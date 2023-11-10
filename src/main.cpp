#include <Arduino.h>
#include <TFT_eSPI.h>

#define TFT_BACKLIGHT     4
#define TFT_CS            5
#define BUTTON_1          0
#define BUTTON_2          35

TFT_eSPI tft;
unsigned int count = 0;

void setup() {
  Serial.begin(115200);
  delay(2000);
  Serial.println("Alive and kicking!");

  pinMode(TFT_BACKLIGHT, OUTPUT);
  pinMode(TFT_CS, OUTPUT);

  tft.init();
  tft.setRotation(1);
  tft.fillScreen(TFT_BLACK);
  tft.setTextFont(7);
  tft.setTextDatum(MC_DATUM);
  tft.setTextColor(TFT_WHITE, TFT_BLACK);
  digitalWrite(TFT_BACKLIGHT, HIGH);
  digitalWrite(TFT_CS, HIGH);
}

void loop() {
  Serial.println(count++);

  tft.fillScreen(TFT_BLACK);
  tft.drawString(String(count), tft.width()/2, tft.height()/2);

  delay(1000);
}

