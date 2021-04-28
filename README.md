# Priority Hour

# Notes

## Roles

- Csata L. Levente
	- Patient
		- Print all patients (void printAllPatients)
	- Date
	
- Csillag Alex
	- Menu
	- BST
		- Delete reservation from BST
	- Reservation
		- Get date from standard input (keyboard)
	
- Miklós Nándor
	- Input files (.txt) (COMPLETED)
		- Patients (30)
			- [Random Person Generator](https://www.fakenamegenerator.com/gen-random-gr-gr.php)
			- ID (string)
			- First Name (string)
			- Last  Name (string)
			- Sex (enum)
			- Nationality
			- Birt Date (Date)
				- Year (int)
				- Month (int)
				- Day (int)
			- Symptoms (string, split by "_")
			- Example:
				- GER001 Eric Schweitzer 0 3 1986 12 12 Headache_Nausea_Hard_of_Hearing

## Menu System

## Data structures

### BinarySearchTree struct 

- Reservation (Reservation)
- Left (BST)
- Right (BST)

### Patient struct

- Patient ID (string)
- First Name (string)
- Last Name (string)
- Sex
- Nationality (enum)
- Birt Date (Date struct) \[(year, month, day) integer\]
- Short description of symptoms (string)

### Reservation  struct

- PatientID (string)
- ScheduledDate (Date)

### Date struct

- Year (integer) (1900 -> 2020)
- Month (integer) (1 -> 12)
- Day (integer) (1 -> 31)
- Hour (integer) (1 -> 24)
- Minute (integer) (0 -> 60)

### Binary Search Tree (Node) struct

- Patient (Patient)
- Left (Node) -> NULL
- Right (Node) -> NULL

### Nationality

- HUNGARIAN -> 0
- ROMANIAN -> 1
- GERMAN -> 2
- FRENCH -> 3
- AMERICAN -> 4
- BRITISH -> 5
- DANISH -> 6
- ICELANDIC -> 7
- IRISH -> 8
- SWEDISH -> 9
