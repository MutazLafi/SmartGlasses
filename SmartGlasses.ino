
#include <Wire.h>
#include <RTClib.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>


#define DEBUG

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define SCREEN_ADDR 0x3C


#define DHTPIN 4
#define DHTTYPE DHT11

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT);

RTC_DS3231 RTC;

const int LightPin = A0;
const int BuzzerPin = 5;

const int TouchPin1 = 6;
const int TouchPin2 = 7;
const int TouchPin3 = 8;
const int TouchPin4 = 9;

const int YAxis = A1;
const int XAxis = A2;

char DaysOfTheWeek[7][12] = { "Sunday", "Monday", "Tuesday", "wednesday", "Thursday", "Friday", "Saturday" };

int TouchState = 0;
bool PrevState1 = false;
bool PrevState2 = false;
bool PrevState3 = false;
bool PrevState4 = false;

#include "classes.h"

GravitySensor Gravity;
LightSensor Light;
TouchSensor Touch;
SoundsControl Sounds;
ModesControl Modes;


void setup() {

#ifdef DEBUG
  Serial.begin(9600);
#endif



  display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDR);
  RTC.begin();
  Gravity.begin();
  Light.begin();
  Touch.begin();
  Sounds.begin();

  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0, 3);

  display.println("HI");
  display.setCursor(0, 34);
  display.println("Mutaz Lafi");
  display.display();
  delay(2000);
  display.clearDisplay();
  display.display();
  display.setCursor(0, 0);
  display.setTextSize(2);
  display.print("Select");
  display.setCursor(0, 17);
  display.print("Mode");
  display.display();
  Serial.print("1");
}

void loop() {
  DateTime now = RTC.now();
  Modes.Modes();

  if (TouchState == 1) {
    display.clearDisplay();
    PrevState2 = false;
    PrevState3 = false;
    PrevState4 = false;

    if (PrevState1 == false) {
      Sounds.ModesNoise(true);
      display.setCursor(0, 0);
      display.setTextSize(3);
      display.print("Time");
      display.display();
      delay(1500);
      Sounds.ModesNoise(false);
      display.clearDisplay();
      display.display();
    }

    display.setCursor(0, 0);
    display.setTextSize(2);
    display.print(DaysOfTheWeek[now.dayOfTheWeek()]);
    display.display();
    display.setCursor(0, 17);
    display.print(now.hour(), DEC);
    display.print(":");
    display.print(now.minute(), DEC);
    display.display();
    display.setTextSize(1);
    display.println(now.second(), DEC);
    display.display();
    display.setCursor(0, 34);
    display.setTextSize(2);
    display.print(now.day(), DEC);
    display.print("/");
    display.print(now.month(), DEC);
    display.print("/");
    display.print(now.year(), DEC);
    display.display();
    delay(1000);
    PrevState1 = true;
  }

  if (TouchState == 2) {
    display.clearDisplay();
    PrevState1 = false;
    PrevState3 = false;
    PrevState4 = false;

    if (PrevState2 == false) {
      display.setCursor(0, 0);
      display.setTextSize(3);
      display.print("Temp");
      display.display();

      Sounds.ModesNoise(true);
      delay(1000);
      Sounds.ModesNoise(false);
      display.clearDisplay();
      display.display();
      PrevState2 = true;
    }
   
    display.setTextSize(2);
    display.setCursor(0, 2);
    display.print("Temp:");
    display.display();
    display.setCursor(0,17);
    display.print(RTC.getTemperature());
    display.print(" C");
    display.display();
  }
  
}
