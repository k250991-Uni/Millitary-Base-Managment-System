#include "logistics/Weapon.h"
#include "utilities/Utils.h"
#include "utilities/CustomExceptions.h"
#include <iostream>
#include <iomanip>

using namespace std;

// Initialize static counter
int Weapon::weaponCount = 0;

// Constructor
Weapon::Weapon(const string& name, const string& code, const string& type,
               int qty, double cost, const string& loc, int ammo, int magCap, const string& cal)
    : Equipment(name, code, qty, cost, loc), weaponType(type), ammunition(ammo),
      magazineCapacity(magCap), caliber(cal), isLocked(true) {
    
    if (ammo < 0 || magCap < 0) {
        throw ValidationException("Ammunition and magazine capacity cannot be negative");
    }
    
    weaponCount++;
    condition = "Serviceable";
    logActivity("Weapon created: " + type + " | Caliber: " + cal);
}

// Destructor
Weapon::~Weapon() {
    weaponCount--;
}

// Validate condition
bool Weapon::validateCondition(const string& cond) const {
    vector<string> validConditions = {"Serviceable", "Unserviceable", "Maintenance", "Locked"};
    for (const auto& c : validConditions) {
        if (Utils::toLowerCase(cond) == Utils::toLowerCase(c)) {
            return true;
        }
    }
    return false;
}

// Display weapon information
void Weapon::display() const {
    cout << "\n=== WEAPON INFORMATION ===" << endl;
    cout << "ID: " << getID() << endl;
    cout << "Name: " << name << endl;
    cout << "Code: " << equipmentCode << endl;
    cout << "Type: " << weaponType << endl;
    cout << "Caliber: " << caliber << endl;
    cout << "Quantity: " << quantity << endl;
    cout << "Unit Cost: $" << fixed << setprecision(2) << unitCost << endl;
    cout << "Total Value: $" << fixed << setprecision(2) << getTotalValue() << endl;
    cout << "Condition: " << condition << endl;
    cout << "Location: " << location << endl;
    cout << "Ammunition: " << ammunition << "/" << magazineCapacity << " (" 
         << getAmmunitionPercentage() << "%)" << endl;
    cout << "Security Lock: " << (isLocked ? "LOCKED" : "UNLOCKED") << endl;
    cout << "Last Service: " << lastServiceDate << endl;
    cout << "Created: " << getDateCreated() << endl;
    cout << "Last Modified: " << getLastModified() << endl;
    cout << "===========================\n" << endl;
}

// Save to file
void Weapon::saveToFile(const string& filename) const {
    cout << "Saving weapon to " << filename << endl;
}

// Load from file
void Weapon::loadFromFile(const string& filename) {
    cout << "Loading weapon from " << filename << endl;
}

// Set weapon type
void Weapon::setWeaponType(const string& type) {
    weaponType = type;
    updateLastModified();
    logActivity("Weapon type updated to: " + type);
}

string Weapon::getWeaponType() const {
    return weaponType;
}

string Weapon::getCaliber() const {
    return caliber;
}

bool Weapon::isWeaponLocked() const {
    return isLocked;
}

// Set caliber
void Weapon::setCaliber(const string& cal) {
    caliber = cal;
    updateLastModified();
    logActivity("Caliber updated to: " + cal);
}

// Add ammunition
void Weapon::addAmmunition(int amount) {
    if (amount < 0) {
        throw ValidationException("Cannot add negative ammunition");
    }
    ammunition += amount;
    if (ammunition > magazineCapacity) {
        ammunition = magazineCapacity;
    }
    updateLastModified();
    logActivity("Added " + to_string(amount) + " ammunition. Total: " + to_string(ammunition));
}

// Remove ammunition
void Weapon::removeAmmunition(int amount) {
    if (amount < 0) {
        throw ValidationException("Cannot remove negative ammunition");
    }
    if (amount > ammunition) {
        throw InsufficientSupplyException("Ammunition", amount, ammunition);
    }
    ammunition -= amount;
    updateLastModified();
    logActivity("Removed " + to_string(amount) + " ammunition. Total: " + to_string(ammunition));
}

// Check adequate ammunition
bool Weapon::hasAdequateAmmunition(int required) const {
    return ammunition >= required;
}

// Get ammunition percentage
int Weapon::getAmmunitionPercentage() const {
    if (magazineCapacity == 0) return 0;
    return (ammunition * 100) / magazineCapacity;
}

// Lock weapon
void Weapon::lockWeapon() {
    isLocked = true;
    condition = "Locked";
    updateLastModified();
    logActivity("Weapon locked");
}

// Unlock weapon
void Weapon::unlockWeapon() {
    isLocked = false;
    condition = "Serviceable";
    updateLastModified();
    logActivity("Weapon unlocked");
}

// Check if can be issued
bool Weapon::canBeIssued() const {
    return !isLocked && condition == "Serviceable" && ammunition > 0;
}

// Perform maintenance
void Weapon::performMaintenance() {
    condition = "Serviceable";
    updateLastServiceDate();
    logActivity("Maintenance performed");
}

string Weapon::getEntityType() const {
    return "Weapon";
}

string Weapon::getEquipmentType() const {
    return weaponType;
}

// Operator< for comparison by ammunition percentage
bool Weapon::operator<(const Weapon& other) const {
    return getAmmunitionPercentage() < other.getAmmunitionPercentage();
}

// Operator== for comparison
bool Weapon::operator==(const Weapon& other) const {
    return BaseEntity::operator==(other);
}

// Stream output operator
ostream& operator<<(ostream& out, const Weapon& weapon) {
    out << "Weapon - ID: " << weapon.getID()
        << " | Type: " << weapon.getWeaponType()
        << " | Caliber: " << weapon.getCaliber()
        << " | Ammo: " << weapon.getCurrentAmmunition() << "/" << weapon.getMaxAmmunitionCapacity()
        << " | Status: " << (weapon.isWeaponLocked() ? "LOCKED" : "UNLOCKED");
    return out;
}
