# Military Base Management System
**Course:** Object-Oriented Programming (CS2001) Lab Semester Project

##  Group Members
* **Muhammad Anas** (ID: 25K-0899)
* **Abdullah Moin** (ID: 25K-0991)
* **Syed Alyan Hussain** (ID: 25K-0648)

##  Project Folder Structure 
```text
Project/
├── Readme.md
├── test_input_full.txt
├── test_output_full.txt
├── include/
│   ├── core/
│   │   ├── AuditLog.h
│   │   ├── BaseEntity.h
│   │   ├── ILoggable.h
│   │   └── MenuSystem.h
│   ├── logistics/
│   │   ├── Equipment.h
│   │   ├── Supplies.h
│   │   └── Weapon.h
│   ├── operations/
│   │   └── Operation.h
│   ├── personnel/
│   │   ├── Contractor.h
│   │   ├── Officer.h
│   │   └── Person.h
│   └── utilities/
│       ├── CustomExceptions.h
│       └── Utils.h
└── Source/
    ├── core/
    │   ├── AuditLog.cpp
    │   ├── BaseEntity.cpp
    │   └── MenuSystem.cpp
    ├── logistics/
    │   ├── Equipment.cpp
    │   ├── Supplies.cpp
    │   └── Weapon.cpp
    ├── main/
    │   └── main.cpp
    ├── operations/
    │   └── Operation.cpp
    ├── personnel/
    │   ├── Contractor.cpp
    │   ├── Officer.cpp
    │   └── Person.cpp
    └── utilities/
        └── Utils.cpp
```

---

##  Project Description
The Military Base Management System is a comprehensive C++ application designed to manage the core logistical and personnel operations of a military installation. Built using advanced Object-Oriented Programming principles, the system provides a centralized platform for tracking personnel (Officers and Contractors), managing high-security inventory (Weapons and Supplies), and coordinating complex military operations.

The system emphasizes data integrity through a robust **Audit Log** that records every administrative action, and ensures system stability through custom **Exception Handling** and strict **Input Validation**.

---

##  Use Cases

### 1. Personnel Registration and Management
- **Primary Actor:** Base Administrator
- **Goal:** Add, update, search, display, promote, and remove personnel records.
- **Preconditions:** System is running and user is in Personnel Management menu.
- **Main Flow:**
    1. Add Officer or Contractor with validated data.
    2. Search by ID or name to retrieve records.
    3. Update details such as salary, rank, and position.
    4. Promote officers based on command decisions.
    5. Delete personnel when records are no longer active.
- **Validation/Rules:**
    - Service number format must match expected pattern.
    - Rank and salary are validated through business rules.
    - Empty and invalid input is rejected with custom exceptions.
- **Postconditions:** Personnel data updated and audit entries recorded.

### 2. Weapon and Supplies Lifecycle Management
- **Primary Actor:** Logistics Officer
- **Goal:** Maintain inventory of weapons and supplies with safe stock operations.
- **Preconditions:** User is in Logistics Management menu.
- **Main Flow:**
    1. Add weapon and supplies records with quantity, cost, and metadata.
    2. Update ammunition, perform maintenance, and issue ammunition.
    3. Replenish or consume supplies according to operational needs.
    4. Check inventory value and search equipment by ID.
    5. Detect expired supplies and report low-stock risk.
- **Validation/Rules:**
    - Quantity, ammunition, stock levels, and costs cannot be invalid.
    - Supply expiration dates must follow YYYY-MM-DD format.
    - Stock operations enforce available balance constraints.
- **Postconditions:** Inventory state is consistent and auditable.

### 3. Operation Planning and Execution Tracking
- **Primary Actor:** Operations Commander
- **Goal:** Create operations, assign resources, and monitor mission status.
- **Preconditions:** User is in Operations Management menu.
- **Main Flow:**
    1. Create operation with code, type, commander, location, and description.
    2. Assign personnel and required equipment.
    3. Update operation status through allowed lifecycle states.
    4. Search operations by ID, code, type, or status.
    5. Generate operation-level report and status breakdown.
- **Validation/Rules:**
    - Operation status must be one of the valid predefined values.
    - Assignments require existing personnel/equipment records.
    - Invalid IDs or empty fields are blocked.
