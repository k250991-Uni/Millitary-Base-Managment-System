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
    static string trim(const string& str);
    static string toUpperCase(const string& str);
    static string toLowerCase(const string& str);
    static bool startsWith(const string& str, const string& prefix);
    static bool endsWith(const string& str, const string& suffix);
    
    // Input validation
    static bool isValidInteger(const string& input);
    static bool isValidDouble(const string& input);
    static bool isValidDate(const string& date);  // Format: YYYY-MM-DD
    
    // Date/Time utilities
    static string getCurrentDateTime();
    static string getCurrentDate();
    static string getCurrentTime();
    
    // Numeric utilities
    static int roundToNearest(double value);
    static double roundToDecimals(double value, int decimals);
    static int getRandomInt(int min, int max);
    
    // Display utilities
    static void printHeader(const string& title);
    static void printLine(int length = 60);
    static std::string createString(int length, char character);
    static void printSeparator();
    static void clearScreen();
    static void pauseExecution(const string& message = "Press Enter to continue...");
    
    // File utilities
    static bool fileExists(const string& filename);
    static void createEmptyFile(const string& filename);
    static bool deleteFile(const string& filename);
    
    // Military-specific validations
    static bool isValidRank(const string& rank);
    static bool isValidServiceNumber(const string& sNumber);
    static bool isValidWeaponCondition(const string& condition);
    static bool isValidOperationStatus(const string& status);
    static bool isValidSecurityClearance(const string& clearance);
};

#endif
