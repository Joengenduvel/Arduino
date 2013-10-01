const int led1Pin = 4;
const int led2Pin = 5;
const int led3Pin = 6;

const int sensorPin = A0;

const float baseLineTemp = 21.0;
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

void loop() {
  int sensorValue = analogRead(sensorPin);
  Serial.print("Sensor Value: ");
  Serial.print(sensorValue);
  
  float voltage = (sensorValue/1024.0)*5.0;
  Serial.print(", Voltage: ");
  Serial.print(voltage);
  
  float temperature = ((voltage - .5) * 100);
  Serial.print(", Temperature: ");
  Serial.print(temperature);
  Serial.print("\n");
  
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
  }
  
  delay(1000);
}
