# include <iostream>
# include <string>
# include <fstream>
# include "Equipment.h"
# include "Supplies.h"

int Supplies::totalSupplies = 0;

Supplies::Supplies(std::string id, std::string name, std::string type, std::string expiry, std::string location, int qty)
                : Equipment(id, name, /*cond*/), supplyType(type), expirayDate(expiry), storageLocation(location), quantity(qty)
                {totalSupplies++;}

void Supplies::saveToFile(std::string fileName) {
    // left 1
}

void Supplies::loadFromFile(std::string fileName) {
    // left 2, total left 6
}

std::string Supplies::getEquipmentType() {
    // where is Equipment type
}

std::string Supplies::getEntityType(){
    // what to do, where is entity
}

std::string Supplies::getSupplyType() {
    return supplyType;
}
std::string Supplies::getExpiryDate() {
    return expirayDate;
}
std::string Supplies::getStorageLocation() {
    return storageLocation;
}
int Supplies::getQuantity(){
    return quantity;
}
int Supplies::getTotalSupplies(){
    return totalSupplies;
}

void Supplies::updateQuantity(int change){
    quantity += change;
}
void Supplies::moveToLocation(std::string newLocation){
    storageLocation = newLocation;
}
bool isExpired(){
    // what to do, where is expired
}

bool Supplies::operator<(const Supplies& other) {
    if( supplyType == other.supplyType &&
        expirayDate == other.expirayDate &&
        storageLocation == other.storageLocation &&
        getEquipmentName() == other.getEquipmentName()) // why was there an error when using other.getEquipmentName() when getEquipmentName was not const in the Equipment class
        {
            if(quantity < other.quantity) {return true;}
            else {return false;}
        } else {
            std::cout << "Cannot cannot compare differenet supplies\n";
        }
}

bool Supplies::operator==(const Supplies& other) {
    if( supplyType == other.supplyType &&
        expirayDate == other.expirayDate &&
        storageLocation == other.storageLocation &&
        getEquipmentName() == other.getEquipmentName()) // why was there an error when using other.getEquipmentName() when getEquipmentName was not const in the Equipment class
        {
            if(quantity == other.quantity) {return true;}
            else {return false;}
        } else {
            std::cout << "Cannot cannot compare differenet supplies\n";
        }
}

Supplies Supplies::operator+(const Supplies& other) {
    if( supplyType == other.supplyType &&
        expirayDate == other.expirayDate &&
        storageLocation == other.storageLocation &&
        getEquipmentName() == other.getEquipmentName()) // why was there an error when using other.getEquipmentName() when getEquipmentName was not const in the Equipment class
        {
            Supplies result = *this;
            result.quantity += other.quantity;
            return result;
        } else {
            std::cout << "Cannot merge differenet supplies\n";
        }
}

void Supplies::display() {
    // what to do
}

Supplies::~Supplies() {
    totalSupplies--;
}