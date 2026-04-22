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
    private:
    bool isRunning;
    //menu display func
    void displayMainMenu();
    void displayPersonnelMenu();
    void displayOperationMenu();
    void displayLogisticsMenu();
    void displayReportMenu();

    //personnel mangemnet 
    void addOfficer();
    void addContractor();
    void updtaePersonnel();
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
    void displayAllEquipement();
    void checkInventory();

    //operations mangamnet
    void createOperation();
    void updateOperationStatus();
    void deleteOperation();
    void siaplayAllOPeration();
    void assignPersonnelToOperation();

    //Report
    void generatePersonnelReport();
    void generateEquipmentReport();

    //get choice
    int getMainMenuChoice();
    int getPersonnelMenuChoice();
    int getLogisticsMenuChoice();
    int getOperationsMenuChoice();
    int getReportsMenuChoice();

    //Input 
    string getPeronnelID();
    string getEquipemtnID();
    string getOperationID();

    //save/load
    void savedAlData();
    void loadAllData();

    public:
    MenuSystem();
    ~MenuSystem();

    //main loop 
    void run();

    //handlers
    void handleMainMenu(int choice);
    void handlePersonnelMenu(int choice);
    void handleLogisticsMenu(int choice);
    void handleOperationMenu(int choice);
    void handleReportMenu(int choice);
    
   //setter / getter
   void setRunning(bool running){
    isRunning = running;
   }
   bool getRunning() const { return isRunning;}


};
#endif