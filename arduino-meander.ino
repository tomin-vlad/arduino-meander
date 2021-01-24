/* Meander on the LED without Delay,
   by Vladislav A. Tomin
*/

#include <Arduino.h>

unsigned long timerLow, timerHigh = 0;
const unsigned int intervalLow = 5000;
const unsigned int intervalHigh = 3000;

void setup() {
   pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
   if (millis() - timerLow > intervalLow) {
      digitalWrite(LED_BUILTIN, HIGH);
      if (millis() - timerHigh > intervalLow + intervalHigh) {
         timerHigh = timerLow = millis();
         digitalWrite(LED_BUILTIN, LOW);
      }
   }
}
