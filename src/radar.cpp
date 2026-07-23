#include <iostream>
#include <unordered_map>
#include <string>
#include "helpers.h"
#include "rules.h"
#include "radar.h"
using namespace std;

string typeAsString[3] = {"car", "truck", "bus"};

void Radar::addRule(Rule* r){
    rules.push_back(r);
}

void Radar::checkForViolations(string plate, string date, CarType type, int speed, bool belt){
    vector<Violation> violationsForThisPlate;

    for(const auto& r : rules){
        Violation result = r->checkAndIssueFine(type, speed, belt);
        if(result.fine > 0){
            violations[r->violationType]++;
            fines[plate] += result.fine;
            violationsForThisPlate.push_back(result);
        }
    }

    if(fines.count(plate) != 0){
        cout << "Traffic fine for " << typeAsString[type] << " " << plate << endl;
        cout << "Total amount: " << fines[plate] << " EGP" << endl;
        cout << "Violations:" << endl;
        for(const auto& v : violationsForThisPlate){
            cout << v.text << endl;
        }
        cout << endl;
    }
}

void Radar::getAllFines(){
    if(fines.empty()){
        cout << "There are currently no issued fines to any vehicle." << endl; return;
    }

    for(const auto& [plate, fine] : fines){
        cout << plate << " has been issued fines adding up to : " << fine << " EGP" << endl;
    }

    cout << endl;
}

void Radar::getAllViolations(){
    for(const auto& [violation, count] : violations){
        cout << "There has been " << count << " cases of " << violation << " violations." << endl;
    }

    cout << endl;
}
