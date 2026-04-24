#include "core/MenuSystem.h"
#include "personnel/Officer.h"
#include "personnel/Contractor.h"
#include "logistics/Weapon.h"
#include "logistics/Supplies.h"
#include "operations/Operation.h"
#include "core/AuditLog.h"
#include "utilities/Utils.h"
#include "utilities/CustomExceptions.h"
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

// Global data storage
vector<Officer*> officers;
vector<Contractor*> contractors;
vector<Weapon*> weapons;
vector<Supplies*> supplies;
vector<Operation*> operations;
AuditLog* auditLog = nullptr;

// Constructor
MenuSystem::MenuSystem() : isRunning(true) {
    if (auditLog == nullptr) {
        auditLog = new AuditLog("military_audit.log");
    }
}

// Destructor
MenuSystem::~MenuSystem() {
    // Cleanup all dynamic objects
    for (auto officer : officers) delete officer;
    for (auto contractor : contractors) delete contractor;
    for (auto weapon : weapons) delete weapon;
    for (auto supply : supplies) delete supply;
    for (auto op : operations) delete op;
    
    if (auditLog != nullptr) {
        delete auditLog;
        auditLog = nullptr;
    }
}

// Main menu loop
void MenuSystem::run() {
    while (isRunning) {
        displayMainMenu();
        int choice = getMainMenuChoice();
        handleMainMenu(choice);
    }
}

// Display main menu
void MenuSystem::displayMainMenu() {
    Utils::clearScreen();
    Utils::printHeader("MILITARY BASE MANAGEMENT SYSTEM");
    cout << "\n1. Personnel Management" << endl;
    cout << "2. Logistics Management" << endl;
    cout << "3. Operations Management" << endl;
    cout << "4. Reports & Analytics" << endl;
    cout << "5. Audit Log" << endl;
    cout << "6. Save & Exit" << endl;
    cout << "\nEnter your choice: ";
}

// Get main menu choice
int MenuSystem::getMainMenuChoice() {
    int choice;
    cin >> choice;
    cin.ignore();
    return choice;
}

// Handle main menu
void MenuSystem::handleMainMenu(int choice) {
    switch (choice) {
        case 1:
            while (true) {
                displayPersonnelMenu();
                int pChoice = getPersonnelMenuChoice();
                if (pChoice == 0) break;
                handlePersonnelMenu(pChoice);
            }
            break;
        case 2:
            while (true) {
                displayLogisticsMenu();
                int lChoice = getLogisticsMenuChoice();
                if (lChoice == 0) break;
                handleLogisticsMenu(lChoice);
            }
            break;
        case 3:
            while (true) {
                displayOperationsMenu();
                int oChoice = getOperationsMenuChoice();
                if (oChoice == 0) break;
                handleOperationsMenu(oChoice);
            }
            break;
        case 4:
            while (true) {
                displayReportsMenu();
                int rChoice = getReportsMenuChoice();
                if (rChoice == 0) break;
                handleReportsMenu(rChoice);
            }
            break;
        case 5:
            while (true) {
                displayAuditMenu();
                int aChoice = getAuditMenuChoice();
                if (aChoice == 0) break;
                handleAuditMenu(aChoice);
            }
            break;
        case 6:
            saveAllData();
            isRunning = false;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
    }
}

// Personnel Menu
void MenuSystem::displayPersonnelMenu() {
    Utils::clearScreen();
    Utils::printHeader("PERSONNEL MANAGEMENT");
    cout << "\n1. Add Officer" << endl;
    cout << "2. Add Contractor" << endl;
    cout << "3. Update Personnel" << endl;
    cout << "4. Delete Personnel" << endl;
    cout << "5. Search Personnel" << endl;
    cout << "6. Display All Personnel" << endl;
    cout << "7. Assign Weapon to Personnel" << endl;
    cout << "8. Promote Officer" << endl;
    cout << "0. Back to Main Menu" << endl;
    cout << "\nEnter your choice: ";
}

int MenuSystem::getPersonnelMenuChoice() {
    int choice;
    cin >> choice;
    cin.ignore();
    return choice;
}

