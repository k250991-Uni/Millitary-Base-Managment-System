#include "logistics/Equipment.h"
#include "utilities/Utils.h"
#include "utilities/CustomExceptions.h"
#include <iostream>
#include <iomanip>

using namespace std;

// Constructor
Equipment::Equipment(const string& name, const string& code, int qty, double cost, const string& loc)
    : BaseEntity(name), equipmentCode(code), quantity(qty), unitCost(cost), location(loc) {
    condition = "Serviceable";
    lastServiceDate = Utils::getCurrentDate();
    
    if (qty < 0) {
        throw ValidationException("Quantity cannot be negative");
    }
    
    if (cost < 0) {
        throw ValidationException("Unit cost cannot be negative");
    }
}

// Destructor
Equipment::~Equipment() {
}

// Set condition
void Equipment::setCondition(const string& cond) {
    if (!validateCondition(cond)) {
        throw ValidationException("Invalid equipment condition: " + cond);
    }
    condition = cond;
    updateLastModified();
    logActivity("Condition updated to: " + cond);
}

// Set location
void Equipment::setLocation(const string& loc) {
    location = loc;
    updateLastModified();
    logActivity("Location updated to: " + loc);
}

// Update last service date
void Equipment::updateLastServiceDate() {
    lastServiceDate = Utils::getCurrentDate();
    updateLastModified();
    logActivity("Service date updated");
}

// Add stock
void Equipment::addStock(int amount) {
    if (amount < 0) {
        throw ValidationException("Cannot add negative stock");
    }
    quantity += amount;
    updateLastModified();
    logActivity("Added " + to_string(amount) + " units. Total: " + to_string(quantity));
}

// Remove stock
void Equipment::removeStock(int amount) {
    if (amount < 0) {
        throw ValidationException("Cannot remove negative stock");
    }
    if (amount > quantity) {
        throw InsufficientSupplyException(name, amount, quantity);
    }
    quantity -= amount;
    updateLastModified();
    logActivity("Removed " + to_string(amount) + " units. Total: " + to_string(quantity));
}

// Check adequate stock
bool Equipment::hasAdequateStock(int required) const {
    return quantity >= required;
}

// Operator< for comparison by total value
bool Equipment::operator<(const Equipment& other) const {
    return getTotalValue() < other.getTotalValue();
}

// Operator== for comparison
bool Equipment::operator==(const Equipment& other) const {
    return BaseEntity::operator==(other);
}

// Getter methods
std::string Equipment::getEquipmentCode() const {
    return equipmentCode;
}

int Equipment::getQuantity() const {
    return quantity;
}

double Equipment::getUnitCost() const {
    return unitCost;
}

double Equipment::getTotalValue() const {
    return quantity * unitCost;
}

std::string Equipment::getCondition() const {
    return condition;
}

std::string Equipment::getLastServiceDate() const {
    return lastServiceDate;
}

std::string Equipment::getLocation() const {
    return location;
}

// Stream output operator
ostream& operator<<(ostream& out, const Equipment& equipment) {
    out << "Code: " << equipment.equipmentCode
        << " | Qty: " << equipment.quantity
        << " | Unit Cost: $" << fixed << setprecision(2) << equipment.unitCost
        << " | Total Value: $" << fixed << setprecision(2) << equipment.getTotalValue()
        << " | Condition: " << equipment.condition
        << " | Location: " << equipment.location;
    return out;
}
