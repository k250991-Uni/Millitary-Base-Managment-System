# include <iostream>
# include <string>
# include <fstream>
# include <sstream>
# include "Equipment.h"
# include "Weapon.h"

int Weapon::totalWeapons = 0;

Weapon::Weapon(std::string id, std::string name, std::string caliber, std::string fireMode, int maxAmmo) 
        : Equipment(id, name, /*cond*/) , caliber(caliber), fireMode(fireMode), maxAmmunitionCapacity(maxAmmo)
        /*what to initialize the currentAmmunition */ {totalWeapons++;}


// the file is in the format id|name|condition|acquisitionDate|caliber|firemode|currentAmmunition|maxAmmunitionCapacity
void Weapon::saveToFile(std::string fileName) {
    std::ofstream out("Weapon_Data.txt", std::ios::app);
    if(!out) {
        std::cout << "Could not open the file.\n";
        return;
    }

}
void Weapon::loadFromFile(std::string fileName) {
    std::ifstream in("Weapon_Data.txt");

    if(!in){
        std::cout << "Could not open the file.\n";
        return;
    }

    in >> totalWeapons;
    in.ignore();

    std::string line;

    while(getline(in, line)){
        std::stringstream ss(line);

        std::string temp1, temp2, temp3, temp4, temp5;

        //std::getline(ss, id, "|");    // id
        std::getline(ss, temp1, '|');   //name
        std::getline(ss, temp2, '|');   //condition
        std::getline(ss, temp3, '|');   //acquisitionDate
        std::getline(ss, caliber, '|'); //caliber
        std::getline(ss, fireMode, '|');//firemode
        std::getline(ss, temp4, '|');   //currentAmmunition
        std::getline(ss, temp5, '|');   //maxAmmunitionCapacity

        setEquipmentName(temp1);
        setCondition(temp2);
        setAcquisitionDate(temp3);
        maxAmmunitionCapacity = std::stoi(temp4);
        currentAmmunition = std::stoi(temp5);

    }
}

void Weapon::fireWeapon(int rounds) {
    if((currentAmmunition - rounds) > 0) {currentAmmunition -= rounds; std::cout << "Fired\n";}
    else {std::cout << "Not enough ammunition left, ammunition left are: " << currentAmmunition << std::endl;}
}
void Weapon::reload(int roundsAdded){
    if((currentAmmunition + roundsAdded) <= maxAmmunitionCapacity) {currentAmmunition += roundsAdded; std::cout << "Reloaded\n";}
    else {std::cout << "Not enought sapce, spaces left are: " << maxAmmunitionCapacity - currentAmmunition << std::endl;}
}
void Weapon::unloadAmmo(){
    currentAmmunition = 0;
    std::cout << "Ammo unloaded\n";
}

std::string Weapon::getEquipmentType() {
    // what to do
}
std::string Weapon::getEntityType() {
    // what to do
}
std::string Weapon::getCaliber() {
    return caliber;
}
std::string Weapon::getFireMode() {
    return fireMode;
}
int Weapon::getCurrentAmmunition() {
    return currentAmmunition;
}
int Weapon::getMaxAmmunitionCapacity() {
    return maxAmmunitionCapacity;
}
int Weapon::getTotalWeapons() {
    return totalWeapons;
}

void Weapon::display(){
    // do it later
}

bool Weapon::operator<(Weapon& other) {
    
}
bool Weapon::operator==(Weapon& other) {

}
Weapon Weapon::operator+(Weapon& other){

}

void Weapon::display() {

}

Weapon::~Weapon() {
    totalWeapons--;
}