const int echoPin = 2;
const int trigPin = 3;


long duration;
int distance; 

void setup() {
  pinMode(trigPin, OUTPUT);      // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT);       // Sets the echoPin as an INPUT
  Serial.begin(38400);            // Serial Communication is starting with 9600 of baudrate speed

}
void loop() {

  while(getDistance() > 25){ }

  int startTime = millis(); 
  
  while(getDistance() <25){ 
   int newTime = millis();        //record the current time

  if (newTime - startTime > 3000){ 
    Serial.write("1");            // send message to screen to open
    Serial.println('\n');
    break;                        // get out so only send message once
  }
  }
  
  
  while(getDistance() < 25){ }
}

int getDistance(){                // defining the function to calculate the distance
   
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
 
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;         // Calculating the distance
  
  return distance;
}
