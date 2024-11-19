#include "fuzzy_function.h"

float pH, PPM, selisih_pH, selisih_PPM;
float set_pH = 6.8;
float set_PPM = 1000;

void baca_pH();
void baca_PPM();
void outputFuzzy();

void setup() {
  Serial.begin(115200);
  //pinMode(relay_pHup, OUTPUT);
  //pinMode(relay_pHdn, OUTPUT);
  //pinMode(relay_nutrisi, OUTPUT);
}

void loop() {
  baca_pH();
  baca_PPM();
  outputFuzzy();
  Serial.println("=============================================");
  Serial.print("pH : ");Serial.println(pH);
  if (pH < set_pH){
    Serial.print("Input Fuzzy pH : ");Serial.println(Error_pH);
    Serial.print("Output Fuzzy pH Up : ");Serial.print(lamaPompa_pH);
    Serial.println(" detik");
  }else if (pH >= set_pH){
    Serial.print("Input Fuzzy pH : ");Serial.println(Error_pH);
    Serial.print("Output Fuzzy pH Down: ");Serial.print(lamaPompa_pH);
    Serial.println(" detik");
  }
  Serial.println("");
  Serial.print("PPM : ");Serial.println(PPM);
  Serial.print("Input Fuzzy PPM : ");Serial.println(Error_PPM);
  Serial.print("Output Fuzzy PPM : ");Serial.print(lamaPompa_PPM);
  Serial.println(" detik");
  Serial.println("=============================================");
  delay(3000);
}


void baca_pH(){
  int randomNumber = random(0, 41);  
  //angka random dari 6 sampai 8 dengan interval 0,1
  pH = 5.0 + (randomNumber * 0.1);

  selisih_pH = abs(set_pH - pH);
  Error_pH = selisih_pH;
}

void baca_PPM(){
  PPM = random(500, 1500); 
  if (PPM <= set_PPM){
    selisih_PPM = set_PPM - PPM;
  }
  else if (PPM > set_PPM){
    selisih_PPM = 0;
  }
  Error_PPM = selisih_PPM;
}

void outputFuzzy (){
  moment();
  lamaPompa_pH = deffuzzyfikasi_pH()/1000;
  lamaPompa_PPM = deffuzzyfikasi_PPM()/1000;
}
