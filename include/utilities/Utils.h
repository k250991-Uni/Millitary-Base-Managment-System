#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <vector>
#include <ctime>
using namespace std;

// Utility functions for Military Base Management System
class Utils {
public:
    // String utilities
    static string toLowerCase(const string& str);
    
    // Input validation
    static bool isValidDate(const string& date);  // Format: YYYY-MM-DD
    
    // Date/Time utilities
    static string getCurrentDateTime();
    static string getCurrentDate();
    
    // Display utilities
    static void printHeader(const string& title);
    static void printLine(int length = 60);
    static std::string createString(int length, char character);
    static void clearScreen();
    static void pauseExecution(const string& message = "Press Enter to continue...");
    
    // Military-specific validations
    static bool isValidRank(const string& rank);
    static bool isValidServiceNumber(const string& sNumber);
    static bool isValidOperationStatus(const string& status);
    static bool isValidSecurityClearance(const string& clearance);
};

#endif
