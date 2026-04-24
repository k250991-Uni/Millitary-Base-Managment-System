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
string Utils::trim(const string& str) {
    size_t first = str.find_first_not_of(" \t\n\r");
    if (first == string::npos) return "";
    size_t last = str.find_last_not_of(" \t\n\r");
    return str.substr(first, last - first + 1);
}

string Utils::toUpperCase(const string& str) {
    string result = str;
    transform(result.begin(), result.end(), result.begin(), ::toupper);
    return result;
}

string Utils::toLowerCase(const string& str) {
    string result = str;
    transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}

bool Utils::startsWith(const string& str, const string& prefix) {
    return str.compare(0, prefix.length(), prefix) == 0;
}

bool Utils::endsWith(const string& str, const string& suffix) {
    if (str.length() < suffix.length()) return false;
    return str.compare(str.length() - suffix.length(), suffix.length(), suffix) == 0;
}

// Input validation
bool Utils::isValidInteger(const string& input) {
    if (input.empty()) return false;
    
    size_t start = (input[0] == '-') ? 1 : 0;
    for (size_t i = start; i < input.length(); ++i) {
        if (!isdigit(input[i])) return false;
    }
    return true;
}

bool Utils::isValidDouble(const string& input) {
    if (input.empty()) return false;
    
    try {
        size_t idx;
        stod(input, &idx);
        return idx == input.length();
    }
    catch (...) {
        return false;
    }
}

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

string Utils::getCurrentTime() {
    time_t now = time(0);
    struct tm* timeinfo = localtime(&now);
    char buffer[80];
    strftime(buffer, sizeof(buffer), "%H:%M:%S", timeinfo);
    return std::string(buffer);
}

// Numeric utilities
int Utils::roundToNearest(double value) {
    return static_cast<int>(round(value));
}

double Utils::roundToDecimals(double value, int decimals) {
    double multiplier = pow(10, decimals);
    return round(value * multiplier) / multiplier;
}

int Utils::getRandomInt(int min, int max) {
    return min + (rand() % (max - min + 1));
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

void Utils::printSeparator() {
    printLine(60);
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

// File utilities
bool Utils::fileExists(const string& filename) {
    ifstream file(filename);
    return file.good();
}

void Utils::createEmptyFile(const string& filename) {
    ofstream file(filename);
    file.close();
}

bool Utils::deleteFile(const string& filename) {
    return remove(filename.c_str()) == 0;
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

bool Utils::isValidWeaponCondition(const string& condition) {
    vector<string> validConditions = {"Serviceable", "Unserviceable", "Maintenance", "Locked"};
    
    for (const auto& cond : validConditions) {
        if (toLowerCase(condition) == toLowerCase(cond)) {
            return true;
        }
    }
    return false;
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
