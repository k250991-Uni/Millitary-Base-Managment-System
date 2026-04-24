#ifndef MENU_SYSTEM_H
#define MENU_SYSTEM_H

#include <string>
#include <vector>
using namespace std;

//forward declaration
class Officer;
class Contractor;
class Weapon;
class Supplies;
class Operation;

class MenuSystem{
    public:
    MenuSystem();
    ~MenuSystem();
    void run();
    void setRunning(bool running){ isRunning = running; }
    bool getRunning() const { return isRunning;}
    
    private:
    bool isRunning;
    //menu display func
    void displayMainMenu();
    void displayPersonnelMenu();
    void displayLogisticsMenu();
    void displayOperationsMenu();
    void displayReportsMenu();

    //personnel management 
    void addOfficer();
    void addContractor();
    void deletePersonnel();
    void displayAllPersonnel();
    void promoteOfficer();

    //logistics management
    void addWeapon();
    void addSupplies();
    void deleteEquipment();
    void displayAllEquipment();

    //operations management
    void createOperation();
    void deleteOperation();
    void displayAllOperations();

    //Report
    void generatePersonnelReport();
    void generateEquipmentReport();

    //audit menu
    void displayAuditMenu();
    int getAuditMenuChoice();
    void handleAuditMenu(int choice);
    void viewAllAuditEntries();
    void searchAuditByEntityType();
    void searchAuditByOperationType();
    void searchAuditByEntityID();

    //get choice
    int getMainMenuChoice();
    int getPersonnelMenuChoice();
    int getLogisticsMenuChoice();
    int getOperationsMenuChoice();
    int getReportsMenuChoice();

    //save/load
    void saveAllData();
    void loadAllData();

    //handlers
    void handleMainMenu(int choice);
    void handlePersonnelMenu(int choice);
    void handleLogisticsMenu(int choice);
    void handleOperationsMenu(int choice);
    void handleReportsMenu(int choice);
};
#endif