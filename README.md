# Priority Hour

<<<<<<< Updated upstream
Contributors


---Team Leader---


  Csillag Alex
  
  
----Employes---- 


  Csata Levente
  
  
  Miklós Nándor
  
  
  :)))
=======
# Notes

## Roles

- Csata L. Levente
	- Patient
	- Date
- Csillag Alex
	- Menu
	- BST
	
- Miklós Nándor
	- Input files (.txt)
		- Patients (30)
			- [(Random Person Generator)](https://www.fakenamegenerator.com/gen-random-gr-gr.php)
			- ID (string)
			- First Name (string)
			- Last  Name (string)
			- Sex (enum)
			- Birt Date (Date)
				- Year (int)
				- Month (int)
				- Day (int)
			- Nationality
			- Symptoms (string, split by "_")
			- Example:
				- GER001 Eric Schweitzer 1 1986 12 12 3 Headache_Nausea_Hard_of_Hearing

## Menu System

## Data structures

### Patient struct
- Patient ID (string)
- First Name (string)
- Last Name (string)
- Sex
- Nationality (enum)
- Birt Date (Date struct) \[(year, month, day) integer\]
- Short description of symptoms (string)

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
>>>>>>> Stashed changes
