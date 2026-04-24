#ifndef UTILS_H
#define UTILS_H

#include <string>
using namespace std;

// Simple utility functions for Military Base Management System
// Only essential functions that are actually used
class Utils {
public:
    // Screen display functions
    static void printHeader(const string& title);      // Show menu header with lines
    static void clearScreen();                         // Clear console
    static void pauseExecution(const string& message); // Wait for user input
    
    // Date/Time - simple and commonly needed
    static string getCurrentDateTime();  // "2026-04-24 10:30:45"
    static string getCurrentDate();      // "2026-04-24"
    
    // Validation - military specific
    static bool isValidRank(const string& rank);              // Check rank (Captain, Major, etc)
    static bool isValidServiceNumber(const string& sNumber);  // Check service number format
    
    // String operations - basic
    static string toLowerCase(const string& str);  // Convert "ABC" to "abc"
    static string createString(int length, char ch); // Create "---" of length N
};

#endif
