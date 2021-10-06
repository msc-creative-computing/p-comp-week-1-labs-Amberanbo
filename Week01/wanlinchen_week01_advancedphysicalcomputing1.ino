// C++ code
//
int switchState = 0;
const int sensorPin = A0;

const float baselineTemp = 20.0;

void setup()
{
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10,INPUT);
}

void loop()
{ 
  switchState=digitalRead(10); //switch
  
  //read temperature sensor value
  int sensorVal = analogRead(sensorPin);
  Serial.print("Sensor Value: ");
  Serial.print(sensorVal);
  //convert sensor date to voltage
  float voltage = (sensorVal/1024.0)*5.0; 
  Serial.print(" ,volts: ");
  Serial.print(voltage);
  Serial.print(" ,degree C: ");
  //convert the voltage to temperature in degrees
  float temperature = (voltage-0.5)*100;
  Serial.println(temperature); 
  
  if (switchState==HIGH){
    if (temperature < baselineTemp){
      digitalWrite(LED_BUILTIN,HIGH);
      delay(1000); // Wait for 1000 millisecond(s)
      digitalWrite(LED_BUILTIN,LOW);
      delay(1000); // Wait for 1000 millisecond(s)
      digitalWrite(12, LOW);
      digitalWrite(11, LOW);
    }
    
    
    else if(temperature >= baselineTemp && 
            temperature < baselineTemp+20){
      digitalWrite(LED_BUILTIN, LOW);
      digitalWrite(12, HIGH);
      delay(1000); // Wait for 1000 millisecond(s)
      digitalWrite(12, LOW);
      delay(1000); // Wait for 1000 millisecond(s)
      digitalWrite(11, LOW);
    }
    
    
    else if(temperature >= baselineTemp+20){
      digitalWrite(LED_BUILTIN,LOW);
      digitalWrite(12, LOW);
      digitalWrite(11, HIGH);
      delay(1000); // Wait for 1000 millisecond(s)
       digitalWrite(11, LOW);
      delay(1000); // Wait for 1000 millisecond(s)
    }
  }
  
  
  else{
    digitalWrite(LED_BUILTIN, LOW);
    digitalWrite(12, LOW);
    digitalWrite(11, LOW);
  }
}