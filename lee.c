#include <DHT.h>
#include <Adafruit_Sensor.h>
#include <LiquidCrystal.h>
#include <Stepper.h>

const int stepsPerRevolution = 1024;
Stepper myStepper(stepsPerRevolution,11,9,10,8); 
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);
DHT dht(12,DHT22);

void setup()
{
	Serial.begin(9600);
	dht.begin();
	lcd.begin(16, 2);
	myStepper.setSpeed(30);

}

int dh=40;
int dt=24;

void loop()
{
	delay(1000);
	float humi = dht.readHumidity(); //Read Humidity
	float temp = dht.readTemperature(); //Read Temperature
	//const int stepsPerRevolution = 2*humi+5*temp; 
	int angleTemp=0;
	int angleHumi=0;

	angleHumi=(humi-dh)*57;
	dh=humi;
	angleTemp=(temp-dt)*57;
	dt=temp;
	
	Serial.print("Temperature: ");
	Serial.print(temp);
	Serial.print("℃  ");
	Serial.print("Humidity: ");
	Serial.print(humi);
	Serial.print("%  ");
	Serial.print("radian: ");
	Serial.print(stepsPerRevolution);
	Serial.println("°  ");


	lcd.setCursor(0,1); 
	lcd.print("Temp: ");
	lcd.print(temp);
	lcd.print((char)96);
	lcd.print("C");

	lcd.setCursor(8,1);
	lcd.print("Humidity: ");
	lcd.print(humi);
	lcd.print("%");

	lcd.setCursor(16,1);
	lcd.print("radian: ");
	lcd.print(stepsPerRevolution);
	lcd.print((char)96);



	myStepper.step(stepsPerRevolution);
}