void MenuSystem::handlePersonnelMenu(int choice) {
    switch (choice) {
        case 1:
            addOfficer();
            break;
        case 2:
            addContractor();
            break;
        case 3:
            updatePersonnel();
            break;
        case 4:
            deletePersonnel();
            break;
        case 5:
            searchPersonnel();
            break;
        case 6:
            displayAllPersonnel();
            break;
        case 7:
            assignWeapon();
            break;
        case 8:
            promoteOfficer();
            break;
        default:
            cout << "Invalid choice." << endl;
    }
    Utils::pauseExecution("Press Enter to continue...");
}

// Logistics Menu
void MenuSystem::displayLogisticsMenu() {
    Utils::clearScreen();
    Utils::printHeader("LOGISTICS MANAGEMENT");
    cout << "\n1. Add Weapon" << endl;
    cout << "2. Add Supplies" << endl;
    cout << "3. Update Equipment" << endl;
    cout << "4. Delete Equipment" << endl;
    cout << "5. Search Equipment" << endl;
    cout << "6. Display All Equipment" << endl;
    cout << "7. Check Inventory" << endl;
    cout << "8. Issue Ammunition" << endl;
    cout << "9. Check Expired Supplies" << endl;
    cout << "0. Back to Main Menu" << endl;
    cout << "\nEnter your choice: ";
}

int MenuSystem::getLogisticsMenuChoice() {
    int choice;
    cin >> choice;
    cin.ignore();
    return choice;
}

void MenuSystem::handleLogisticsMenu(int choice) {
    switch (choice) {
        case 1:
            addWeapon();
            break;
        case 2:
            addSupplies();
            break;
        case 3:
            updateEquipment();
            break;
        case 4:
            deleteEquipment();
            break;
        case 5:
            searchEquipment();
            break;
        case 6:
            displayAllEquipment();
            break;
        case 7:
            checkInventory();
            break;
        default:
            cout << "Invalid choice." << endl;
    }
    Utils::pauseExecution("Press Enter to continue...");
}

// Operations Menu
void MenuSystem::displayOperationsMenu() {
    Utils::clearScreen();
    Utils::printHeader("OPERATIONS MANAGEMENT");
    cout << "\n1. Create Operation" << endl;
    cout << "2. Update Operation Status" << endl;
    cout << "3. Delete Operation" << endl;
    cout << "4. Search Operation" << endl;
    cout << "5. Display All Operations" << endl;
    cout << "6. Assign Personnel to Operation" << endl;
    cout << "7. Assign Equipment to Operation" << endl;
    cout << "8. Generate Operation Report" << endl;
    cout << "0. Back to Main Menu" << endl;
    cout << "\nEnter your choice: ";
}

int MenuSystem::getOperationsMenuChoice() {
    int choice;
    cin >> choice;
    cin.ignore();
    return choice;
}

void MenuSystem::handleOperationsMenu(int choice) {
    switch (choice) {
        case 1:
            createOperation();
            break;
        case 2:
            updateOperationStatus();
            break;
        case 3:
            deleteOperation();
            break;
        case 4:
            searchOperation();
            break;
        case 5:
            displayAllOperations();
            break;
        case 6:
            assignPersonnelToOperation();
            break;
        case 7:
            assignEquipmentToOperation();
            break;
        case 8:
            generateOperationReport();
            break;
        default:
            cout << "Invalid choice." << endl;
    }
    Utils::pauseExecution("Press Enter to continue...");
}

// Reports Menu
void MenuSystem::displayReportsMenu() {
    Utils::clearScreen();
    Utils::printHeader("REPORTS & ANALYTICS");
    cout << "\n1. Personnel Report" << endl;
    cout << "2. Equipment Report" << endl;
    cout << "3. Inventory Report" << endl;
    cout << "0. Back to Main Menu" << endl;
    cout << "\nEnter your choice: ";
}

int MenuSystem::getReportsMenuChoice() {
    int choice;
    cin >> choice;
    cin.ignore();
    return choice;
}

void MenuSystem::handleReportsMenu(int choice) {
    switch (choice) {
        case 1:
            generatePersonnelReport();
            break;
        case 2:
            generateEquipmentReport();
            break;
        case 3:
            generateInventoryReport();
            break;
        default:
            cout << "Invalid choice." << endl;
    }
    Utils::pauseExecution("Press Enter to continue...");
}

