#include <LiquidCrystal_I2C.h>
#include <Streaming.h>
#include <Wire.h>
#include <OneWire.h>
#include <DallasTemperature.h>

#define RELAY_PIN 5
#define ONE_WIRE_BUS 2

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

LiquidCrystal_I2C lcd(0x27, 16, 2);

float tempc;
void setup() {

  Serial.begin(9600);
  // findI2CAddress();
  lcd.begin();
  lcd.backlight();
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, HIGH);
  sensors.begin();
}

void loop() {
  tempc = getTemp();
  lcd.setCursor(0, 0), lcd << F("Temp=       C");
  lcd.setCursor(6, 0), lcd << tempc;
  if (tempc > 36) {
    relayOn();
    lcd.setCursor(0, 1), lcd << F("FAN ON ");
  }
  if (tempc < 36) {
    relayOff();
    lcd.setCursor(0, 1), lcd.print("FAN OFF");
  }
  delay(1000);
}

float getTemp() {
  sensors.requestTemperatures();
  return sensors.getTempCByIndex(0);
}

void relayOn() {
  digitalWrite(RELAY_PIN, LOW);
}

void relayOff() {
  digitalWrite(RELAY_PIN, HIGH);
}

void lcdTest() {
  lcd.setCursor(0, 0), lcd << F("      Hello     ");
  lcd.setCursor(0, 1), lcd << F("     WORLD!!!   ");
}


void findI2CAddress() {

  byte error, address;
  int nDevices;

  Serial.println("Scanning...");

  nDevices = 0;
  for (address = 1; address < 127; address++) {
    // The i2c_scanner uses the return value of
    // the Write.endTransmisstion to see if
    // a device did acknowledge to the address.
    Wire.beginTransmission(address);
    error = Wire.endTransmission();

    if (error == 0) {
      Serial.print("I2C device found at address 0x");
      if (address < 16)
        Serial.print("0");
      Serial.print(address, HEX);
      Serial.println("  !");

      nDevices++;
    } else if (error == 4) {
      Serial.print("Unknown error at address 0x");
      if (address < 16)
        Serial.print("0");
      Serial.println(address, HEX);
    }
  }
  if (nDevices == 0)
    Serial.println("No I2C devices found\n");
  else
    Serial.println("done\n");

  while (true)
    ;
}
