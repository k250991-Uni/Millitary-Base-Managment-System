#include "utilities/Utils.h"
#include <iostream>
#include <cctype>
#include <algorithm>
#include <ctime>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <cmath>

using namespace std;

// String utilities
string Utils::toLowerCase(const string& str) {
    string result = str;
    transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}

// Input validation

bool Utils::isValidDate(const string& date) {
    // Format: YYYY-MM-DD
    if (date.length() != 10) return false;
    if (date[4] != '-' || date[7] != '-') return false;
    
    for (int i = 0; i < 10; i++) {
        if (i == 4 || i == 7) continue;
        if (!isdigit(date[i])) return false;
    }
    return true;
}

// Date/Time utilities
string Utils::getCurrentDateTime() {
    time_t now = time(0);
    struct tm* timeinfo = localtime(&now);
    char buffer[80];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", timeinfo);
    return std::string(buffer);
}

string Utils::getCurrentDate() {
    time_t now = time(0);
    struct tm* timeinfo = localtime(&now);
    char buffer[80];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d", timeinfo);
    return std::string(buffer);
}

// Display utilities
void Utils::printHeader(const string& title) {
    printLine(60);
    cout << " " << title << endl;
    printLine(60);
}

void Utils::printLine(int length) {
    for (int i = 0; i < length; ++i) cout << "=";
    cout << endl;
}

string Utils::createString(int length, char character) {
    return std::string(length, character);
}

void Utils::clearScreen() {
    #ifdef _WIN32
        system("cls"); //for windows
    #else
        system("clear");   // for mac
    #endif
}

void Utils::pauseExecution(const string& message) {
    cout << message;
    cin.ignore(10000, '\n');
}

// Military-specific validations
bool Utils::isValidRank(const string& rank) {
    vector<string> validRanks = {
        "Private", "Sergeant", "Lieutenant", "Captain",
        "Major", "Colonel", "General", "Civilian", "Contractor"
    };
    
    for (const auto& validRank : validRanks) {
        if (toLowerCase(rank) == toLowerCase(validRank)) {
            return true;
        }
    }
    return false;
}

bool Utils::isValidServiceNumber(const string& sNumber) {
    // Service number format: SN-XXXXX where X is digit
    if (sNumber.length() < 6) return false;
    return sNumber[0] == 'S' && sNumber[1] == 'N' && sNumber[2] == '-';
}

bool Utils::isValidOperationStatus(const string& status) {
    vector<string> validStatuses = {"Planned", "Active", "Completed", "On Hold"};
    
    for (const auto& s : validStatuses) {
        if (toLowerCase(status) == toLowerCase(s)) {
            return true;
        }
    }
    return false;
}

bool Utils::isValidSecurityClearance(const string& clearance) {
    vector<string> validClearances = {"Confidential", "Secret", "Top Secret"};
    
    for (const auto& clear : validClearances) {
        if (toLowerCase(clearance) == toLowerCase(clear)) {
            return true;
        }
    }
    return false;
}