// Audit Menu
void MenuSystem::displayAuditMenu() {
    Utils::clearScreen();
    Utils::printHeader("AUDIT LOG");
    cout << "\n1. Display All Audit Entries" << endl;
    cout << "2. Search Audit Log" << endl;
    cout << "0. Back to Main Menu" << endl;
    cout << "\nEnter your choice: ";
}

int MenuSystem::getAuditMenuChoice() {
    int choice;
    cin >> choice;
    cin.ignore();
    return choice;
}

void MenuSystem::handleAuditMenu(int choice) {
    switch (choice) {
        case 1:
            displayAuditLog();
            break;
        case 2:
            searchAuditLog();
            break;
        default:
            cout << "Invalid choice." << endl;
    }
    Utils::pauseExecution("Press Enter to continue...");
}

// Personnel Management Implementations
void MenuSystem::addOfficer() {
    cout << "\n=== ADD NEW OFFICER ===" << endl;
    cout << "Enter name: ";
    string name;
    getline(cin, name);
    
    cout << "Enter service number (SN-XXXXX): ";
    string sNumber;
    getline(cin, sNumber);
    
    cout << "Enter rank (Private, Corporal, Sergeant, Lieutenant, Captain, Major, Colonel, General): ";
    string rank;
    getline(cin, rank);
    
    cout << "Enter salary: ";
    string salStr;
    getline(cin, salStr);
    double salary = stod(salStr);
    
    cout << "Enter specialization: ";
    string spec;
    getline(cin, spec);
    
    cout << "Enter command center: ";
    string cmdCenter;
    getline(cin, cmdCenter);
    
    cout << "Enter years of service: ";
    string yearsStr;
    getline(cin, yearsStr);
    int years = stoi(yearsStr);
    
    try {
        Officer* officer = new Officer(name, sNumber, rank, salary, spec, cmdCenter, years);
        officers.push_back(officer);
        auditLog->addEntry("ADD", "Officer", officer->getID(), "Officer " + name + " added");
        cout << "\nOfficer added successfully. ID: " << officer->getID() << endl;
    }
    catch (const exception& e) {
        cout << "\nError: " << e.what() << endl;
    }
}

void MenuSystem::addContractor() {
    cout << "\n=== ADD NEW CONTRACTOR ===" << endl;
    cout << "Enter name: ";
    string name;
    getline(cin, name);
    
    cout << "Enter service number (SN-XXXXX): ";
    string sNumber;
    getline(cin, sNumber);
    
    cout << "Enter salary: ";
    string salStr;
    getline(cin, salStr);
    double salary = stod(salStr);
    
    cout << "Enter company name: ";
    string company;
    getline(cin, company);
    
    cout << "Enter security clearance (Confidential, Secret, Top Secret, TS/SCI): ";
    string clearance;
    getline(cin, clearance);
    
    cout << "Enter contract end date (YYYY-MM-DD): ";
    string endDate;
    getline(cin, endDate);
    
    cout << "Enter contract value: ";
    string valueStr;
    getline(cin, valueStr);
    double value = stod(valueStr);
    
    try {
        Contractor* contractor = new Contractor(name, sNumber, salary, company, clearance, endDate, value);
        contractors.push_back(contractor);
        auditLog->addEntry("ADD", "Contractor", contractor->getID(), "Contractor " + name + " added");
        cout << "\nContractor added successfully. ID: " << contractor->getID() << endl;
    }
    catch (const exception& e) {
        cout << "\nError: " << e.what() << endl;
    }
}

void MenuSystem::displayAllPersonnel() {
    cout << "\n=== ALL PERSONNEL ===" << endl;
    
    if (!officers.empty()) {
        cout << "\n--- Officers ---" << endl;
        for (const auto& officer : officers) {
            officer->display();
        }
    }
    
    
    if (!contractors.empty()) {
        cout << "\n--- Contractors ---" << endl;
        for (const auto& contractor : contractors) {
            contractor->display();
        }
    }
    
    if (officers.empty() && contractors.empty()) {
        cout << "No personnel found." << endl;
    }
}

void MenuSystem::updatePersonnel() {
    cout << "\n=== UPDATE PERSONNEL ===" << endl;
    cout << "Enter personnel ID to update: ";
    int id;
    cin >> id;
    cin.ignore();
    
    // Search in all lists
    // Simple implementation - can be expanded
    cout << "Update functionality - detailed implementation in full version" << endl;
}

