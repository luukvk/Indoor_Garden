/*servo*/
#include <Servo.h>
Servo myservo;
int pos_open = 0;
int pos_closed = 179;

/*moisture sensor*/
const int moist_in = 0;
const int div_Vin = 2;
const int div_gnd = 3;

int moisture; // the raw sensor value
int moist; // the percentage of water in the soil


int SoilMoist(){
 int reading;
 
 pinMode(div_gnd, OUTPUT);
 pinMode(div_Vin, INPUT);
 
 delay(1000);
 
 reading = analogRead(moist_in);
 
 digitalWrite(div_gnd, LOW);
 digitalWrite(div_Vin, HIGH);
 
 delay(1000);
 
 digitalWrite(div_Vin, LOW);
 
 return reading;
}

/*sensor values*/
const int MAX = 100; //the value here should be equal to the value of the sensor when in water
const int MIN = 0; //the value here should be equal to the value of the sensor in the air

/*plant values*/
const int plantmoist = ; // amount of moist needed for the plant
const int plantlight = ; // amount of light needed for the plant


void setup(){
 myservo.attach(9);
 Serial.begin(9600); 
}

void loop(void){
 moisture = SoilMoist();
 moist = (MAX-moisture)/(MAX-MIN)*100 //calculate the percentage of moist
 
 Serial.print("Moist: ");
 //Serial.print(moisture); //raw sensor value for the MAX and MIN
 Serial.print(moist);
 Serial.print("%");
 Serial.println();
  
 /*controling the valve with the servo*/
 if(moist < plantmoist){
   myservo.write(pos_open);
 }
 else{
   myservo.write(pos_closed);
 }
 
 delay(1000);
}
