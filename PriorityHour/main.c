#include <stdio.h>
#include "Patient.h"
#include "Date.h"
int main() {
    printf("Team Leade Csillag Alex!\n");


    Patient* patient=readPatientFromFile("patients.txt");
    for(int i=0;i<PATIENT_COUNT;i++){
        printPatient(&patient[i]); //Done
    }
    return 0;
}
