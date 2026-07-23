#include <string>
#include "rules.h"


Rule::Rule(string type){
    violationType = type;
}

Seatbelt::Seatbelt() : Rule("belt") {}

Violation Seatbelt::checkAndIssueFine(CarType type, int speed, bool belt){
     if(!belt){
        return {BELT_FINE, "- Seatbelt not fastned : " + to_string(BELT_FINE) + " EGP"};
    }
    return {0, ""};
}


Speeding::Speeding() : Rule("speeding") {}

Violation Speeding::checkAndIssueFine(CarType type, int speed, bool belt){
    int limit = findSpeedLimit(type);
    if(speed > limit){
        return {SPEEDING_FINE, "- speed of " + to_string(speed) + " exceeded max allowed " + to_string(limit) + " : " + to_string(SPEEDING_FINE) +" EGP"};
    }
    return {0, ""};
}    