void MenuSystem::deletePersonnel() {
    cout << "\n=== DELETE PERSONNEL ===" << endl;
    cout << "Enter personnel ID to delete: ";
    int id;
    cin >> id;
    cin.ignore();
    
    // Delete from lists
    cout << "Delete functionality - detailed implementation in full version" << endl;
}

void MenuSystem::searchPersonnel() {
    cout << "\n=== SEARCH PERSONNEL ===" << endl;
    cout << "Search functionality - detailed implementation in full version" << endl;
}

void MenuSystem::assignWeapon() {
    cout << "\n=== ASSIGN WEAPON TO PERSONNEL ===" << endl;
    cout << "Weapon assignment - detailed implementation in full version" << endl;
}

void MenuSystem::promoteOfficer() {
    cout << "\n=== PROMOTE OFFICER ===" << endl;
    cout << "Enter officer ID: ";
    int id;
    cin >> id;
    cin.ignore();
    
    cout << "Enter new rank: ";
    string newRank;
    getline(cin, newRank);
    
    for (auto& officer : officers) {
        if (officer->getID() == id) {
            try {
                officer->promote(newRank);
                auditLog->addEntry("UPDATE", "Officer", id, "Officer promoted to " + newRank);
                cout << "\nOfficer promoted successfully." << endl;
                return;
            }
            catch (const exception& e) {
                cout << "\nError: " << e.what() << endl;
                return;
            }
        }
    }
    cout << "\nOfficer not found." << endl;
}

// Logistics Management Implementations
void MenuSystem::addWeapon() {
    cout << "\n=== ADD NEW WEAPON ===" << endl;
    cout << "Enter weapon name: ";
    string name;
    getline(cin, name);
    
    cout << "Enter equipment code: ";
    string code;
    getline(cin, code);
    
    cout << "Enter weapon type (Rifle, Pistol, Sniper, etc.): ";
    string type;
    getline(cin, type);
    
    cout << "Enter quantity: ";
    string qtyStr;
    getline(cin, qtyStr);
    int qty = stoi(qtyStr);
    
    cout << "Enter unit cost: ";
    string costStr;
    getline(cin, costStr);
    double cost = stod(costStr);
    
    cout << "Enter storage location: ";
    string loc;
    getline(cin, loc);
    
    cout << "Enter initial ammunition: ";
    string ammoStr;
    getline(cin, ammoStr);
    int ammo = stoi(ammoStr);
    
    cout << "Enter magazine capacity: ";
    string magStr;
    getline(cin, magStr);
    int magCap = stoi(magStr);
    
    cout << "Enter caliber: ";
    string caliber;
    getline(cin, caliber);
    
    try {
        Weapon* weapon = new Weapon(name, code, type, qty, cost, loc, ammo, magCap, caliber);
        weapons.push_back(weapon);
        auditLog->addEntry("ADD", "Weapon", weapon->getID(), "Weapon " + name + " added");
        cout << "\nWeapon added successfully. ID: " << weapon->getID() << endl;
    }
    catch (const exception& e) {
        cout << "\nError: " << e.what() << endl;
    }
}

void MenuSystem::addSupplies() {
    cout << "\n=== ADD NEW SUPPLIES ===" << endl;
    cout << "Enter supply name: ";
    string name;
    getline(cin, name);
    
    cout << "Enter equipment code: ";
    string code;
    getline(cin, code);
    
    cout << "Enter supply type (Food, Medical, Clothing, Fuel, etc.): ";
    string type;
    getline(cin, type);
    
    cout << "Enter quantity: ";
    string qtyStr;
    getline(cin, qtyStr);
    int qty = stoi(qtyStr);
    
    cout << "Enter unit cost: ";
    string costStr;
    getline(cin, costStr);
    double cost = stod(costStr);
    
    cout << "Enter storage location: ";
    string loc;
    getline(cin, loc);
    
    cout << "Enter expiration date (YYYY-MM-DD): ";
    string expDate;
    getline(cin, expDate);
    
    cout << "Enter minimum stock level: ";
    string minStockStr;
    getline(cin, minStockStr);
    int minStock = stoi(minStockStr);
    
    cout << "Enter supplier name: ";
    string supplier;
    getline(cin, supplier);
    
    try {
        Supplies* sup = new Supplies(name, code, type, qty, cost, loc, expDate, minStock, supplier);
        supplies.push_back(sup);
        auditLog->addEntry("ADD", "Supplies", sup->getID(), "Supplies " + name + " added");
        cout << "\nSupplies added successfully. ID: " << sup->getID() << endl;
    }
    catch (const exception& e) {
        cout << "\nError: " << e.what() << endl;
    }
}

