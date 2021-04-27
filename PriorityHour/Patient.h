//
// Created by Legion on 4/27/2021.
//

#ifndef PRIORITYHOUR_PATIENT_H
#define PRIORITYHOUR_PATIENT_H


#include "enums.h"
#include "Date.h"
#include "Utility.h"

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
                      Date birthDate,
                      char* symptoms);

Patient *readPatientFromFile(char *fileName);

void printPatient(Patient *patient);

void killPatient(Patient* patient);

#endif //PRIORITYHOUR_PATIENT_H
