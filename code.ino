
/**********************************************************************************************  
* Particle Photon - HRXL-MaxSonar-WR -> ANALOG pin 5
* Author: Eric Brunet
* Website: http://www.ericbrunet.ca
* References:
* - https://www.maxbotix.com/tutorials6/032-using-analog-voltage-pin-3.htm
**********************************************************************************************/
const int maxSonarSensor = A2; 
const int band = 1024;

float Vcc, V5mm, maxSonarSensor_mV, Rmm, Rcm;
long bands;

void setup() {
    Serial.begin(115200);
}

void readSensor(){
    Vcc = 3.25; // may vary and should be measured 
    V5mm = ((Vcc / band) * 1000); // convert to mV

    maxSonarSensor_mV = analogRead(maxSonarSensor);
    
    Rmm = ((maxSonarSensor_mV / V5mm) * 5);
    Rcm = (Rmm / 10); // conver to cm
}

void printRange(){
    Serial.print(maxSonarSensor);
    Serial.print(" Vcc=");
    Serial.print(Vcc);
    Serial.print(" V5mm=");
    Serial.print(V5mm);
    Serial.print(" maxSonarSensor_mV=");
    Serial.print(maxSonarSensor_mV);
    Serial.print(" Rmm=");
    Serial.print(Rmm);
    Serial.print(" Rcm=");
    Serial.println(Rcm); 
}

void loop() {
    
    readSensor();
    printRange();
    
    delay(2000);
}
