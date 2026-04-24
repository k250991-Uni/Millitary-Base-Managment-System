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
    void displayOperationMenu();
    void displayLogisticsMenu();
    void displayReportMenu();
    void displayOperationsMenu();
    void displayReportsMenu();
    void displayAuditMenu();

    //personnel mangemnet 
    void addOfficer();
    void addContractor();
    void updatePersonnel();
    void deletePersonnel();
    void searchPersonnel();
    void displayAllPersonnel();
    void assignWeapon();
    void promoteOfficer();

    //logistics management
    void addWeapon();
    void addSupplies();
    void updateEquipment();
    void deleteEquipment();
    void searchEquipment();
    void displayAllEquipment();
    void checkInventory();

    //operations mangamnet
    void createOperation();
    void updateOperationStatus();
    void deleteOperation();
    void displayAllOperation();
    void searchOperation();
    void assignPersonnelToOperation();
    void assignEquipmentToOperation();
    void generateOperationReport();

    //Report
    void generatePersonnelReport();
    void generateEquipmentReport();
    void generateInventoryReport();

    //get choice
    int getMainMenuChoice();
    int getPersonnelMenuChoice();
    int getLogisticsMenuChoice();
    int getOperationsMenuChoice();
    int getReportsMenuChoice();
    int getAuditMenuChoice();

    //Input 
    string getPersonnelID();
    string getEquipmentID();
    string getOperationID();

    //save/load
    void saveAllData();
    void loadAllData();

    //handlers
    void handleMainMenu(int choice);
    void handlePersonnelMenu(int choice);
    void handleLogisticsMenu(int choice);
    void handleOperationMenu(int choice);
    void handleReportMenu(int choice);
    void handleOperationsMenu(int choice);
    void handleReportsMenu(int choice);
    void handleAuditMenu(int choice);
    void displayAuditLog();
    void searchAuditLog();
    void displayAllOperations();
    void issuedAmmo();
    void checkExpiredSupplies();
};
#endif