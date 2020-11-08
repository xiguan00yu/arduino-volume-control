#include "DigiKeyboard.h"

#define KEY_VOLUME_UP 128
#define KEY_VOLUME_DOWN 129

#define REVERSED false //if your controller is reversed change it to true

#define MAX_VOLUME_NUM 16

int val = 0;
int previousval = 0;
int val2 = 0;

void setup()
{
  DigiKeyboard.delay(100);

  for (int a = 0; a <= MAX_VOLUME_NUM; a++)
  {
    DigiKeyboard.sendKeyStroke(KEY_VOLUME_DOWN); //set the volume to 0
    delay(2);
  }
}

void loop()
{
  val = analogRead(A1);
  val = map(val, 0, 1023, 0, MAX_VOLUME_NUM);
  if (REVERSED)
  {
    val = MAX_VOLUME_NUM - val;
  }
  if (abs(val - previousval) >= 1)
  {
    previousval = val;
    while (val2 < val)
    {
      DigiKeyboard.sendKeyStroke(KEY_VOLUME_UP);
      val2++;
      delay(2);
    }
    while (val2 > val)
    {
      DigiKeyboard.sendKeyStroke(KEY_VOLUME_DOWN);
      val2--;
      delay(2);
    }
  }
  delay(250);
}
