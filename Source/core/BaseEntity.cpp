#include "core/BaseEntity.h"
#include "utilities/Utils.h"
#include <iostream>

// Initialize static member
int BaseEntity::entityCounter = 0;

// Constructor
BaseEntity::BaseEntity(const string& n) 
    : entityID(++entityCounter), name(n) {
    dateCreated = Utils::getCurrentDateTime();
    lastModified = Utils::getCurrentDateTime();
}

// Destructor
BaseEntity::~BaseEntity() {
}

// Set name and update modification timestamp
void BaseEntity::setName(const string& n) {
    name = n;
    updateLastModified();
    logActivity("Name changed to: " + n);
}

// Update last modified timestamp
void BaseEntity::updateLastModified() {
    lastModified = Utils::getCurrentDateTime();
}

// ILoggable implementation
void BaseEntity::logActivity(string msg) {
    cout << "[LOG] Entity " << entityID << " (" << name << "): " << msg << endl;
}

// Operator== for comparison
bool BaseEntity::operator==(const BaseEntity& other) const {
    return this->entityID == other.entityID;
}

// Operator!= for comparison
bool BaseEntity::operator!=(const BaseEntity& other) const {
    return !(*this == other);
}

// Stream output operator
ostream& operator<<(ostream& out, const BaseEntity& entity) {
    out << "ID: " << entity.entityID 
        << " | Name: " << entity.name 
        << " | Created: " << entity.dateCreated 
        << " | Modified: " << entity.lastModified;
    return out;
}

// Stream input operator
istream& operator>>(istream& in, BaseEntity& entity) {
    cout << "Enter name: ";
    getline(in, entity.name);
    entity.updateLastModified();
    return in;
}
