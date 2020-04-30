int trigPin = 8; 
int echoPin = 9; 

long duration;
//long u;
long abstand;
long oldabstand = 80; 
int say = 0;
const unsigned long timeout = 10000;

void setup(){
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin,INPUT); 
  Serial.begin(9600); 
}
void loop()
{
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);   
  duration = pulseIn(echoPin, HIGH, timeout); 
  abstand = duration /29.1/2;
              
  if(abstand > 80){ // Maximalentfernung
    abstand = 80;
    oldabstand = abstand;
  }
  
  //Bei QuerRichtung
/*  if(abstand < 23 && oldabstand > 22){
    say++;
    oldabstand = abstand;
    }
*/

  //Bei SchritteRichtung
  if(abstand < 25 && oldabstand > 24){
    say++;
    oldabstand = abstand;
  }
  
  oldabstand = abstand;
    
  Serial.print(abstand);
  Serial.print(" cm ");
  Serial.print("           ");   
  Serial.print(say); 
  Serial.println(" Schritte ");
  delay(100);   
}
