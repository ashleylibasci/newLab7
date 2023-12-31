/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "/Users/ashleylibasci/IoTFolderLabs/newLab7/src/newLab7.ino"
#include "env.h"
#include <blynk.h>
#include "oled-wing-adafruit.h"

void setup();
void loop();
#line 5 "/Users/ashleylibasci/IoTFolderLabs/newLab7/src/newLab7.ino"
SYSTEM_THREAD(ENABLED);

OledWingAdafruit display;

void setup()
{
  Blynk.begin(BLYNK_AUTH_TOKEN);
  pinMode(A4, INPUT);

  display.setup();
  display.clearDisplay();
  display.display(); // cause the display to be updated
}

void loop()
{
  Blynk.run();

  uint64_t reading = analogRead(A4);
  double voltage = (reading * 3.3) / 4095.0;
  double celsius = (voltage - 0.5) * 100;

  double farenheit = (celsius * 9 / 5) + 32;

  display.loop();
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.println(celsius);
  display.setCursor(0, 15);
  display.println(farenheit);
  display.display();

  Blynk.virtualWrite(V0, celsius);
  Blynk.virtualWrite(V2, farenheit);

  if (display.pressedA())
  {
    Blynk.logEvent("oledButtonPressed");
    display.loop();
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(0, 0);
    display.println(celsius);
    display.setCursor(0, 15);
    display.println("button pressed");
    display.display();
    delay(3000);
  }
}
