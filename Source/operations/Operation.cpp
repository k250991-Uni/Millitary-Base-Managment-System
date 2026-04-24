#include "operations/Operation.h"
#include "utilities/Utils.h"
#include "utilities/CustomExceptions.h"
#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

// Initialize static counter
int Operation::operationCount = 0;

// Constructor
Operation::Operation(const string& code, const string& opType, const string& cmdName,
                     const string& loc, const string& desc)
    : BaseEntity(code), operationCode(code), operationType(opType), 
      commander(cmdName), location(loc), description(desc), casualtyCount(0) {
    
    status = "Planned";
    startDate = Utils::getCurrentDate();
    endDate = "";
    
    if (!Utils::isValidOperationStatus(status)) {
        throw InvalidOperationStatusException(status);
    }
    
    operationCount++;
    logActivity("Operation created: " + opType + " at " + loc);
}

// Destructor
Operation::~Operation() {
    operationCount--;
    // Clean up dynamic vectors
    assignedPersonnelIDs.clear();
    requiredEquipmentIDs.clear();
}

// Display operation information
void Operation::display() const {
    cout << "\n=== OPERATION INFORMATION ===" << endl;
    cout << "ID: " << getID() << endl;
    cout << "Operation Code: " << operationCode << endl;
    cout << "Type: " << operationType << endl;
    cout << "Commander: " << commander << endl;
    cout << "Location: " << location << endl;
    cout << "Status: " << status << endl;
    cout << "Start Date: " << startDate << endl;
    cout << "End Date: " << (endDate.empty() ? "N/A" : endDate) << endl;
    cout << "Description: " << description << endl;
    cout << "Assigned Personnel: " << assignedPersonnelIDs.size() << endl;
    for (int id : assignedPersonnelIDs) {
        cout << "  - Personnel ID: " << id << endl;
    }
    cout << "Required Equipment: " << requiredEquipmentIDs.size() << endl;
    for (int id : requiredEquipmentIDs) {
        cout << "  - Equipment ID: " << id << endl;
    }
    cout << "Casualty Count: " << casualtyCount << endl;
    cout << "Created: " << getDateCreated() << endl;
    cout << "Last Modified: " << getLastModified() << endl;
    cout << "=============================\n" << endl;
}

// Save to file
void Operation::saveToFile(const string& filename) const {
    cout << "Saving operation to " << filename << endl;
}

// Load from file
void Operation::loadFromFile(const string& filename) {
    cout << "Loading operation from " << filename << endl;
}

// Set status
void Operation::setStatus(const string& newStatus) {
    if (!Utils::isValidOperationStatus(newStatus)) {
        throw InvalidOperationStatusException(newStatus);
    }
    status = newStatus;
    updateLastModified();
    logActivity("Status updated to: " + newStatus);
}

// Set location
void Operation::setLocation(const string& loc) {
    location = loc;
    updateLastModified();
    logActivity("Location updated to: " + loc);
}

// Set commander
void Operation::setCommander(const string& cmdName) {
    commander = cmdName;
    updateLastModified();
    logActivity("Commander updated to: " + cmdName);
}

// Set description
void Operation::setDescription(const string& desc) {
    description = desc;
    updateLastModified();
    logActivity("Description updated");
}

// Set casualty count
void Operation::setCasualtyCount(int count) {
    if (count < 0) {
        throw ValidationException("Casualty count cannot be negative");
    }
    casualtyCount = count;
    updateLastModified();
    logActivity("Casualty count updated to: " + to_string(count));
}

// Assign personnel
void Operation::assignPersonnel(int personnelID) {
    if (!isPersonnelAssigned(personnelID)) {
        assignedPersonnelIDs.push_back(personnelID);
        updateLastModified();
        logActivity("Personnel " + to_string(personnelID) + " assigned");
    }
}

// Remove personnel
void Operation::removePersonnel(int personnelID) {
    auto it = find(assignedPersonnelIDs.begin(), assignedPersonnelIDs.end(), personnelID);
    if (it != assignedPersonnelIDs.end()) {
        assignedPersonnelIDs.erase(it);
        updateLastModified();
        logActivity("Personnel " + to_string(personnelID) + " removed");
    }
}

// Check if personnel is assigned
bool Operation::isPersonnelAssigned(int personnelID) const {
    auto it = find(assignedPersonnelIDs.begin(), assignedPersonnelIDs.end(), personnelID);
    return it != assignedPersonnelIDs.end();
}

// Get assigned personnel count
int Operation::getAssignedPersonnelCount() const {
    return assignedPersonnelIDs.size();
}

// Require equipment
void Operation::requireEquipment(int equipmentID) {
    if (!isEquipmentRequired(equipmentID)) {
        requiredEquipmentIDs.push_back(equipmentID);
        updateLastModified();
        logActivity("Equipment " + to_string(equipmentID) + " required");
    }
}

// Release equipment
void Operation::releaseEquipment(int equipmentID) {
    auto it = find(requiredEquipmentIDs.begin(), requiredEquipmentIDs.end(), equipmentID);
    if (it != requiredEquipmentIDs.end()) {
        requiredEquipmentIDs.erase(it);
        updateLastModified();
        logActivity("Equipment " + to_string(equipmentID) + " released");
    }
}

// Check if equipment is required
bool Operation::isEquipmentRequired(int equipmentID) const {
    auto it = find(requiredEquipmentIDs.begin(), requiredEquipmentIDs.end(), equipmentID);
    return it != requiredEquipmentIDs.end();
}

// Get required equipment count
int Operation::getRequiredEquipmentCount() const {
    return requiredEquipmentIDs.size();
}

// Operator< for comparison by start date
bool Operation::operator<(const Operation& other) const {
    return startDate < other.startDate;
}

// Operator== for comparison
bool Operation::operator==(const Operation& other) const {
    return BaseEntity::operator==(other);
}

// Stream output operator
ostream& operator<<(ostream& out, const Operation& operation) {
    out << "Operation - Code: " << operation.operationCode
        << " | Type: " << operation.operationType
        << " | Location: " << operation.location
        << " | Status: " << operation.status
        << " | Commander: " << operation.commander
        << " | Personnel: " << operation.assignedPersonnelIDs.size()
        << " | Equipment: " << operation.requiredEquipmentIDs.size();
    return out;
}
