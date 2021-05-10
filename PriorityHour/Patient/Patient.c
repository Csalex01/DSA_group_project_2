#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../Utility/Utility.h"

Patient *createPatent(char *ID,
                      char *fistName,
                      char *lastName,
                      enum Sex sex,
                      enum Nationality nationality,
                      Date *birthDate,
                      char *symptoms) {

    Patient *patient = (Patient *) malloc(sizeof(Patient));

    if (!patient) {
        printf("Failed to allocate memory for Patient");
        return NULL;
    }

    strcpy(patient->ID, ID);
    strcpy(patient->firstName, fistName);
    strcpy(patient->lastName, lastName);
    patient->sex = sex;
    patient->nationality = nationality;
    patient->birthDate = *birthDate;
    strcpy(patient->symptoms, symptoms);

    return patient;
}

Patient *readPatientFromFile(char *fileName) {

    FILE *fin = fopen(fileName, "rt");

    if (!fin) {
        printf("Could not open file %s", fileName);
        return NULL;
    }

    int n;
    fscanf(fin, "%i", &n);

    PATIENT_COUNT = n;

    Patient *patient = (Patient *) calloc(n, sizeof(Patient));

    if (!patient) {
        printf("Failed to allocate temporary vector for patients!");
        fclose(fin);
        return NULL;
    }

    char ID[7];
    char firstName[30];
    char lastName[30];
    char symptoms[50];

    int year, month, day;
    Date *birthDate;

    enum Sex sex;
    enum Nationality nationality;

    for (int i = 0; i < n; i++) {
        fscanf(fin, "%s", ID);
        fscanf(fin, "%s", firstName);
        fscanf(fin, "%s", lastName);

        fscanf(fin, "%i", &sex);
        fscanf(fin, "%i", &nationality);

        fscanf(fin, "%i", &year);
        fscanf(fin, "%i", &month);
        fscanf(fin, "%i", &day);

        fscanf(fin, "%s", symptoms);

        birthDate = createDate(year, month, day, 0, 0);

        patient[i] = *createPatent(ID, firstName, lastName, sex, nationality, birthDate, symptoms);
    }

    fclose(fin);

    return patient;
}

Patient *findPatientById(char *ID) {
    for (int i = 0; i < PATIENT_COUNT; i++)
        if (!strcmp(PATIENTS[i].ID, ID))
            return &PATIENTS[i];
    return NULL;
}

void addPatient() {
    char ID[7];
    char firstName[30];
    char lastName[30];

    enum Sex sex;
    enum Nationality nationality;

    Date birthDate;
    int year, month, day, hour, minute;

    char symptoms[50];

    printf("Patient ID (7 characters):");
    scanf("%s", ID);
    printf("\n");

    printf("First Name (max. 30 characters): ");
    scanf("%s", firstName);
    printf("\n");

    printf("Last Name (max. 30 characters): ");
    scanf("%s", lastName);
    printf("\n");

    printf("Sex (0 - FEMALE, 1 - MALE): ");
    scanf("%i", &sex);
    printf("\n");

    printf("HUNGARIAN - 0\n");
    printf("ROMANIAN - 1\n");
    printf("GERMAN - 2\n");
    printf("FRENCH - 3\n");
    printf("AMERICAN - 4\n");
    printf("BRITISH - 5\n");
    printf("DANISH - 6\n");
    printf("ICELANDIC - 7\n");
    printf("IRISH - 8\n");
    printf("SWEDISH - 9\n");
    printf("----------\nNationality: ");
    scanf("%i", &nationality);
    printf("\n");


    printf("Birth date (YYYY MM DD hh mm): ");
    scanf("%i %i %i %i %i", &year, &month, &day, &hour, &minute);
    printf("\n");

    printf("Symptoms (use \"_\" instead of spaces, max. 50 characters: ");
    scanf("%s", symptoms);

    Patient *patient = createPatent(ID,
                                    firstName,
                                    lastName,
                                    sex,
                                    nationality,
                                    createDate(year, month, day, hour, minute),
                                    symptoms
    );

    PATIENT_COUNT++;
    PATIENTS = (Patient*)realloc(PATIENTS, PATIENT_COUNT);
    PATIENTS[PATIENT_COUNT - 1] = *patient;
}

void printPatient(Patient *patient) {
    if(!patient)
        return;

    printf("ID: %s\n", patient->ID);
    printf("\tName: \t\t%s %s\n", patient->firstName, patient->lastName);
    printf("\tBirth date: \t%i-%i-%i\n",
           patient->birthDate.year,
           patient->birthDate.month,
           patient->birthDate.day);
    printf("\tNationality: \t%i (", patient->nationality);

    switch (patient->nationality) {
        case HUNGARIAN:
            printf("HUNGARIAN");
            break;
        case ROMANIAN:
            printf("ROMANIAN");
            break;
        case GERMAN:
            printf("GERMAN");
            break;
        case FRENCH:
            printf("FRENCH");
            break;
        case AMERICAN:
            printf("AMERICAN");
            break;
        case BRITISH:
            printf("BRITISH");
            break;
        case DANISH:
            printf("DANISH");
            break;
        case ICELANDIC:
            printf("ICELANDIC");
            break;
        case IRISH:
            printf("IRISH");
            break;
        case SWEDISH:
            printf("SWEDISH");
            break;
        default:
            printf("UNKNOWN");
    }

    printf(")\n");
    printf("\tSymptoms: \t%s\n\n", patient->symptoms);
}

void printAllPatients() {
    for (int i = 0; i < PATIENT_COUNT; i++) {
        printPatient(&PATIENTS[i]);
    }
}

void killPatient(Patient *patient) {
    free(patient);
    patient = NULL;
}