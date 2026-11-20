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



