#include "personnel/Contractor.h"
#include "utilities/Utils.h"
#include "utilities/CustomExceptions.h"
#include <iostream>
#include <iomanip>

using namespace std;

// Initialize static counter
int Contractor::contractorCount = 0;

// Constructor
Contractor::Contractor(const string& name, const string& sNumber, double salary,
                       const string& company, const string& clearance, const string& endDate, double cValue)
    : Person(name, sNumber, "Civilian", salary), companyName(company),
      securityClearanceLevel(clearance), contractEndDate(endDate), 
      contractValue(cValue), isClearanceValid(true) {
    
    if (!isClearanceLevelValid(clearance)) {
        throw ValidationException("Invalid security clearance level");
    }
    
    contractorCount++;
    logActivity("Contractor created from company: " + company);
}

// Destructor
Contractor::~Contractor() {
    contractorCount--;
}

// Display contractor information
void Contractor::display() const {
    cout << "\n=== CONTRACTOR PERSONNEL INFORMATION ===" << endl;
    cout << "ID: " << getID() << endl;
    cout << "Name: " << name << endl;
    cout << "Service Number: " << serviceNumber << endl;
    cout << "Salary: $" << fixed << setprecision(2) << salary << endl;
    cout << "Position: " << currentPosition << endl;
    cout << "Company: " << companyName << endl;
    cout << "Security Clearance: " << securityClearanceLevel << endl;
    cout << "Clearance Valid: " << (isClearanceValid ? "YES" : "NO") << endl;
    cout << "Contract End Date: " << contractEndDate << endl;
    cout << "Contract Value: $" << fixed << setprecision(2) << contractValue << endl;
    cout << "Assigned Weapons: " << assignedWeapons.size() << endl;
    for (const auto& weapon : assignedWeapons) {
        cout << "  - " << weapon << endl;
    }
    cout << "Created: " << getDateCreated() << endl;
    cout << "Last Modified: " << getLastModified() << endl;
    cout << "========================================\n" << endl;
}

// Save to file
void Contractor::saveToFile(const string& filename) const {
    cout << "Saving contractor to " << filename << endl;
}

// Load from file
void Contractor::loadFromFile(const string& filename) {
    cout << "Loading contractor from " << filename << endl;
}

// Set company name
void Contractor::setCompanyName(const string& company) {
    companyName = company;
    updateLastModified();
    logActivity("Company updated to: " + company);
}

// Set security clearance level
void Contractor::setSecurityClearanceLevel(const string& clearance) {
    if (!isClearanceLevelValid(clearance)) {
        throw ValidationException("Invalid security clearance level");
    }
    securityClearanceLevel = clearance;
    updateLastModified();
    logActivity("Security clearance updated to: " + clearance);
}

// Set contract end date
void Contractor::setContractEndDate(const string& date) {
    if (!Utils::isValidDate(date)) {
        throw ValidationException("Invalid date format (use YYYY-MM-DD)");
    }
    contractEndDate = date;
    updateLastModified();
    logActivity("Contract end date updated to: " + date);
}

// Set contract value
void Contractor::setContractValue(double value) {
    if (value < 0) {
        throw ValidationException("Contract value cannot be negative");
    }
    contractValue = value;
    updateLastModified();
    logActivity("Contract value updated to: $" + to_string(value));
}

// Validate clearance
bool Contractor::validateClearance() {
    // Check if clearance is still valid (not expired)
    // In this simple implementation, we just return the current status
    return isClearanceValid;
}

// Update clearance status
void Contractor::updateClearanceStatus(bool valid) {
    isClearanceValid = valid;
    updateLastModified();
    if (valid) {
        logActivity("Clearance renewed");
    } else {
        logActivity("Clearance revoked");
    }
}

// Check if clearance level is valid
bool Contractor::isClearanceLevelValid(const string& level) const {
    return Utils::isValidSecurityClearance(level);
}

// Check if contract is expiring
bool Contractor::isContractExpiring(int daysThreshold) const {
    // Simplified implementation - in production, calculate actual days
    return false;
}

// Renew contract
void Contractor::renewContract(const string& newEndDate) {
    if (!Utils::isValidDate(newEndDate)) {
        throw ValidationException("Invalid date format (use YYYY-MM-DD)");
    }
    contractEndDate = newEndDate;
    isClearanceValid = true;
    updateLastModified();
    logActivity("Contract renewed until: " + newEndDate);
}

// Operator< for comparison by contract value
bool Contractor::operator<(const Contractor& other) const {
    return contractValue < other.contractValue;
}

// Operator== for comparison
bool Contractor::operator==(const Contractor& other) const {
    return BaseEntity::operator==(other);
}

// Stream output operator
ostream& operator<<(ostream& out, const Contractor& contractor) {
    out << "Contractor - " << static_cast<const Person&>(contractor)
        << " | Company: " << contractor.companyName
        << " | Clearance: " << contractor.securityClearanceLevel
        << " | Value: $" << fixed << setprecision(2) << contractor.contractValue;
    return out;
}