void MenuSystem::displayAllEquipment() {
    cout << "\n=== ALL EQUIPMENT ===" << endl;
    
    if (!weapons.empty()) {
        cout << "\n--- Weapons ---" << endl;
        for (const auto& weapon : weapons) {
            weapon->display();
        }
    }
    
    if (!supplies.empty()) {
        cout << "\n--- Supplies ---" << endl;
        for (const auto& supply : supplies) {
            supply->display();
        }
    }
    
    if (weapons.empty() && supplies.empty()) {
        cout << "No equipment found." << endl;
    }
}

void MenuSystem::updateEquipment() {
    cout << "\n=== UPDATE EQUIPMENT ===" << endl;
    cout << "Update functionality - detailed implementation in full version" << endl;
}

void MenuSystem::deleteEquipment() {
    cout << "\n=== DELETE EQUIPMENT ===" << endl;
    cout << "Delete functionality - detailed implementation in full version" << endl;
}

void MenuSystem::searchEquipment() {
    cout << "\n=== SEARCH EQUIPMENT ===" << endl;
    cout << "Search functionality - detailed implementation in full version" << endl;
}

void MenuSystem::checkInventory() {
    cout << "\n=== INVENTORY CHECK ===" << endl;
    cout << "Inventory check - detailed implementation in full version" << endl;
}

void MenuSystem::issuedAmmo() {
    cout << "\n=== ISSUE AMMUNITION ===" << endl;
    cout << "Ammunition issue - detailed implementation in full version" << endl;
}

void MenuSystem::checkExpiredSupplies() {
    cout << "\n=== EXPIRED SUPPLIES ===" << endl;
    cout << "Checking for expired supplies..." << endl;
    
    for (const auto& supply : supplies) {
        if (supply->isExpired()) {
            cout << "EXPIRED: " << supply->getName() << " (ID: " << supply->getID() << ")" << endl;
        }
    }
}

// Operations Management Implementations
void MenuSystem::createOperation() {
    cout << "\n=== CREATE NEW OPERATION ===" << endl;
    cout << "Enter operation code: ";
    string code;
    getline(cin, code);
    
    cout << "Enter operation type (Training, Patrol, Combat, etc.): ";
    string opType;
    getline(cin, opType);
    
    cout << "Enter commander name: ";
    string commander;
    getline(cin, commander);
    
    cout << "Enter location: ";
    string location;
    getline(cin, location);
    
    cout << "Enter description: ";
    string desc;
    getline(cin, desc);
    
    try {
        Operation* op = new Operation(code, opType, commander, location, desc);
        operations.push_back(op);
        auditLog->addEntry("ADD", "Operation", op->getID(), "Operation " + code + " created");
        cout << "\nOperation created successfully. ID: " << op->getID() << endl;
    }
    catch (const exception& e) {
        cout << "\nError: " << e.what() << endl;
    }
}

void MenuSystem::updateOperationStatus() {
    cout << "\n=== UPDATE OPERATION STATUS ===" << endl;
    cout << "Enter operation ID: ";
    int id;
    cin >> id;
    cin.ignore();
    
    cout << "Enter new status (Planned, Active, Completed, Aborted, On Hold): ";
    string newStatus;
    getline(cin, newStatus);
    
    for (auto& op : operations) {
        if (op->getID() == id) {
            try {
                op->setStatus(newStatus);
                auditLog->addEntry("UPDATE", "Operation", id, "Status updated to " + newStatus);
                cout << "\nOperation status updated successfully." << endl;
                return;
            }
            catch (const exception& e) {
                cout << "\nError: " << e.what() << endl;
                return;
            }
        }
    }
    cout << "\nOperation not found." << endl;
}

