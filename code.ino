
/**********************************************************************************************  
* Particle Photon - HRXL-MaxSonar-WR -> ANALOG pin 5
* Author: Eric Brunet
* Website: http://www.ericbrunet.ca
* References:
* - https://www.maxbotix.com/tutorials6/032-using-analog-voltage-pin-3.htm
**********************************************************************************************/
const int sourceVoltage = A0; 
const int maxSonarSensor = A1; 
const int band = 1024;

float Vcc, V5mm, maxSonarSensor_mV, Rmm, Rcm;
long bands;

void setup() {
    Serial.begin(115200);
}

void readSensor(){
    Vcc = analogRead(sourceVoltage);    
    V5mm = (Vcc / band);

    maxSonarSensor_mV = analogRead(maxSonarSensor);
    
    Rmm = ((maxSonarSensor_mV / V5mm) * 5);
    Rcm = (Rmm / 10); // convert to cm
}

void printRange(){
    Serial.print(maxSonarSensor);
    Serial.printf(" Vcc=%.2f", Vcc);
    Serial.printf(" V5mm=%.4f", V5mm);
    Serial.printf(" sourceVoltage_mV=%.2f", sourceVoltage_mV);
    Serial.printf(" maxSonarSensor_mV=%.2f", maxSonarSensor_mV);
    Serial.printf(" Rmm=%.2f", Rmm);
    Serial.printf(" Rcm=%.2f", Rcm);
    Serial.println(); 
}

void loop() {    
    readSensor();
    printRange();    
    delay(2000);
}
