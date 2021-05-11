#ifndef PRIORITYHOUR_PATIENT_H
#define PRIORITYHOUR_PATIENT_H

#include "../enums.h"
#include "../Date/Date.h"

/// Definition of the Patient structure
typedef struct {
    char ID[7];
    char firstName[30];
    char lastName[30];

    enum Sex sex;
    enum Nationality nationality;

    Date birthDate;

    char symptoms[50];
} Patient;

/// Allocate a Patient in memory
Patient *createPatent(char* ID,
                      char* fistName,
                      char* lastName,
                      enum Sex sex,
                      enum Nationality nationality,
                      Date* birthDate,
                      char* symptoms);

/// Read Patients from file
Patient *readPatientFromFile(char *fileName);

/// Return a Patient by a given ID
Patient *findPatientById(char* ID);

/// Add a Patient
void addPatient();

/// Print a given Patient to the standard output
void printPatient(Patient *patient);

/// Print all Patients to the standard output
void printAllPatients();

/// Deallocates a Patient from memory
void killPatient(Patient* patient);

#endif //PRIORITYHOUR_PATIENT_H
