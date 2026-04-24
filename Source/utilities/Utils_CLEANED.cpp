#include "utilities/Utils.h"
#include <iostream>
#include <cctype>
#include <algorithm>
#include <ctime>
#include <cstdlib>

using namespace std;

// ============ Screen Display Functions ============

void Utils::printHeader(const string& title) {
    cout << "\n" << createString(60, '=') << "\n";
    cout << "  " << title << "\n";
    cout << createString(60, '=') << "\n\n";
}

void Utils::clearScreen() {
    system("clear");  // Mac/Linux
    // For Windows: system("cls");
}

void Utils::pauseExecution(const string& message) {
    cout << "\n" << message;
    cin.ignore();
    cin.get();
}

// ============ Date/Time Functions ============

string Utils::getCurrentDateTime() {
    time_t now = time(0);
    struct tm* timeinfo = localtime(&now);
    char buffer[80];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", timeinfo);
    return string(buffer);
}

string Utils::getCurrentDate() {
    time_t now = time(0);
    struct tm* timeinfo = localtime(&now);
    char buffer[80];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d", timeinfo);
    return string(buffer);
}

// ============ Validation Functions ============

bool Utils::isValidRank(const string& rank) {
    // Valid military ranks
    const string validRanks[] = {
        "Private", "Corporal", "Sergeant", "Lieutenant", 
        "Captain", "Major", "Colonel", "General"
    };
    
    for (const auto& validRank : validRanks) {
        if (rank == validRank) return true;
    }
    return false;
}

bool Utils::isValidServiceNumber(const string& sNumber) {
    // Service number format: SN followed by 6 digits
    if (sNumber.length() != 8) return false;
    if (sNumber[0] != 'S' || sNumber[1] != 'N') return false;
    
    for (int i = 2; i < 8; i++) {
        if (!isdigit(sNumber[i])) return false;
    }
    return true;
}

// ============ String Functions ============

string Utils::toLowerCase(const string& str) {
    string result = str;
    transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}

string Utils::createString(int length, char ch) {
    return string(length, ch);
}
