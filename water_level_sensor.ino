const int trigerPIN = 4; // Trigger Pin of Ultrasonic Sensor
const int echoPin = 2; // Echo Pin of Ultrasonic Sensor

const long overFlow_POINT=10;//cm
const long lowest_water_level_POINT=23;//cm

const int blue_light=7;
const int white_light=8;
const int flickering_light=6;
const int buzzer=9;
long last_counter = -1;
const int MAX_SIZE = 8;
long arr[MAX_SIZE] = { 0 };//to store last few sensor

int font = -1, back = -1;

void push (long x)
{

  if (back == -1)
    {
      font++;
      back++;
      arr[back] = x;

    }
  else
    {
      if (((back + 1) % MAX_SIZE) == font)
  {
    font = (font + 1) % MAX_SIZE;
    back = (back + 1) % MAX_SIZE;
    arr[back] = x;
  }else{
      
    back = (back + 1) % MAX_SIZE;
    arr[back] = x;
  }

    }
  //printf ("push -> : %d\n ", arr[back]);
}


void setup(){
   Serial.begin(9600); // Starting Serial Terminal
   // opens serial port, sets data rate to 9600 bps 
   
   pinMode(blue_light, OUTPUT);
   pinMode(white_light, OUTPUT);
   pinMode(flickering_light, OUTPUT);
   pinMode(buzzer, OUTPUT);
   
}


void loop() {
   long duration, current_Water_level_in_INCHES, current_Water_level_in_CM;
   
   pinMode(trigerPIN, OUTPUT);
   digitalWrite(trigerPIN, LOW);
   delayMicroseconds(2);
   digitalWrite(trigerPIN, HIGH);//turn on the trinsmitter 
   delayMicroseconds(10);
   digitalWrite(trigerPIN, LOW);//turn off the trinsmitter 
   pinMode(echoPin, INPUT);//turn on the receiver  
   duration = pulseIn(echoPin, HIGH);
   
   current_Water_level_in_INCHES = microsecondsToInches(duration);
   current_Water_level_in_CM = microsecondsToCentimeters(duration);
   
   current_Water_level_in_CM=Check_for_error(current_Water_level_in_CM);

   
   if(current_Water_level_in_CM==0){
    //error 
    digitalWrite(flickering_light, HIGH);
    digitalWrite(blue_light, HIGH);
    digitalWrite(white_light, HIGH);
   }else if(current_Water_level_in_CM<=overFlow_POINT){
    //over flow point 
    tone(buzzer, 10000, 1000);//pin , frequency , duration in ms 
    digitalWrite(blue_light, LOW);
    digitalWrite(flickering_light, LOW);
   digitalWrite(white_light, HIGH);
  
   }else if(current_Water_level_in_CM>=lowest_water_level_POINT){
    // lowest water level point 
     digitalWrite(flickering_light, HIGH);
     digitalWrite(blue_light, LOW);
     digitalWrite(white_light, LOW);

   }else{
    //stable point 
     digitalWrite(white_light, LOW);
     digitalWrite(flickering_light, LOW);
    digitalWrite(blue_light, HIGH);
   }
   
   Serial.print(current_Water_level_in_INCHES);
   Serial.print("in, ");
   Serial.print(current_Water_level_in_CM);
   Serial.print("cm");
   Serial.println();
   delay(100);
}
float get_probability (long item)
{

  //printf("item -> r : %d\n , ",item);
  int tfont = font;
  int tback = back;
  int counter = 0;
  int n = 1;

    for(int i=font;i!=back;i=(i+1)%MAX_SIZE){


      if (arr[i] == item)
  {
    counter += 1;

  }
      
      n += 1;

        
    }
    
    
     // printf("counter : %d ,n: %d \n",counter,n);

  return ((float)counter /(float) n) * 100.0;

}
long Check_for_error(long curr_water_lv_in_cm){
  
        
      push (curr_water_lv_in_cm);
      if (last_counter == -1)
  {
    last_counter =curr_water_lv_in_cm;

  }
      long rate_of_Change = (long) (abs (last_counter -curr_water_lv_in_cm));
      //printf("rate_of_Change %d \n",rate_of_Change);

      if (rate_of_Change >= 1 && rate_of_Change <= 3)
  {

    last_counter =
      last_counter +
      (long) ((sinh (curr_water_lv_in_cm- last_counter)) * rate_of_Change);

  }
      else
  {

    float prob = get_probability (curr_water_lv_in_cm);
    
    if (prob > 30)
      {
        last_counter = curr_water_lv_in_cm;
     
      }
  }
  return last_counter;
  
}
long microsecondsToInches(long microseconds) {
   return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds) {
   return microseconds / 29 / 2;
  // 29 micSec/cm 
}
