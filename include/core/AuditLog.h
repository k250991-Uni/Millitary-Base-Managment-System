#ifndef AUDIT_LOG_H
#define AUDIT_LOG_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// AuditLog entry for tracking system operations
class AuditLogEntry {
private:
    int entryID;                // Unique ID for audit entry
    string timestamp;           // When operation occurred
    string operationType;       // Type of operation (ADD, UPDATE, DELETE, etc.)
    string entityType;          // Type of entity affected
    int entityID;               // ID of affected entity
    string details;             // Additional operation details
    static int entryCounter;    // Track total entries
    
public:
    AuditLogEntry(const string& opType, const string& entType, int eID, const string& details);
    ~AuditLogEntry();
    
    // Getters
    int getEntryID() const { return entryID; }
    string getTimestamp() const { return timestamp; }
    string getOperationType() const { return operationType; }
    string getEntityType() const { return entityType; }
    int getEntityID() const { return entityID; }
    string getDetails() const { return details; }
    static int getTotalEntries() { return entryCounter; }
    
    // Display audit entry
    void display() const;
    
    // Operators for comparison
    bool operator==(const AuditLogEntry& other) const;
    bool operator<(const AuditLogEntry& other) const;
    
    // Stream operators
    friend ostream& operator<<(ostream& out, const AuditLogEntry& entry);
};

// AuditLog manager for storing and managing audit entries
class AuditLog {
private:
    vector<AuditLogEntry*> entries;
    string logFilePath;
    
public:
    AuditLog(const string& logPath = "audit_log.txt");
    ~AuditLog();
    
    // Add entry to audit log
    void addEntry(const string& opType, const string& entType, int eID, const string& details);
    
    // Display all entries
    void displayAllEntries() const;
    
    // Search entries
    void searchByEntityType(const string& entityType) const;
    void searchByOperationType(const string& operationType) const;
    void searchByEntityID(int entityID) const;
    
    // File operations
    void saveToFile() const;
    void loadFromFile();
    
    // Get entry count
    int getEntryCount() const { return entries.size(); }
    
    // Get entry by index
    AuditLogEntry* getEntry(int index) const;
    
    // Clear all entries
    void clearAll();
};

#endif
