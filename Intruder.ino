#include <SoftwareSerial.h>


SoftwareSerial mySerial(9, 10);
#define trigpin 12
#define echopin 11
#define buzzer 8
int sms_count=0;
void setup()
{
pinMode(trigpin,OUTPUT);
pinMode(echopin,INPUT);
pinMode(buzzer,OUTPUT);
pinMode(push_switch,INPUT); // configuring pin 6 as Input
mySerial.begin(9600);
}

void loop()
{
long duration,distance;
digitalWrite(trigpin,LOW);
delayMicroseconds(20);
digitalWrite(trigpin,HIGH);
delayMicroseconds(20);
digitalWrite(trigpin,LOW);
duration=pulseIn(echopin,HIGH);
distance=(duration/2)/29.1;
if(distance<60)
{
digitalWrite(buzzer,HIGH);
SendTextMessage();
}

else
{
digitalWrite(buzzer,LOW);
}
delay(500);
}


void SendTextMessage()
{
mySerial.println("AT+CMGF=1"); 
mySerial.println("AT+CMGS=\"+91956xxxxxxx\"\r");
delay(1000);
mySerial.println("Bhai ghar me koi haiii!");
delay(200);
mySerial.println((char)26);

delay(1000);
sms_count++;
}
