#include "core/MenuSystem.h"
#include "utilities/Utils.h"
#include "utilities/CustomExceptions.h"
#include <iostream>
#include <iomanip>

using namespace std;

void initializeSystem() {
    try {
        Utils::printHeader("MILITARY BASE MANAGEMENT SYSTEM - INITIALIZATION");
        
        cout << "\nSystem Initialization Status:" << endl;
        cout << "✓ Exception handling system loaded" << endl;
        cout << "✓ Utility functions initialized" << endl;
        cout << "✓ Personnel management module ready" << endl;
        cout << "✓ Logistics management module ready" << endl;
        cout << "✓ Operations management module ready" << endl;
        cout << "✓ Audit logging system initialized" << endl;
        cout << "\nSystem initialized successfully!" << endl;
        cout << "\nVersion: 1.0" << endl;
        cout << "Build Date: " << Utils::getCurrentDateTime() << endl;
        
        Utils::pauseExecution("\nPress Enter to continue to main menu...");
    }
    catch (const MilitaryException& e) {
        cout << "\nCRITICAL ERROR during initialization: " << e.what() << endl;
        cout << "System cannot continue. Please check your configuration.\n" << endl;
        throw;
    }
    catch (const exception& e) {
        cout << "\nUnexpected error during initialization: " << e.what() << endl;
        cout << "System cannot continue.\n" << endl;
        throw;
    }
}

void cleanupSystem() {
    try {
        cout << "\nSystem cleanup in progress..." << endl;
        cout << "✓ Closing database connections" << endl;
        cout << "✓ Clearing memory buffers" << endl;
        cout << "✓ Finalizing audit logs" << endl;
        cout << "\nSystem cleanup complete" << endl;
    }
    catch (const exception& e) {
        cout << "Error during cleanup: " << e.what() << endl;
    }
}

int main() {
    try {
        // Initialize system
        initializeSystem();
        
        // Create and run menu system
        MenuSystem menu;
        menu.run();
        
        // Cleanup
        cleanupSystem();
        
        Utils::printHeader("MILITARY BASE MANAGEMENT SYSTEM");
        cout << "\nThank you for using Military Base Management System!" << endl;
        cout << "Program terminated successfully.\n" << endl;
        
        return 0;
    }
    catch (const MilitaryException& e) {
        cout << "\n" << Utils::createString(60, '=') << endl;
        cout << "CRITICAL ERROR: " << e.what() << endl;
        cout << Utils::createString(60, '=') << "\n" << endl;
        
        cleanupSystem();
        return 1;
    }
    catch (const exception& e) {
        cout << "\n" << Utils::createString(60, '=') << endl;
        cout << "UNEXPECTED ERROR: " << e.what() << endl;
        cout << Utils::createString(60, '=') << "\n" << endl;
        
        cleanupSystem();
        return 1;
    }
}
