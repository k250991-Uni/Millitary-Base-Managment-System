# Military Base Management System - Libraries & Functions Reference

## 📚 Standard C++ Libraries Used

### 1. **iostream** - Input/Output Operations
- **Purpose**: Console input (cin) and output (cout)
- **Usage in Project**: Menu display, user input, data output
- **Example**:
```cpp
cout << "Enter officer name: ";
cin >> name;
```

### 2. **iomanip** - Input/Output Manipulation
- **Purpose**: Format output (fixed decimals, setprecision)
- **Usage in Project**: Display monetary values and formatted reports
- **Example**:
```cpp
cout << fixed << setprecision(2) << price;  // Shows 99.99 not 99.9999
```

### 3. **vector** - Dynamic Arrays
- **Purpose**: Store collections of objects dynamically
- **Usage in Project**: Store officers, contractors, weapons, supplies, operations
- **Example**:
```cpp
vector<Officer*> officers;  // List of all officers
officers.push_back(new Officer(...));  // Add officer
```

### 4. **string** - Text/String Handling
- **Purpose**: Store and manipulate text
- **Usage in Project**: Names, IDs, descriptions, dates
- **Example**:
```cpp
string name = "John Smith";
string rank = "Captain";
```

### 5. **ctime** - Date/Time Functions
- **Purpose**: Get current date and time
- **Usage in Project**: Timestamp records, audit logs
- **Example**:
```cpp
time_t now = time(0);  // Current time
localtime(&now);       // Convert to readable format
```

### 6. **cctype** - Character Classification
- **Purpose**: Check if character is digit, letter, etc.
- **Usage in Project**: Input validation
- **Example**:
```cpp
if (isdigit(input[i])) { ... }  // Check if character is 0-9
```

### 7. **algorithm** - Standard Algorithms
- **Purpose**: Transform sequences (like uppercase/lowercase conversion)
- **Usage in Project**: String transformations
- **Example**:
```cpp
transform(result.begin(), result.end(), result.begin(), ::toupper);
```

### 8. **sstream** - String Stream (String parsing)
- **Purpose**: Convert between strings and numbers
- **Usage in Project**: Input validation, data parsing
- **Example**:
```cpp
stringstream ss(input);
int number;
ss >> number;  // Convert "123" to 123
```

### 9. **fstream** - File Input/Output
- **Purpose**: Read/write files
- **Usage in Project**: Audit log file operations, data persistence
- **Example**:
```cpp
fstream file("audit.log", ios::app);  // Open file to append
file << "New log entry\n";
file.close();
```

### 10. **cmath** - Mathematical Functions
- **Purpose**: Math operations (pow, sqrt, round)
- **Usage in Project**: Rounding values, calculations
- **Example**:
```cpp
double rounded = floor(value * 100) / 100;  // Round to 2 decimals
```

### 11. **cstdlib** - Standard Library
- **Purpose**: General utilities (rand, exit, system)
- **Usage in Project**: Random numbers, system calls
- **Example**:
```cpp
int randNum = rand() % 100;  // Random 0-99
```

---

## 🛠️ Custom Utility Functions (Utils Class)

### ✅ **ACTUALLY USED** - Keep These:

#### 1. **printHeader(title)**
- **Purpose**: Display formatted menu headers
- **Usage**: Every menu display
- **Example**:
```cpp
Utils::printHeader("PERSONNEL MANAGEMENT");
// Output: ============================================================
//          PERSONNEL MANAGEMENT
//         ============================================================
```

#### 2. **clearScreen()**
- **Purpose**: Clear console screen
- **Usage**: Between menu transitions
- **Example**:
```cpp
Utils::clearScreen();  // Clears screen for next menu
```

#### 3. **pauseExecution(message)**
- **Purpose**: Wait for user before continuing
- **Usage**: After displaying information
- **Example**:
```cpp
Utils::pauseExecution("Press Enter to continue...");
```

#### 4. **getCurrentDateTime()**
- **Purpose**: Get current date and time as string
- **Usage**: Timestamps for audit logs, record creation
- **Example**:
```cpp
string timestamp = Utils::getCurrentDateTime();
// Returns: "2026-04-24 10:30:45"
```

#### 5. **getCurrentDate()**
- **Purpose**: Get today's date as string
- **Usage**: Date-specific operations
- **Example**:
```cpp
string today = Utils::getCurrentDate();
// Returns: "2026-04-24"
```

#### 6. **isValidRank(rank)**
- **Purpose**: Check if military rank is valid
- **Usage**: Personnel creation and validation
- **Example**:
```cpp
if (Utils::isValidRank("Captain")) { ... }  // Valid
if (Utils::isValidRank("SuperSoldier")) { ... }  // Invalid
```

#### 7. **isValidServiceNumber(sNumber)**
- **Purpose**: Check if service number format is correct
- **Usage**: Personnel registration
- **Example**:
```cpp
if (Utils::isValidServiceNumber("SN123456")) { ... }
```

#### 8. **toLowerCase(str)**
- **Purpose**: Convert string to lowercase
- **Usage**: Case-insensitive comparisons
- **Example**:
```cpp
if (Utils::toLowerCase(input) == Utils::toLowerCase(expected)) { ... }
```

