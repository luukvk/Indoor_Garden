const int moist_in = 0;
const int div_Vin = 2;
const int div_gnd = 3;

const int MAX = 100; //the value here should be equal to the value of the sensor when in water
const int MIN = 0; //the value here should be equal to the value of the sensor in the air

int moisture;

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

void setup(){
 Serial.begin(9600); 
}

void loop(){
 moisture = SoilMoist();
 Serial.print("Moisture: ");
 Serial.print(moisture); //calculate the boundery values (in water/air)
 Serial.print((MAX-moisture)/(MAX-MIN)*100);//calculate the percentage of moist
 Serial.print("%");
 Serial.println();
 delay(1000);
}
