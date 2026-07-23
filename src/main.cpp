#include "helpers.h"
#include "radar.h"
#include <iostream>

int main(){
    Radar radar;

    std::cout << "Adding speeding and seatbelt rules..." << std::endl;

    radar.addRule(new Seatbelt());
    radar.addRule(new Speeding());

    std::cout << "=================================================" << std::endl;
    std::cout << "----------- Checking for violations -------------" << std::endl;
    std::cout << "=================================================" << std::endl;

    radar.checkForViolations("ABC1234", "2026-07-23", PRIVATE, 94, true);

    radar.checkForViolations("BUS9999", "2026-07-23", BUS, 65, false);

    radar.checkForViolations("TRK5555", "2026-07-23", TRUCK, 55, true);

    radar.checkForViolations("XYZ7890", "2026-07-23", PRIVATE, 70, false);

    radar.checkForViolations("ABC1234", "2026-07-23", PRIVATE, 110, true);

    std::cout << "=================================================" << std::endl;
    std::cout << "--------------- Getting all fines ---------------" << std::endl;
    std::cout << "=================================================" << std::endl;

    radar.getAllFines();
    
    std::cout << "=================================================" << std::endl;
    std::cout << "------------ Getting all violations -------------" << std::endl;
    std::cout << "=================================================" << std::endl;
    radar.getAllViolations();
}