#include "personnel/Person.h"
#include "utilities/Utils.h"
#include "utilities/CustomExceptions.h"
#include <iostream>
#include <algorithm>

using namespace std;

using namespace std;

// Constructor
Person::Person(const string& name, const string& sNumber, const string& r, double sal)
    : BaseEntity(name), serviceNumber(sNumber), rank(r), salary(sal) {
    currentPosition = "Unassigned";
    
    if (!isValidServiceNumber(sNumber)) {
        throw ValidationException("Invalid service number format");
    }
    
    if (!Utils::isValidRank(r)) {
        throw InvalidRankException(r);
    }
    
    if (sal < 0) {
        throw ValidationException("Salary cannot be negative");
    }
}

// Destructor
Person::~Person() {
}

// Set rank
void Person::setRank(const string& newRank) {
    if (!Utils::isValidRank(newRank)) {
        throw InvalidRankException(newRank);
    }
    rank = newRank;
    updateLastModified();
    logActivity("Rank updated to: " + newRank);
}

// Set salary
void Person::setSalary(double newSalary) {
    if (newSalary < 0) {
        throw ValidationException("Salary cannot be negative");
    }
    salary = newSalary;
    updateLastModified();
    logActivity("Salary updated to: $" + to_string(newSalary));
}

// Set current position
void Person::setCurrentPosition(const string& newPosition) {
    currentPosition = newPosition;
    updateLastModified();
    logActivity("Position updated to: " + newPosition);
}

// Add assigned weapon
void Person::addAssignedWeapon(const string& weaponID) {
    auto it = find(assignedWeapons.begin(), assignedWeapons.end(), weaponID);
    if (it == assignedWeapons.end()) {
        assignedWeapons.push_back(weaponID);
        logActivity("Weapon " + weaponID + " assigned");
    }
}

// Remove assigned weapon
void Person::removeAssignedWeapon(const string& weaponID) {
    auto it = find(assignedWeapons.begin(), assignedWeapons.end(), weaponID);
    if (it != assignedWeapons.end()) {
        assignedWeapons.erase(it);
        logActivity("Weapon " + weaponID + " removed");
    }
}

// Validate service number
bool Person::isValidServiceNumber(const string& sNumber) {
    return Utils::isValidServiceNumber(sNumber);
}

// Operator< for comparison by rank
bool Person::operator<(const Person& other) const {
    return rank < other.rank;
}

// Operator== for comparison
bool Person::operator==(const Person& other) const {
    return BaseEntity::operator==(other);
}

// Stream output operator
ostream& operator<<(ostream& out, const Person& person) {
    out << "Name: " << person.name 
        << " | Service #: " << person.serviceNumber 
        << " | Rank: " << person.rank
        << " | Position: " << person.currentPosition
        << " | Salary: $" << fixed << person.salary;
    return out;
}

// Stream input operator
istream& operator>>(istream& in, Person& person) {
    cout << "Enter service number: ";
    getline(in, person.serviceNumber);
    
    cout << "Enter rank: ";
    getline(in, person.rank);
    
    cout << "Enter salary: ";
    string salaryStr;
    getline(in, salaryStr);
    try {
        person.salary = stod(salaryStr);
    }
    catch (...) {
        throw ValidationException("Invalid salary format");
    }
    
    person.updateLastModified();
    return in;
}
