#include "personnel/Offiicer.h"
#include "utilities/Utils.h"
#include "utilities/CustomExceptions.h"
#include <iostream>
#include <iomanip>

using namespace std;

// Initialize static counter
int Officer::officerCount = 0;

// Constructor
Officer::Officer(const string& name, const string& sNumber, const string& rank,
                 double salary, const string& spec, const string& cmdCenter, int years)
    : Person(name, sNumber, rank, salary), specialization(spec), 
      commandCenter(cmdCenter), yearOfService(years) {
    officerCount++;
    logActivity("Officer created with specialization: " + spec);
}

// Destructor
Officer::~Officer() {
    officerCount--;
}

// Display officer information
void Officer::display() const {
    cout << "\n=== OFFICER INFORMATION ===" << endl;
    cout << "ID: " << getID() << endl;
    cout << "Name: " << name << endl;
    cout << "Service Number: " << serviceNumber << endl;
    cout << "Rank: " << rank << endl;
    cout << "Salary: $" << fixed << setprecision(2) << salary << endl;
    cout << "Position: " << currentPosition << endl;
    cout << "Specialization: " << specialization << endl;
    cout << "Command Center: " << commandCenter << endl;
    cout << "Years of Service: " << yearOfService << endl;
    cout << "Assigned Weapons: " << assignedWeapons.size() << endl;
    for (const auto& weapon : assignedWeapons) {
        cout << "  - " << weapon << endl;
    }
    cout << "Created: " << getDateCreated() << endl;
    cout << "Last Modified: " << getLastModified() << endl;
    cout << "============================\n" << endl;
}

// Save to file
void Officer::saveToFile(const string& filename) const {
    // Implementation for file saving
    cout << "Saving officer to " << filename << endl;
}

// Load from file
void Officer::loadFromFile(const string& filename) {
    // Implementation for file loading
    cout << "Loading officer from " << filename << endl;
}

// Set specialization
void Officer::setSpecialization(const string& spec) {
    specialization = spec;
    updateLastModified();
    logActivity("Specialization updated to: " + spec);
}

// Set command center
void Officer::setCommandCenter(const string& cmdCenter) {
    commandCenter = cmdCenter;
    updateLastModified();
    logActivity("Command center updated to: " + cmdCenter);
}

// Set years of service
void Officer::setYearsOfService(int years) {
    if (years < 0) {
        throw ValidationException("Years of service cannot be negative");
    }
    yearOfService = years;
    updateLastModified();
    logActivity("Years of service updated to: " + to_string(years));
}

// Promote officer
void Officer::promote(const string& newRank) {
    Person::setRank(newRank);
    yearOfService++;
    logActivity("Promoted to rank: " + newRank);
}

// Operator< for comparison by years of service
bool Officer::operator<(const Officer& other) const {
    return yearOfService < other.yearOfService;
}

// Operator== for comparison
bool Officer::operator==(const Officer& other) const {
    return BaseEntity::operator==(other);
}

// Stream output operator
ostream& operator<<(ostream& out, const Officer& officer) {
    out << "Officer - " << static_cast<const Person&>(officer)
        << " | Specialization: " << officer.specialization
        << " | Command: " << officer.commandCenter
        << " | Years: " << officer.yearOfService;
    return out;
}