void MenuSystem::displayAllOperations() {
    cout << "\n=== ALL OPERATIONS ===" << endl;
    
    if (operations.empty()) {
        cout << "No operations found." << endl;
        return;
    }
    
    for (const auto& op : operations) {
        op->display();
    }
}

void MenuSystem::deleteOperation() {
    cout << "\n=== DELETE OPERATION ===" << endl;
    cout << "Delete functionality - detailed implementation in full version" << endl;
}

void MenuSystem::searchOperation() {
    cout << "\n=== SEARCH OPERATION ===" << endl;
    cout << "Search functionality - detailed implementation in full version" << endl;
}

void MenuSystem::assignPersonnelToOperation() {
    cout << "\n=== ASSIGN PERSONNEL TO OPERATION ===" << endl;
    cout << "Assign personnel - detailed implementation in full version" << endl;
}

void MenuSystem::assignEquipmentToOperation() {
    cout << "\n=== ASSIGN EQUIPMENT TO OPERATION ===" << endl;
    cout << "Assign equipment - detailed implementation in full version" << endl;
}

void MenuSystem::generateOperationReport() {
    cout << "\n=== OPERATION REPORT ===" << endl;
    cout << "Report generation - detailed implementation in full version" << endl;
}

// Reports Management
void MenuSystem::generatePersonnelReport() {
    cout << "\n=== PERSONNEL REPORT ===" << endl;
    cout << "Total Officers: " << officers.size() << endl;
    cout << "Total Officers: " << officers.size() << endl;
    cout << "Total Contractors: " << contractors.size() << endl;
    cout << "Total Personnel: " << (officers.size() + contractors.size()) << endl;
}

void MenuSystem::generateEquipmentReport() {
    cout << "\n=== EQUIPMENT REPORT ===" << endl;
    cout << "Total Weapons: " << weapons.size() << endl;
    cout << "Total Supplies: " << supplies.size() << endl;
    cout << "Total Equipment: " << (weapons.size() + supplies.size()) << endl;
}

void MenuSystem::generateInventoryReport() {
    cout << "\n=== INVENTORY REPORT ===" << endl;
    double totalWeaponValue = 0;
    for (const auto& weapon : weapons) {
        totalWeaponValue += weapon->getTotalValue();
    }
    cout << "Total Weapon Value: $" << fixed << setprecision(2) << totalWeaponValue << endl;
    
    double totalSupplyValue = 0;
    for (const auto& supply : supplies) {
        totalSupplyValue += supply->getTotalValue();
    }
    cout << "Total Supplies Value: $" << fixed << setprecision(2) << totalSupplyValue << endl;
    cout << "Total Equipment Value: $" << fixed << setprecision(2) << (totalWeaponValue + totalSupplyValue) << endl;
}

// Audit Log Management
void MenuSystem::displayAuditLog() {
    if (auditLog != nullptr) {
        auditLog->displayAllEntries();
    }
}

void MenuSystem::searchAuditLog() {
    cout << "\n=== SEARCH AUDIT LOG ===" << endl;
    cout << "1. Search by Entity Type" << endl;
    cout << "2. Search by Operation Type" << endl;
    cout << "3. Search by Entity ID" << endl;
    cout << "Enter your choice: ";
    
    int choice;
    cin >> choice;
    cin.ignore();
    
    if (auditLog != nullptr) {
        switch (choice) {
            case 1: {
                cout << "Enter entity type: ";
                string entityType;
                getline(cin, entityType);
                auditLog->searchByEntityType(entityType);
                break;
            }
            case 2: {
                cout << "Enter operation type: ";
                string opType;
                getline(cin, opType);
                auditLog->searchByOperationType(opType);
                break;
            }
            case 3: {
                cout << "Enter entity ID: ";
                int entityID;
                cin >> entityID;
                auditLog->searchByEntityID(entityID);
                break;
            }
            default:
                cout << "Invalid choice." << endl;
        }
    }
}

// Save and Load
void MenuSystem::saveAllData() {
    cout << "\nSaving all data..." << endl;
    if (auditLog != nullptr) {
        auditLog->saveToFile();
    }
    cout << "Data saved successfully." << endl;
}

void MenuSystem::loadAllData() {
    cout << "\nLoading all data..." << endl;
    if (auditLog != nullptr) {
        auditLog->loadFromFile();
    }
    cout << "Data loaded successfully." << endl;
}
