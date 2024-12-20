#include <DHT.h>
#include <DHT_U.h>
//#include <ArduinoJson.h>
#define Type DHT11
#include <Servo.h>

//DHT sensor
//gnd-gnd
//data-
//vcc-5v
int sensePin = 2;
DHT HT(sensePin,Type);
float humidity;
float tempC;

float lowHumidity = 20;
float highHumidity = 60;

//diodes
int greenD = 4;
int redD = 7;
int blueD = 8;

//servo motor
//brown cable-grnd
//red- power 5V
//yellow/orange- data
int pos = 0;
Servo servo_9;

unsigned long lastSensorReadTime = 0;
//moisture sensor
//vcc -analogRead pin power
//gnd-gnd
//sig -analodRead pin data
#define analogPin A0
#define digitalPin 3
#define vccPin 12
unsigned long time = 0;

int lowMoisture;
int highMoisture;

int timeDelay;


void setup() {
  Serial.begin(9600);
  delay(500);
  HT.begin();
  delay(500);

  servo_9.attach(9, 500, 2500);

  //test if everything is all right
  pinMode(greenD, OUTPUT);
  pinMode(redD, OUTPUT);
  pinMode(blueD, OUTPUT);

  delay(500);
  moveServo(80,true);
  delay(500);

  digitalWrite(greenD, HIGH);
  digitalWrite(redD, HIGH);
  digitalWrite(blueD, HIGH);
  delay(1000);
  digitalWrite(greenD, LOW);
  digitalWrite(redD, LOW);
  digitalWrite(blueD, LOW);

  //test  moisture
  pinMode(analogPin, INPUT);
  pinMode(digitalPin, INPUT);
  pinMode(vccPin, OUTPUT);
  digitalWrite(vccPin, LOW);

  Serial.print("test");
}

void loop() {
  humidity = HT.readHumidity();
  tempC = HT.readTemperature();

  Serial.print("Temperature:");
  Serial.print(tempC);
  Serial.println("C");
  Serial.print("Humidity:");
  Serial.print(humidity);
  Serial.println("");
  
  digitalWrite(greenD, LOW);
  digitalWrite(redD, LOW);
  digitalWrite(blueD, LOW);

  if (humidity > highHumidity)
  {
    digitalWrite(redD,HIGH);
  }
  else if (humidity< lowHumidity)
  {
    digitalWrite(blueD, HIGH);
    //watering flowers
    if (millis() >= 86400000UL) { // 24 hours in milliseconds
    moveServo(180, true);
    resetMillis(); // Reset the millis counter
  }

  }
  else
  {
    digitalWrite(greenD, HIGH);
  }

  Serial.print("Moisture: ");

  moistureTest();

  delay(1000);

}

void moveServo(int position , bool way)
{
  if (way == true)
  {
    for (pos = 0; pos <= position; pos += 1) {
      // tell servo to go to position in variable 'pos'
      servo_9.write(pos);
      // wait 15 ms for servo to reach the position
      delay(15); // Wait for 15 millisecond(s)
    }
    for (position ; position >= 0;position-= 1) {
      // tell servo to go to position in variable 'pos'
      servo_9.write(pos);
      // wait 15 ms for servo to reach the position
      delay(15); // Wait for 15 millisecond(s)
    }
  }
  else if (way == false)
  {
    for (position; position >= 0; pos -= 1) {
      // tell servo to go to position in variable 'pos'
      servo_9.write(pos);
      // wait 15 ms for servo to reach the position
      delay(15); // Wait for 15 millisecond(s)
    }
  }
}


void moistureTest()
{
  if (millis() - time > 3000) 
  {
    digitalWrite(vccPin, HIGH);
    delay(100);
    
    int analog = analogRead(analogPin);
    bool digit = digitalRead(digitalPin);
    
    Serial.print("Analogovy vstup: ");
    Serial.print(analog);
    if (digit == HIGH) 
    {
      Serial.print(" | Detekovano prekroceni hranice!");
    }
    
    Serial.println();
    
    digitalWrite(vccPin, LOW);
    
    time = millis();
  }
  
}

void resetMillis() {
  asm volatile ("jmp 0"); // Resets the Arduino by jumping to the start of the program
}