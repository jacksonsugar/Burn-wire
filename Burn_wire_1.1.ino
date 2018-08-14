//Burn Wire 1.1 -- Sugar //
#include <Wire.h>
#include "RTClib.h"
#include "LowPower.h"

const int BURN = 2;
const int STROBE = 3;
const int IND = 13;
unsigned long start;
unsigned long burn;
int i;

RTC_DS3231 rtc;

//////////////////////////////////////////////////////////////////////////////////////
//Set time to begin burn cycle
int days = 0;
int h = 0;
int m = 2;
int s = 0;
//Set length of burn cycle before strobe flash (in seconds)
const unsigned long burnTime = 0;  //Input time of wire burning before strobe (1200 recommended)
//////////////////////////////////////////////////////////////////////////////////////
const long deploy = (days * 86400)+ (h * 3600) + (60 * m) + s;


void setup () {

//Set outputs
pinMode(BURN, OUTPUT);
pinMode(STROBE, OUTPUT);
pinMode(IND, OUTPUT);
digitalWrite(BURN, LOW);
digitalWrite(STROBE, LOW);
digitalWrite(IND, LOW);

  while (!Serial) {
    delay(100);  // for Leonardo/Micro/Zero
  }
  
  Serial.begin(9600);

  if (! rtc.begin()) {
    Serial.println("RTC is NOT running!");
    while (1);
  }

  //Set new time based on computer clock
  rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  DateTime now = rtc.now();
  start = now.unixtime();
  burn = start + deploy;
  //Print clock reading + burn time
  Serial.print("Start time:  ");
  Serial.println(start);
  Serial.print("Burn time:   ");
  Serial.println(burn);
  delay(2000);

  for (int j = 1; j <= 3; j++) {
        digitalWrite(STROBE, HIGH);
        delay(500);
        digitalWrite(STROBE, LOW);
        delay(500);
        Serial.print("flash ");
        Serial.println(j);
  }
  Serial.println();
}

void loop () {
  
DateTime now = rtc.now();

if (now.unixtime() <= burn) {
    Serial.print(now.month(), DEC);
    Serial.print('/');
    Serial.print(now.day(), DEC);
    Serial.print('/');
    Serial.print(now.year(), DEC);
    Serial.print("         ");
    Serial.print(now.hour(), DEC);
    Serial.print(':');
    Serial.print(now.minute(), DEC);
    Serial.print(':');
    Serial.print(now.second(), DEC);
    Serial.println();
    Serial.print("Start Unix Time:   ");
    Serial.println(start);
    Serial.print("Burn Time:         ");
    Serial.println(burn);
    Serial.print("Current Unix Time: ");
    Serial.println(now.unixtime());
    Serial.println();
    digitalWrite(BURN, LOW);
    digitalWrite(STROBE, LOW);
    delay(100);
    
    for (int i = 1; i <= 15; i++){
      LowPower.powerDown(SLEEP_8S, ADC_OFF, BOD_OFF);
      digitalWrite(IND, HIGH);
      delay(50);
      digitalWrite(IND, LOW);
    }

}
    else {
      if(now.unixtime() <= burn + burnTime) {
//        Serial.println("Burn = 1");
        digitalWrite(BURN, HIGH);
          for (int i = 1; i <= 15; i++){
            LowPower.powerDown(SLEEP_8S, ADC_OFF, BOD_OFF);
    }
    
      }
      else {
        digitalWrite(BURN, HIGH);
        digitalWrite(STROBE, HIGH);
        delay(random(100, 500));
        digitalWrite(STROBE, LOW);
        LowPower.powerDown(SLEEP_2S, ADC_OFF, BOD_OFF);
        digitalWrite(IND, HIGH);
        delay(50);
        digitalWrite(IND, LOW);
      }
    }
}

