//CODE FOR ESP32 MODULE:
#include<WiFi.h>
#include<WiFiCLient.h>
#include<BlynkSimpleEsp32.h>

char auth[]="FCUbeV1HqGG9PpQEuO5oCPgUWlb_g1Ku";
char ssid[]="iPhone";
char pass[]="12345678901";
long value1,value2,value3,value4,value5,value6,value7,value8,value9,value10;
int 
pin1=5,
pin2=18,
pin3=19,
pin4=21,
pin5=22,
pin6=23,
pin7=13,
pin8=12,
pin9=14,
pin10=27,
pin11=26,
pin12=25;
BLYNK_WRITE(V0)
{
  value1=param.asInt();
  digitalWrite(pin1,value1);
}
BLYNK_WRITE(V1)
{
  value2=param.asInt();
  digitalWrite(pin2,value2);
}
BLYNK_WRITE(V2)
{
  value3=param.asInt();
  digitalWrite(pin3,value3);
}
BLYNK_WRITE(V3)
{
  value4=param.asInt();
  digitalWrite(pin4,value4);
}
BLYNK_WRITE(V4)
{
  value5=param.asInt();
  digitalWrite(pin5,value5);
}
BLYNK_WRITE(V5)
{
  value6=param.asInt();
  digitalWrite(pin6,value6);
}
BLYNK_WRITE(V6)
{
  value7=param.asInt();
  digitalWrite(pin7,value7);
}
BLYNK_WRITE(V7)
{
  value8=param.asInt();
  digitalWrite(pin8,value8);
}
BLYNK_WRITE(V9)
{
  value10=param.asInt();
  digitalWrite(pin10,value10);
}
void all_light_ON()
{
  digitalWrite(pin1,HIGH); Blynk.virtualWrite(V0, HIGH); delay(100);
  digitalWrite(pin2,HIGH); Blynk.virtualWrite(V1, HIGH); delay(100);
  digitalWrite(pin3,HIGH); Blynk.virtualWrite(V2, HIGH); delay(100);
  digitalWrite(pin4,HIGH); Blynk.virtualWrite(V3, HIGH); delay(100);
}
void all_light_off()
{
  digitalWrite(pin1,LOW); Blynk.virtualWrite(V0,LOW); delay(100);
  digitalWrite(pin2,LOW); Blynk.virtualWrite(V1,LOW); delay(100);
  digitalWrite(pin3,LOW); Blynk.virtualWrite(V2,LOW); delay(100);
  digitalWrite(pin4,LOW); Blynk.virtualWrite(V3,LOW); delay(100);
}
void all_fan_ON()
{
  digitalWrite(pin5,HIGH); Blynk.virtualWrite(V4,HIGH); delay(100);
  digitalWrite(pin6,HIGH); Blynk.virtualWrite(V5,HIGH); delay(100);
  digitalWrite(pin7,HIGH); Blynk.virtualWrite(V6,HIGH); delay(100);
  digitalWrite(pin8,HIGH); Blynk.virtualWrite(V7,HIGH); delay(100);
}
void all_fan_off()
{
  digitalWrite(pin5,LOW); Blynk.virtualWrite(V4,LOW); delay(100);
  digitalWrite(pin6,LOW); Blynk.virtualWrite(V5,LOW); delay(100);
  digitalWrite(pin7,LOW); Blynk.virtualWrite(V6,LOW); delay(100);
  digitalWrite(pin8,LOW); Blynk.virtualWrite(V7,LOW); delay(100);
}
void temp_sensor()
{
  if(digitalRead(pin12)==HIGH)
  {
    all_fan_ON();
  }
  else
  {
    all_fan_off();
  }
}
void LDR_sensor()
{
  if(digitalRead(pin11)==HIGH)
  {
    all_light_ON();
  }
  else
  {
    all_light_off();
  }
}
void automatic()
{
  if(value10==HIGH)
  {
    LDR_sensor();
    temp_sensor();
  }
  else
  {
    Blynk.run();
  }
}
void setup()
{
  pinMode(pin1,OUTPUT);
  pinMode(pin2,OUTPUT);
  pinMode(pin3,OUTPUT);
  pinMode(pin4,OUTPUT);
  pinMode(pin5,OUTPUT);
  pinMode(pin6,OUTPUT);
  pinMode(pin7,OUTPUT);
  pinMode(pin8,OUTPUT);
  pinMode(pin9,OUTPUT);
  pinMode(pin10,OUTPUT);
  pinMode(pin11,INPUT);
  pinMode(pin12,INPUT);

  Blynk.begin(auth,ssid,pass,"Blynk.cloud",80);
}
void loop()
{
  automatic();
}
