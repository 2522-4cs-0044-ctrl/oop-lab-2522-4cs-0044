# Semester Project Requirements (FURPS+)

## Functionality
1. FR-1 (Add & Manage Records):

The system shall allow a user to add a new record with a unique ID, title/name, and valid numeric attributes, and display a confirmation message upon saving

2. FR-2 (Search & Filter):

The system shall allow a user to search records by ID or keyword and return matching entries within the same session

3. FR-3 (Calculate Totals & Status):

The system shall calculate total charges, fines, or balances accurately based on item rules and update status (e.g., active, paid, returned).
-------------------------------------------------------------------------------------------
#### Usability
1. UR-1 (Clear Prompts & Menus):

A new user shall be able to navigate the main menu and complete a standard workflow (add, view, search) in under 2 minutes without prior training.

2. UR-2 (Readable Input Validation Errors):

When invalid input is entered (such as a negative amount or empty ID), the system shall display a clear error message explaining what to re-enter instead of crashing.
-------------------------------------------------------------------------------------------------
### Reliability
1. RL-1 (Data Persistence):

 All saved records shall persist across program restarts when loaded from and saved to the storage file

 
2. RL-2 (Invalid State Prevention):

The system shall prevent duplicate IDs and negative quantities/amounts from being committed to active records

xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx


## Performance
1.PF-1 (Response Time):
Search and display operations on up to 1,000 records shall complete in under 1 second on a standard desktop machine


2.PF-2 (Startup & Load Time):
The application shall start and load existing records in under 2 seconds

-----------------------------------------------------------------------------------------

## Supportability
1.SP-1 (Modular OOP Structure):
Each entity and manager component shall be separated into well-defined classes/headers so individual modules can be updated without breaking unrelated features

2.SP-2 (Readable Logging & Diagnostics):
 File read/write errors and invalid operation attempts shall be reported with clear context messages to aid debugging

------------------------------------------------------------------------------------------------

## + (Additional Requirements)
1.Design (+DS):
The system shall follow Object-Oriented design principles including encapsulation, inheritance, polymorphism, and an abstract base class for shared behavior

2.Implementation (+IM):
The project shall be implemented in standard C++ using clean naming conventions, access specifiers, and destructors where needed.

3.Interface (+IN):
The application shall provide a text-based console menu interface (or well-defined CLI prompts/output) with clear labels and formatted summaries.

4.Physical (+PH):
The application shall run on standard Windows/Linux PC hardware with at least 4 GB RAM and store data locally on disk.