#### 9. **createString(length, character)**
- **Purpose**: Create repeated character string
- **Usage**: Display separators and lines
- **Example**:
```cpp
Utils::createString(60, '-');  // Returns "----...----" (60 times)
```

---

### ❌ **NOT USED** - Can Remove:

These functions are defined but **never called** in the project:

1. **trim(str)** - Remove whitespace from string
2. **toUpperCase(str)** - Convert to uppercase
3. **startsWith(str, prefix)** - Check string prefix
4. **endsWith(str, suffix)** - Check string suffix
5. **isValidInteger(input)** - Validate integer input
6. **isValidDouble(input)** - Validate decimal input
7. **isValidDate(date)** - Validate date format
8. **roundToNearest(value)** - Round to whole number
9. **roundToDecimals(value, decimals)** - Round to N decimals
10. **getRandomInt(min, max)** - Generate random number
11. **printLine(length)** - Print separator line
12. **printSeparator()** - Another separator function
13. **fileExists(filename)** - Check if file exists
14. **createEmptyFile(filename)** - Create empty file
15. **deleteFile(filename)** - Delete file
16. **isValidWeaponCondition(condition)** - Validate weapon condition

---

## 🎯 Core Custom Classes & Their Purpose

### 1. **BaseEntity** (include/core/BaseEntity.h)
- **Purpose**: Base class for all entities
- **Key Members**: ID, name, dateCreated, lastModified
- **Key Methods**: getID(), getName(), getDateCreated()
- **Usage**: All personnel, weapons, supplies, operations inherit from this

### 2. **Person** (include/personnel/Person.h)
- **Purpose**: Base class for military personnel
- **Key Members**: rank, serviceNumber, department
- **Child Classes**: Officer, Contractor
- **Usage**: Store and manage all military personnel

### 3. **Officer** (include/personnel/Officer.h)
- **Purpose**: Military officers
- **Key Members**: rank, specialization, yearsOfService
- **Usage**: Officers who manage base operations

### 4. **Contractor** (include/personnel/Contractor.h)
- **Purpose**: Civilian contractors
- **Key Members**: companyName, contractEndDate
- **Usage**: Non-military staff

### 5. **Equipment** (include/logistics/Equipment.h)
- **Purpose**: Base class for all equipment
- **Child Classes**: Weapon, Supplies
- **Key Methods**: display(), validateCondition()
- **Usage**: Inventory management

### 6. **Weapon** (include/logistics/Weapon.h)
- **Purpose**: Military weapons
- **Key Members**: type, caliber, ammunition, magazineCapacity
- **Usage**: Track weapons inventory and status

### 7. **Supplies** (include/logistics/Supplies.h)
- **Purpose**: Military supplies/inventory
- **Key Members**: type, expirationDate, minStockLevel, supplier
- **Usage**: Track consumable supplies and food

### 8. **Operation** (include/operations/Operation.h)
- **Purpose**: Military operations/missions
- **Key Members**: name, type, status, startDate, endDate
- **Usage**: Record and manage military operations

### 9. **AuditLog** (include/core/AuditLog.h)
- **Purpose**: Record all system activities
- **Key Methods**: addEntry(), displayAllEntries(), searchByEntityID()
- **Usage**: Track who did what and when

### 10. **MenuSystem** (include/core/MenuSystem.h)
- **Purpose**: Main user interface
- **Key Methods**: run(), handleMainMenu(), displayPersonnelMenu()
- **Usage**: Interactive menu for all operations

### 11. **CustomExceptions** (include/utilities/CustomExceptions.h)
- **Purpose**: Custom error handling
- **Exception Types**: 
  - MilitaryException (base)
  - PersonnelException
  - LogisticsException
  - OperationException
  - ValidationException
  - FileException
- **Usage**: Throw specific errors for different situations

---

## 📊 Data Flow Example

```
User starts program
    ↓
System initializes (creates AuditLog)
    ↓
Main Menu displayed
    ↓
User selects "Personnel Management"
    ↓
Personnel Menu displayed
    ↓
User adds new Officer
    ↓
Officer object created, added to officers vector
    ↓
AuditLog records: "Officer created: John Smith"
    ↓
Back to Personnel Menu
```

---

## 🔧 Summary: What to Keep vs. Remove

### Keep (Actually Used):
- ✅ printHeader, clearScreen, pauseExecution
- ✅ getCurrentDateTime, getCurrentDate
- ✅ isValidRank, isValidServiceNumber
- ✅ toLowerCase, createString
- ✅ All core classes (Person, Officer, Weapon, Supplies, etc.)

### Remove (Dead Code):
- ❌ trim, toUpperCase, startsWith, endsWith
- ❌ isValidInteger, isValidDouble, isValidDate
- ❌ roundToNearest, roundToDecimals, getRandomInt
- ❌ printLine, printSeparator
- ❌ fileExists, createEmptyFile, deleteFile
- ❌ isValidWeaponCondition

This will reduce code bloat and make the project cleaner!