- **Postconditions:** Operation records reflect current planning/execution state.

### 4. Strategic Reporting and Analytics
- **Primary Actor:** Command Leadership
- **Goal:** Obtain summarized visibility into personnel, equipment, and operations.
- **Preconditions:** Sufficient data exists in system collections.
- **Main Flow:**
    1. Generate personnel report with totals and salary impact.
    2. Generate equipment report with category counts and value totals.
    3. Generate operation report with status distribution.
    4. Export reports to text files for review and documentation.
- **Validation/Rules:**
    - Reports gracefully handle empty datasets.
    - Currency and totals are formatted for readability.
- **Postconditions:** Decision-ready summaries are available in console and files.

### 5. Security Auditing and Traceability
- **Primary Actor:** Compliance/Security Officer
- **Goal:** Track system activity for accountability and forensic review.
- **Preconditions:** Audit log subsystem is initialized.
- **Main Flow:**
    1. Capture add/update/delete/assign/unassign operations.
    2. View complete audit history.
    3. Filter by entity type, operation type, or entity ID.
    4. Persist and reload audit records across sessions.
- **Validation/Rules:**
    - Every significant state-changing action should produce an audit entry.
    - Search filters are validated for safe retrieval.
- **Postconditions:** Transparent, searchable history of critical actions is maintained.

### 6. Data Persistence Across Sessions
- **Primary Actor:** System/User (on startup and exit)
- **Goal:** Preserve system continuity between program executions.
- **Preconditions:** File access permissions are available.
- **Main Flow:**
    1. Load persisted state at startup.
    2. Keep in-memory collections synchronized during runtime.
    3. Save all data and logs on controlled exit.
- **Validation/Rules:**
    - File read/write errors are handled using custom exceptions.
    - Save/load calls are centralized to reduce inconsistency.
- **Postconditions:** Data loss risk is minimized and continuity is preserved.

---

##  Core OOP Concepts Applied
* **Encapsulation:** All data members (e.g., `salary`, `quantity`) are protected/private, accessible only through controlled getter and setter methods.
* **Inheritance:** Utilizes a multi-level hierarchy where `Officer` and `Contractor` inherit from `Person`, and `Weapon` and `Supplies` inherit from `Equipment`—all deriving from a central `BaseEntity`.
* **Polymorphism:** Implements function overriding and virtual functions for `display()` and `getEntityType()` to handle diverse objects through base pointers.
* **Abstraction:** Employs abstract classes (e.g., `BaseEntity`, `Person`) and interfaces (`ILoggable`) to define essential behaviors without exposing implementation details.

---

##  Instructions to Run (Dev-C++)
To run this project in Dev-C++, follow these steps to ensure the modular files are linked correctly:

1.  **Create a Project:** Go to `File > New > Project...`
2.  **Select Console Application:** Choose `C++ Project`, name it `MilitaryManagement`, and click OK.
3.  **Add Files:** Right-click the project folder in the left sidebar, select **"Add to Project"**, and select all `.cpp` and `.h` files from the `include` and `Source` directories.
4.  **Configure Compiler:** Go to `Tools > Compiler Options`. Check the box "Add the following commands when calling the compiler" and enter `-std=c++11` (or higher).
5.  **Build and Run:** Press `F11` to compile and run the system.

---

##  Instructions to Run (VS Code)
1.  **Prerequisite:** Ensure the `C/C++` and `C++ Runner` extensions are installed.
2.  **Open Folder:** Open the project root directory in VS Code.
3.  **Compilation:** Since this project uses a modular structure, compile using the following command in the terminal:
    ```bash
    g++ -I include Source/core/*.cpp Source/logistics/*.cpp Source/personnel/*.cpp Source/operations/*.cpp Source/utilities/*.cpp Source/main/main.cpp -o MilitarySystem
    ```
4.  **Execution:** Run the generated file:
    ```bash
    ./MilitarySystem
    ```

---

## Assumptions & Limitations
* **Date Format:** The system expects dates in the `YYYY-MM-DD` format for validation.
* **Persistence:** Data is saved to `.txt` or `.log` files in the execution directory; ensure the program has write permissions.
* **Memory:** The system uses dynamic memory; ensure "Save & Exit" is used to trigger proper destructor cleanup.
