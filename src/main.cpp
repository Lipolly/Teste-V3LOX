#include "../include/defines.h"
#include "../include/funcsAuxiliares.h"

FuncsAux funcs = FuncsAux();

void setup() {
    Wire.begin();
    Serial.begin(9600);
    digitalWrite(LED_BUILTIN,funcs.init());
    
}

void loop() {
    uint16 dist[8] = {0,0,0,0,0,0,0,0};
    funcs.ler(dist);
    Serial.print("Leituras: ");
    for(int sensor = 0; sensor <= 7; sensor++){
        Serial.print(dist[sensor]);
        Serial.print("  ");
    }
    delay(100);
}
