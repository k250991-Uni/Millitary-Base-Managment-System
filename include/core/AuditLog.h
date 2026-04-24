#ifndef AUDIT_LOG_H
#define AUDIT_LOG_H

#include <iosfwd>
#include <string>
#include <vector>

// AuditLog entry for tracking system operations
class AuditLogEntry {
private:
    int entryID;                // Unique ID for audit entry
    std::string timestamp;      // When operation occurred
    std::string operationType;  // Type of operation (ADD, UPDATE, DELETE, etc.)
    std::string entityType;     // Type of entity affected
    int entityID;               // ID of affected entity
    std::string details;        // Additional operation details
    static int entryCounter;    // Track total entries
    
public:
    AuditLogEntry(const std::string& opType, const std::string& entType, int eID, const std::string& details);
    ~AuditLogEntry();
    
    // Getters
    int getEntryID() const { return entryID; }
    std::string getTimestamp() const { return timestamp; }
    std::string getOperationType() const { return operationType; }
    std::string getEntityType() const { return entityType; }
    int getEntityID() const { return entityID; }
    std::string getDetails() const { return details; }
    static int getTotalEntries() { return entryCounter; }
    
    // Display audit entry
    void display() const;
    
    // Operators for comparison
    bool operator==(const AuditLogEntry& other) const;
    bool operator<(const AuditLogEntry& other) const;
    
    // Stream operators
    friend std::ostream& operator<<(std::ostream& out, const AuditLogEntry& entry);
};

// AuditLog manager for storing and managing audit entries
class AuditLog {
private:
    std::vector<AuditLogEntry*> entries;
    std::string logFilePath;
    
public:
    AuditLog(const std::string& logPath = "audit_log.txt");
    ~AuditLog();
    
    // Add entry to audit log
    void addEntry(const std::string& opType, const std::string& entType, int eID, const std::string& details);
    
    // Display all entries
    void displayAllEntries() const;
    
    // Search entries
    void searchByEntityType(const std::string& entityType) const;
    void searchByOperationType(const std::string& operationType) const;
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
