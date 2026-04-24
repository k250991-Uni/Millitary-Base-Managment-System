#ifndef OPERATION_H
#define OPERATION_H

#include "core/BaseEntity.h"
#include <string>
#include <vector>
using namespace std;

// Operation class - represents military operations
class Operation : public BaseEntity {
private:
    string operationCode;           // Unique operation code
    string operationType;           // Type of operation (Training, Patrol, Combat, etc.)
    string status;                  // Current status (Planned, Active, Completed, Aborted)
    string location;                // Operation location
    string commander;               // Operation commander (Officer name/ID)
    vector<int> assignedPersonnelIDs;  // Personnel assigned to operation
    vector<int> requiredEquipmentIDs;  // Equipment required
    string startDate;               // Operation start date
    string endDate;                 // Operation end date
    string description;             // Operation description
    int casualtyCount;              // Number of casualties
    static int operationCount;      // Total operations
    
public:
    Operation(const string& code, const string& opType, const string& cmdName,
              const string& loc, const string& desc);
    ~Operation();
    
    // Override virtual functions
    void display() const override;
    void saveToFile(const string& filename) const override;
    void loadFromFile(const string& filename) override;
    string getEntityType() const override { return "Operation"; }
    
    // Getters
    string getOperationCode() const { return operationCode; }
    string getOperationType() const { return operationType; }
    string getStatus() const { return status; }
    string getLocation() const { return location; }
    string getCommander() const { return commander; }
    string getStartDate() const { return startDate; }
    string getEndDate() const { return endDate; }
    string getDescription() const { return description; }
    int getCasualtyCount() const { return casualtyCount; }
    vector<int> getAssignedPersonnelIDs() const { return assignedPersonnelIDs; }
    vector<int> getRequiredEquipmentIDs() const { return requiredEquipmentIDs; }
    static int getOperationCount() { return operationCount; }
    
    // Setters
    void setStatus(const string& newStatus);
    void setLocation(const string& loc);
    void setCommander(const string& cmdName);
    void setDescription(const string& desc);
    void setCasualtyCount(int count);
    
    // Personnel management
    void assignPersonnel(int personnelID);
    void removePersonnel(int personnelID);
    bool isPersonnelAssigned(int personnelID) const;
    int getAssignedPersonnelCount() const;
    
    // Equipment management
    void requireEquipment(int equipmentID);
    void releaseEquipment(int equipmentID);
    bool isEquipmentRequired(int equipmentID) const;
    int getRequiredEquipmentCount() const;
    
    // Operation status management
    void activateOperation();
    void completeOperation();
    void abortOperation();
    bool isActive() const;
    
    // Operators
    bool operator<(const Operation& other) const;  // Compare by start date
    bool operator==(const Operation& other) const;
    
    // Stream operators
    friend ostream& operator<<(ostream& out, const Operation& operation);
};

#endif
 