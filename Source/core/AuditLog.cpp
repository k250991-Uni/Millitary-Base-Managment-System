#include "core/AuditLog.h"
#include "utilities/Utils.h"
#include <iostream>
#include <fstream>


// Initialize static counter
int AuditLogEntry::entryCounter = 0;

// AuditLogEntry Constructor
AuditLogEntry::AuditLogEntry(const string& opType, const string& entType, int eID, const string& details)
    : entryID(++entryCounter), operationType(opType), entityType(entType), 
      entityID(eID), details(details) {
    timestamp = Utils::getCurrentDateTime();
}

// AuditLogEntry Destructor
AuditLogEntry::~AuditLogEntry() {
}

// Display audit entry
void AuditLogEntry::display() const {
    cout << "[" << entryID << "] " << timestamp << " | Operation: " << operationType 
         << " | Entity: " << entityType << " (ID: " << entityID << ") | Details: " << details << endl;
}

// Equality operator for audit entries
bool AuditLogEntry::operator==(const AuditLogEntry& other) const {
    return this->entryID == other.entryID;
}

// Less than operator
bool AuditLogEntry::operator<(const AuditLogEntry& other) const {
    return this->entryID < other.entryID;
}

// Stream output operator for audit entry
ostream& operator<<(ostream& out, const AuditLogEntry& entry) {
    out << entry.entryID << "|" << entry.timestamp << "|" << entry.operationType 
        << "|" << entry.entityType << "|" << entry.entityID << "|" << entry.details;
    return out;
}

// AuditLog Constructor
AuditLog::AuditLog(const string& logPath) : logFilePath(logPath) {
    loadFromFile();
}

// AuditLog Destructor
AuditLog::~AuditLog() {
    clearAll();
}

// Add entry to audit log
void AuditLog::addEntry(const string& opType, const string& entType, int eID, const string& details) {
    AuditLogEntry* newEntry = new AuditLogEntry(opType, entType, eID, details);
    entries.push_back(newEntry);
}

// Display all entries
void AuditLog::displayAllEntries() const {
    if (entries.empty()) {
        cout << "No audit entries found." << endl;
        return;
    }
    
    cout << "\n=== AUDIT LOG ===" << endl;
    cout << "Total Entries: " << entries.size() << endl;
    cout << Utils::createString(60, '-') << endl;
    
    for (const auto& entry : entries) {
        entry->display();
    }
}

// Search by entity type
void AuditLog::searchByEntityType(const string& entityType) const {
    bool found = false;
    cout << "\n=== AUDIT LOG - Search by Entity Type: " << entityType << " ===" << endl;
    
    for (const auto& entry : entries) {
        if (entry->getEntityType() == entityType) {
            entry->display();
            found = true;
        }
    }
    
    if (!found) {
        cout << "No entries found for entity type: " << entityType << endl;
    }
}

// Search by operation type
void AuditLog::searchByOperationType(const string& operationType) const {
    bool found = false;
    cout << "\n=== AUDIT LOG - Search by Operation Type: " << operationType << " ===" << endl;
    
    for (const auto& entry : entries) {
        if (entry->getOperationType() == operationType) {
            entry->display();
            found = true;
        }
    }
    
    if (!found) {
        cout << "No entries found for operation type: " << operationType << endl;
    }
}

// Search by entity ID
void AuditLog::searchByEntityID(int entityID) const {
    bool found = false;
    cout << "\n=== AUDIT LOG - Search by Entity ID: " << entityID << " ===" << endl;
    
    for (const auto& entry : entries) {
        if (entry->getEntityID() == entityID) {
            entry->display();
            found = true;
        }
    }
    
    if (!found) {
        cout << "No entries found for entity ID: " << entityID << endl;
    }
}

// Save to file
void AuditLog::saveToFile() const {
    ofstream outFile(logFilePath, ios::app);
    if (!outFile.is_open()) {
        cout << "Error opening audit log file." << endl;
        return;
    }
    
    for (const auto& entry : entries) {
        outFile << *entry << endl;
    }
    
    outFile.close();
}

// Load from file
void AuditLog::loadFromFile() {
    ifstream inFile(logFilePath);
    if (!inFile.is_open()) {
        return;  // File doesn't exist yet
    }
    
    string line;
    while (getline(inFile, line)) {
        // Parse and recreate entries from file
        // This is simplified - in production, use proper parsing
    }
    
    inFile.close();
}

// Get entry by index
AuditLogEntry* AuditLog::getEntry(int index) const {
    if (index >= 0 && index < entries.size()) {
        return entries[index];
    }
    return nullptr;
}

// Clear all entries
void AuditLog::clearAll() {
    for (auto entry : entries) {
        delete entry;
    }
    entries.clear();
}
