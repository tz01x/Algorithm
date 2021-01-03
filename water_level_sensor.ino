const int trigerPIN = 4; // Trigger Pin of Ultrasonic Sensor
const int echoPin = 2; // Echo Pin of Ultrasonic Sensor


const int blue_light=7;
const int whight_light=8;
const int disco_light=6;
const int buzzer=9;


const long overFlow_POINT=10;//cm
const long lowest_water_level_POINT=23;//cm

void setup(){
   Serial.begin(9600); // Starting Serial Terminal
   // opens serial port, sets data rate to 9600 bps 
   pinMode(blue_light, OUTPUT);
   pinMode(whight_light, OUTPUT);
   pinMode(disco_light, OUTPUT);
   pinMode(buzzer, OUTPUT);
   
}


void loop() {
   long duration, current_Water_level_in_INCHES, current_Water_level_in_CM;
   
   pinMode(trigerPIN, OUTPUT);
   digitalWrite(trigerPIN, LOW);
   delayMicroseconds(2);
   digitalWrite(trigerPIN, HIGH);
   delayMicroseconds(10);
   digitalWrite(trigerPIN, LOW);
   pinMode(echoPin, INPUT);
   duration = pulseIn(echoPin, HIGH);
   
   current_Water_level_in_INCHES = microsecondsToInches(duration);
   current_Water_level_in_CM = microsecondsToCentimeters(duration);
   

   if(current_Water_level_in_CM==0){
    //error 
    digitalWrite(disco_light, HIGH);
    digitalWrite(blue_light, HIGH);
    digitalWrite(whight_light, HIGH);
   }else if(current_Water_level_in_CM<=overFlow_POINT){
    //over flow point 
    tone(buzzer, 10000, 1000);
    digitalWrite(blue_light, LOW);
    digitalWrite(disco_light, LOW);
   digitalWrite(whight_light, HIGH);
  
   }else if(current_Water_level_in_CM>=lowest_water_level_POINT){
    // lowest water level point 
     digitalWrite(disco_light, HIGH);
     digitalWrite(blue_light, LOW);
     digitalWrite(whight_light, LOW);

   }else{
    //stable point 
     digitalWrite(whight_light, LOW);
     digitalWrite(disco_light, LOW);
    digitalWrite(blue_light, HIGH);
   }
   
   Serial.print(current_Water_level_in_INCHES);
   Serial.print("in, ");
   Serial.print(current_Water_level_in_CM);
   Serial.print("cm");
   Serial.println();
   delay(100);
}

long microsecondsToInches(long microseconds) {
   return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds) {
   return microseconds / 29 / 2;
}
