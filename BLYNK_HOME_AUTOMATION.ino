#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME680.h>
#include <Adafruit_VEML7700.h>
#define BLYNK_TEMPLATE_ID "TMPL5Ijl4UwrI"
#define BLYNK_TEMPLATE_NAME "Home Automation"
#define BLYNK_AUTH_TOKEN "cB1GDjC80u3kRJM6rgx67KgTk3ze-B8q"

#define BLYNK_PRINT Serial
#define relay1 40
#define relay2 41
#define relay3 21
#define relay4 47
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
char ssid[] = "Jasin";
char pass[] = "1223334444";
int global_val;
 float temp,humi,press,gas,lux;
#define SDA_PIN 1
#define SCL_PIN 2
Adafruit_BME680 bme;
Adafruit_VEML7700 veml;

BlynkTimer timer;
BLYNK_WRITE(V0) {
  // Set incoming value from pin V0 to a variable
  int value = param.asInt();
  digitalWrite(relay1, value);
}
BLYNK_WRITE(V1) {
  // Set incoming value from pin V0 to a variable
  int value = param.asInt();
  digitalWrite(relay2, value);
}
BLYNK_WRITE(V2) {
  // Set incoming value from pin V0 to a variable
  global_val = param.asInt();
  digitalWrite(relay3, global_val);
}
BLYNK_WRITE(V3) {
  // Set incoming value from pin V0 to a variable
  int value = param.asInt();
  digitalWrite(relay4, value);
}
void myTimerEvent() {
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
  Blynk.virtualWrite(V4,temp);
  Blynk.virtualWrite(V5,humi);
  Blynk.virtualWrite(V6,press);
  Blynk.virtualWrite(V7,gas);
  Blynk.virtualWrite(V8,lux);
}

void setup() {
  Serial.begin(115200);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  timer.setInterval(1000L, myTimerEvent);
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(relay3, OUTPUT);
  pinMode(relay4, OUTPUT);
  Serial.begin(115200);
Wire.begin(SDA_PIN, SCL_PIN);
Serial.println("BME688 Test Starting...");

if (!bme.begin(0x76)) {
    Serial.println("Could not find BME688! Check wiring!");
    while (1);
  }

  // Set oversampling and filter settings
  bme.setTemperatureOversampling(BME680_OS_8X);
  bme.setHumidityOversampling(BME680_OS_2X);
  bme.setPressureOversampling(BME680_OS_4X);
  bme.setIIRFilterSize(BME680_FILTER_SIZE_3);
  bme.setGasHeater(320, 150); 

Serial.println("VEML7700 Test Starting...");

if (!veml.begin()) {
    Serial.println("VEML7700 not found! Check wiring!");
    while (1);
}

veml.setGain(VEML7700_GAIN_1);
veml.setIntegrationTime(VEML7700_IT_100MS);
}

void loop() {
  Blynk.run();
  timer.run();
  if (!bme.performReading()) {
    Serial.println("Failed to get reading!");
    return;
  }

  temp = bme.temperature;
  humi = bme.humidity;
  press = bme.pressure/100.0;
  gas = bme.gas_resistance/1000.0;
  lux = veml.readLux();
  if (lux < 65 && global_val == 1){
    Blynk.virtualWrite(V2,HIGH);
    digitalWrite(relay3,HIGH);
  }
  else if(lux > 65 && global_val == 1){
    digitalWrite(relay3,LOW);
  }
  if(temp > 31){
    Blynk.logEvent("temperature");
  }
}
