
// Fill-in information from your Blynk Template here
#define BLYNK_TEMPLATE_ID "TMPLC8eLTwRU"
#define BLYNK_DEVICE_NAME "final"

#define BLYNK_FIRMWARE_VERSION        "0.1.0"

// #define BLYNK_PRINT Serial
//#define BLYNK_DEBUG

#define APP_DEBUG

// Uncomment your board, or configure a custom board in Settings.h
//#define USE_SPARKFUN_BLYNK_BOARD
//#define USE_NODE_MCU_BOARD
//#define USE_WITTY_CLOUD_BOARD
//#define USE_WEMOS_D1_MINI

// #include "BlynkEdgent.h"
//code is written by Md iqbal
//website:-techiqbal.com
//Youtube:-Techiqbal
#define BLYNK_PRINT Serial
#include <OneWire.h>
#include <SPI.h>
#include <BlynkSimpleEsp8266.h>
#include <DHT.h>
#include <DallasTemperature.h>
#define ONE_WIRE_BUS D2
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
char auth[] ="DuNwdmBw1imq1PPpXAN9D8sYnYjoS-87";
char ssid[] = "ENGINEERS CHOICE";
char pass[] = "nadeem148";
//code written by Md iqbal
//website:-techiqbal.com
//Youtube:-Techiqbal
#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
SimpleTimer timer;
void sendSensor()
{
float h = dht.readHumidity();
float t = dht.readTemperature();

if (isnan(h) || isnan(t)) {
Serial.println("Failed to read from DHT sensor!");
return;
}

Blynk.virtualWrite(V5, h); //V5 is for Humidity
Blynk.virtualWrite(V6, t); //V6 is for Temperature
}
void setup()
{
Serial.begin(9600);
dht.begin();

timer.setInterval(1000L, sendSensor);
Blynk.begin(auth, ssid, pass);
sensors.begin();
}
int sensor=0;
int output=0;
void sendTemps()
{
sensor=analogRead(A0);
output=(145-map(sensor,0,1023,0,100)); //in place 145 there is 100(it change with the change in sensor)
delay(1000);
sensors.requestTemperatures();
float temp = sensors.getTempCByIndex(0);
Serial.println(temp);
Serial.print("moisture = ");
Serial.print(output);
Serial.println("%");
Blynk.virtualWrite(V1, temp);
Blynk.virtualWrite(V2,output);
delay(1000);
}
void loop()
{
Blynk.run();
timer.run();
sendTemps();
}
//code written by Md iqbal
//website:-techiqbal.com
//Youtube:-Techiqbal

