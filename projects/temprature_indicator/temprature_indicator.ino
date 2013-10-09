const int led1Pin = 4;
const int led2Pin = 5;
const int led3Pin = 6;

const int sensorPin = A0;
float baseLineTemp = 16.0;
const int tempVariation = 2;

void setup() {
  pinMode(led1Pin, OUTPUT);
  pinMode(led2Pin, OUTPUT);
  pinMode(led3Pin, OUTPUT);
  Serial.begin(9600);
  
  digitalWrite(led1Pin, LOW);
  digitalWrite(led2Pin, LOW);
  digitalWrite(led3Pin, LOW);
}

int previousValue = 0;
void loop() {
  int sensorValue = analogRead(sensorPin);
  printTemperature(sensorValue);
  sensorValue = (sensorValue + previousValue)/2;
  printTemperature(sensorValue);
  
  float temperature = calculateTemperature(sensorValue);
  //Too hot
  if(temperature > baseLineTemp + tempVariation){
    digitalWrite(led1Pin, LOW);
    digitalWrite(led2Pin, LOW);
    digitalWrite(led3Pin, HIGH);
  }else{
    //Too cold
    if(temperature < baseLineTemp - tempVariation){
    digitalWrite(led1Pin, HIGH);
    digitalWrite(led2Pin, LOW);
    digitalWrite(led3Pin, LOW);
    }
    else{
      digitalWrite(led1Pin, LOW);
      digitalWrite(led2Pin, HIGH);
      digitalWrite(led3Pin, LOW);
    }
    previousValue = sensorValue;
  }
  //read new baseline from serial
  Serial.println("Set new baseline temp");
  if (Serial.available() > 0) {
    baseLineTemp = Serial.parseFloat();
    Serial.println(baseLineTemp);
  }
  delay(1000);
}

void printTemperature(int sensorValue){
  Serial.print("Sensor Value: ");
  Serial.print(sensorValue);
  
  Serial.print(", Voltage: ");
  Serial.print((sensorValue/1024.0)*5.0);
  
  Serial.print(", Temperature: ");
  Serial.print(calculateTemperature(sensorValue));
  Serial.print("\n");
}

float calculateTemperature(int sensorValue){
  return ((((sensorValue/1024.0)*5.0) - .5) * 100);
}
