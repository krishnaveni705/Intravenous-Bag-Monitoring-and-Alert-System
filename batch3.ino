#include <SoftwareSerial.h>
#include <LiquidCrystal.h>
#include <Servo.h>
#define SERVO_PIN A2
const int bz = A3;
Servo servoMotor;
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);
const int trigPin1 = A5;
const int echoPin1 = A4;
long duration, distance,levelSensor;
void setup() {
  pinMode(bz,OUTPUT);
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  servoMotor.attach(SERVO_PIN);
  servoMotor.write(0);
  lcd.begin(16, 2); // Set up the LCD's number of columns and rows
  lcd.setCursor(0,0);
  lcd.print("WELCOME TO");
  lcd.setCursor(0,1);
  lcd.print("BAG MONITORING");
  delay(2000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("AND ALERT ");
  lcd.setCursor(0,1);
  lcd.print("SYSTEM");
  digitalWrite(bz,LOW);
  delay(2000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("ULTRASONIC: ");
  lcd.setCursor(0,1);
  lcd.print("DISTANCE:");
}

void loop() {
  SonarSensor(trigPin1, echoPin1);
  levelSensor = distance;
  delay(200);  
  lcd.setCursor(8,1);
  lcd.print(levelSensor);
  lcd.print("   ");
  if(levelSensor<10)
  {
    servoMotor.write(90);
    digitalWrite(bz,HIGH);
  }
  else
  {
    servoMotor.write(0);
    digitalWrite(bz,LOW);
  }
  }
   void SonarSensor(int trigPin, int echoPin)
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) / 29.1;
}
