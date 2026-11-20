# Semester Project Requirements (FURPS+)

## Functionality
1. FR-1 (Process Payments & Calculate Fees):
   The system shall allow users to process payments through supported methods (Bank Transfer and Digital Wallet) with a valid amount and calculate the transaction fee based on each method's percentage rate

2. FR-2 (Compare Student Marks):
   The system shall allow comparison of two students' marks using roll number and marks attributes and identify which student has obtained higher marks.

3. FR-3 (Calculate Assessment & Total Marks):
   The system shall record and display marks for assessment activities (Quiz and Assignment) and calculate the combined total marks across assessments.

------------------------------------------------------------------------------------------

#### Usability
1. UR-1 (Clear Prompts & Menus):
   A new user shall be able to select payment/assessment options, compare student marks, and view results in under 2 minutes without prior training

2. UR-2 (Readable Input Validation Errors):
   When invalid values are entered (such as negative amounts, invalid roll numbers, or negative marks), the system shall display a clear error message explaining what to re-enter instead of crashing

-----------------------------------------------------------------------------------------------

### Reliability
1. RL-1 (Accurate Fee & Marks Calculation):
   All transaction fees (2% for Bank Transfer, 1% for Digital Wallet) and total marks calculations shall produce consistent, accurate results across repeated runs.

2. RL-2 (Invalid State Prevention):
   The system shall prevent negative payment amounts or negative marks from being accepted as valid records.

-----------------------------------------------------------------------------------------------

## Performance
1. PF-1 (Response Time):
   Fee calculations, student comparisons, and total marks additions shall execute instantaneously (in under 1 second) on a standard desktop machine

2. PF-2 (Startup & Execution Time):
   The application shall compile, start, and display results in under 2 seconds

------------------------------------------------------------------------------------------

## Supportability
1. SP-1 (Modular OOP Structure):
   Each payment method, student record, assessment type, and marks accumulator shall be separated into distinct C++ classes so individual rules can be updated without breaking other components

2. SP-2 (Readable Error & Status Messages):
   Invalid inputs or edge cases (such as equal marks or zero/negative amounts) shall display clear status or error messages to aid testing and debugging

---------------------------------------------------------------------------------------------

## + (Additional Requirements)
1. Design (+DS):
   The system shall follow Object-Oriented design principles including encapsulation, inheritance, polymorphism, abstract base classes, and operator overloading (`>` and `+`)

2. Implementation (+IM):
   The project shall be implemented in standard C++ using clean naming conventions, private/protected access specifiers, parameterized constructors, and pure virtual functions where required

3. Interface (+IN):
   The application shall provide a clear console-based input/output interface with labeled prompts and formatted summary outputs

4. Physical (+PH):
   The application shall run on standard Windows/Linux PC hardware with a C++ compiler and at least 4 GB RAM

------------------------------------------------------------------------------------------

## Classes

### 1. Payment (Abstract Class)
. Role: Abstract base class defining the common interface for payment methods
. Role: Abstract base class defining the common interface for payment methods
. Member Functions:
  . `calculateFee()` *(pure virtual — from "calculate")
  . `getAmount()` *(from "get")

### 2. BankTransfer / DigitalWallet (Concrete Derived Classes)
.Role: Represent specific payment methods with their respective fee rates (`2%` and `1%`)
.Member Functions:
  . `calculateFee()` *(overrides base — from "calculate")
  . `displayFee()` *(from "display")

### 3. Student (Concrete Class)
.Role: Stores a student's `rollNo` and `marks` and supports comparison
.Member Functions:
  . `operator>()` *(from "compare / greater")
  . `displayInfo()` *(from "display")

### 4. Marks (Concrete Class)
.Role: Stores an assessment score `value` and supports combining marks
.Member Functions:
  . `operator+()` *(from "add")
  . `getValue()` *(from "get")