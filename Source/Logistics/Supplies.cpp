#include "logistics/Supplies.h"
#include "utilities/Utils.h"
#include "utilities/CustomExceptions.h"
#include <iostream>
#include <iomanip>

using namespace std;

// Initialize static counter
int Supplies::supplyCount = 0;

// Constructor
Supplies::Supplies(const string& name, const string& code, const string& type,
                   int qty, double cost, const string& loc, const string& expDate, 
                   int minStock, const string& supp)
    : Equipment(name, code, qty, cost, loc), supplyType(type), expirationDate(expDate),
      minStockLevel(minStock), supplier(supp) {
    
    if (minStock < 0) {
        throw ValidationException("Minimum stock level cannot be negative");
    }
    
    supplyCount++;
    condition = "Available";
    logActivity("Supply created: " + type + " | Supplier: " + supp);
}

// Destructor
Supplies::~Supplies() {
    supplyCount--;
}

// Validate condition
bool Supplies::validateCondition(const string& cond) const {
    vector<string> validConditions = {"Available", "Low", "Critical", "Expired"};
    for (const auto& c : validConditions) {
        if (Utils::toLowerCase(cond) == Utils::toLowerCase(c)) {
            return true;
        }
    }
    return false;
}

// Display supplies information
void Supplies::display() const {
    cout << "\n=== SUPPLIES INFORMATION ===" << endl;
    cout << "ID: " << getID() << endl;
    cout << "Name: " << name << endl;
    cout << "Code: " << equipmentCode << endl;
    cout << "Type: " << supplyType << endl;
    cout << "Quantity: " << quantity << endl;
    cout << "Unit Cost: Rs" << fixed << setprecision(2) << unitCost << endl;
    cout << "Total Value: Rs" << fixed << setprecision(2) << getTotalValue() << endl;
    cout << "Condition: " << condition << endl;
    cout << "Location: " << location << endl;
    cout << "Expiration Date: " << expirationDate << endl;
    cout << "Status: " << (isExpired() ? "EXPIRED" : "VALID") << endl;
    cout << "Min Stock Level: " << minStockLevel << endl;
    cout << "Stock Status: " << (isLowOnStock() ? "LOW STOCK" : "ADEQUATE") << endl;
    cout << "Supplier: " << supplier << endl;
    cout << "Created: " << getDateCreated() << endl;
    cout << "Last Modified: " << getLastModified() << endl;
    cout << "==============================\n" << endl;
}

// Save to file
void Supplies::saveToFile(const string& filename) const {
    cout << "Saving supplies to " << filename << endl;
}

// Load from file
void Supplies::loadFromFile(const string& filename) {
    cout << "Loading supplies from " << filename << endl;
}

// Set supply type
void Supplies::setSupplyType(const string& type) {
    supplyType = type;
    updateLastModified();
    logActivity("Supply type updated to: " + type);
}

// Set expiration date
void Supplies::setExpirationDate(const string& date) {
    if (!Utils::isValidDate(date)) {
        throw ValidationException("Invalid date format (use YYYY-MM-DD)");
    }
    expirationDate = date;
    updateLastModified();
    logActivity("Expiration date updated to: " + date);
}

// Set minimum stock level
void Supplies::setMinStockLevel(int level) {
    if (level < 0) {
        throw ValidationException("Minimum stock level cannot be negative");
    }
    minStockLevel = level;
    updateLastModified();
    logActivity("Minimum stock level updated to: " + to_string(level));
}

// Set supplier
void Supplies::setSupplier(const string& supp) {
    supplier = supp;
    updateLastModified();
    logActivity("Supplier updated to: " + supp);
}

string Supplies::getSupplyType() const {
    return supplyType;
}

string Supplies::getExpirationDate() const {
    return expirationDate;
}

int Supplies::getMinStockLevel() const {
    return minStockLevel;
}

string Supplies::getSupplier() const {
    return supplier;
}

// Check if expired
bool Supplies::isExpired() const {
    // Simplified: compare with current date
    string currentDate = Utils::getCurrentDate();
    return expirationDate < currentDate;
}

// Check if low on stock
bool Supplies::isLowOnStock() const {
    return quantity < minStockLevel;
}

// Consume supply
void Supplies::consumeSupply(int amount) {
    if (amount < 0) {
        throw ValidationException("Cannot consume negative amount");
    }
    if (isExpired()) {
        throw ValidationException("Cannot consume expired supplies");
    }
    if (amount > quantity) {
        throw InsufficientSupplyException(name, amount, quantity);
    }
    
    quantity -= amount;
    
    if (isLowOnStock()) {
        condition = "Low";
    }
    
    updateLastModified();
    logActivity("Consumed " + to_string(amount) + " units. Remaining: " + to_string(quantity));
}

// Replenish supply
void Supplies::replenishSupply(int amount) {
    if (amount < 0) {
        throw ValidationException("Cannot replenish negative amount");
    }
    
    quantity += amount;
    condition = "Available";
    updateLastModified();
    logActivity("Replenished " + to_string(amount) + " units. Total: " + to_string(quantity));
}

string Supplies::getEntityType() const {
    return "Supplies";
}

string Supplies::getEquipmentType() const {
    return supplyType;
}

// Operator< for comparison by expiration date
bool Supplies::operator<(const Supplies& other) const {
    return expirationDate < other.expirationDate;
}

// Operator== for comparison
bool Supplies::operator==(const Supplies& other) const {
    return BaseEntity::operator==(other);
}

