#pragma once
#include <string>
using namespace std;

enum CarType{PRIVATE, TRUCK, BUS};

inline int findSpeedLimit(CarType type){
    switch(type){
        case PRIVATE:
        return 80;
        case TRUCK:
        return 60;
        case BUS:
        return 50;
        default :
        return 0;
    }
}

struct Violation{
    int fine = 0;
    string text = "";
};

const int BELT_FINE = 100;
const int SPEEDING_FINE = 300;