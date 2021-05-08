#ifndef PRIORITYHOUR_PATIENT_H
#define PRIORITYHOUR_PATIENT_H

#include "../enums.h"
#include "../Date/Date.h"

typedef struct {
    char ID[7];
    char firstName[30];
    char lastName[30];

    enum Sex sex;
    enum Nationality nationality;

    Date birthDate;

    char symptoms[50];
} Patient;

Patient *createPatent(char* ID,
                      char* fistName,
                      char* lastName,
                      enum Sex sex,
                      enum Nationality nationality,
                      Date* birthDate,
                      char* symptoms);

Patient *readPatientFromFile(char *fileName);

Patient *findPatientById(char* ID);

void addPatient();

void printPatient(Patient *patient);

void printAllPatients();

void killPatient(Patient* patient);

#endif //PRIORITYHOUR_PATIENT_H
