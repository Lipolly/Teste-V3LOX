#include "../include/funcsAuxiliares.h"

#include "../include/defines.h"

VL53L0X sensor[8];

FuncsAux::FuncsAux() {}

bool FuncsAux::init() {
    for (int i = 0; i < 7; i++) {
        digitalWrite(XSHUT1, !i);
        digitalWrite(XSHUT2, !i);
        digitalWrite(XSHUT3, !i);
        digitalWrite(XSHUT4, !i);
        digitalWrite(XSHUT5, !i);
        digitalWrite(XSHUT6, !i);
        digitalWrite(XSHUT7, !i);
        digitalWrite(XSHUT8, i);
        delay(10);
        sensor[i].setTimeout(500);
        sensor[i].setMeasurementTimingBudget(200000);
        if (!sensor[i].init()) {
            Serial.println("Não deu certo");
            return false;
        }
    }
    return true;
}

void FuncsAux::ler(uint16 data[]) {
    for(int i = 0; i < 1; i++) {
    data[i] = sensor[i].readRangeSingleMillimeters();
        if (sensor[i].timeoutOccurred()) {
            Serial.println("TIMEOUT");
            if (!sensor[i].init()) {
                Serial.println("Parou");
            }
        }
    }
}