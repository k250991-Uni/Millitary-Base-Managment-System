# include <iostream>
# include <string>
# include "Equipment.h"
using namespace std;

Equipment::Equipment(std::string id, std::string name, std::string cond) : equipmentName(name), condition(cond) {}
// hoe to set acquisition date

std::string Equipment::getEquipmentName() const{
    return equipmentName;
}
std::string Equipment::getCondition() {
    return condition;
}
std::string Equipment::getAcquisitionDate() {
    return acquisitionDate;
}

void Equipment::setCondition(std::string newCondition) {
    condition = newCondition;
}

std::string Equipment::getLogEntry() {
    // what to define
}