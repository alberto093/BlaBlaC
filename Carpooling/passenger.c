//
//  passenger.c
//  Carpooling
//
//  Created by Alberto Saltarelli on 29/10/2019.
//  Copyright © 2019 Alberto Saltarelli. All rights reserved.
//

#include "passenger.h"
#include <string.h>

int load_passengers(passenger passengers[], int count) {
    FILE *rstream = fopen("/Users/Alberto/Università/Informatica/I anno/Laboratorio di Informatica/BlaBlaC/Carpooling/passengers.dat", "rb");
    if (rstream == NULL) {
        return 0;
    }
    
    fread(passengers, sizeof(passenger) * count, 1, rstream);
    int total_passengers = (int)ftell(rstream) / sizeof(passenger);
    fclose(rstream);
    return total_passengers;
}

passenger create_passenger(void) {
    passenger new_passenger;
    printf("\nInserisci il nome: ");
    scanf("%s", new_passenger.name);
    printf("Inserisci il cognome: ");
    scanf("%s", new_passenger.surname);
    printf("Inserisci età: ");
    scanf("%hd", &new_passenger.age);
    printf("Inserisci il codice fiscale: ");
    scanf("%s", new_passenger.code);
    printf("Inserisci una breve biografia: ");
    scanf("%s", new_passenger.description);
    printf("\n");
    return new_passenger;
}

void edit_passenger(passenger *edit_passenger) {
    printf("\nIl nome è %s, inserisci il nuovo nome: ", (*edit_passenger).name);
    scanf("%s", (*edit_passenger).name);
    printf("\nIl cognome è %s, inserisci il nuovo cognome: ", (*edit_passenger).surname);
    scanf("%s", (*edit_passenger).surname);
    printf("\nL'età è %hd, inserisci la nuova età: ", (*edit_passenger).age);
    scanf("%hd", &(*edit_passenger).age);
    printf("La biografia è %s, inserisci la nuova biografia: ", (*edit_passenger).description);
    scanf("%s", (*edit_passenger).description);
}

int remove_passenger(passenger *remove_passenger, passenger passengers[], int *count) {
    int end = *count;
    int found = 0;
    for (int i=0; i<end; i++) {
        if (!strcmp((*remove_passenger).code, passengers[i].code) && !found) {
            end--;
            found = 1;
        }
        if (found) {
            passengers[i] = passengers[i+1];
        }
    }
    if (found) {
        (*count)--;
    }
    return found;
}

passenger *find_passenger(passenger passengers[], int count) {
    hash_code passenger_code;
    passenger *actual_passenger = NULL;
    printf("\nInserisci il codice fiscale del conducente: ");
    scanf("%s", passenger_code);
    actual_passenger = existing_passenger(passenger_code, passengers, count);
    if (!actual_passenger) {
        printf("Conducente non trovato!");
    }
    return actual_passenger;
}

passenger *existing_passenger(hash_code passenger_code, passenger passengers[], int count) {
    for (int i=0; i<count; i++) {
        if (!strcmp(passengers[i].code, passenger_code)) {
            return &passengers[i];
        }
    }
    return NULL;
}

int contains_passenger(passenger* new_passenger, passenger passengers[], int count) {
    return existing_passenger((*new_passenger).code, passengers, count) != NULL;
}

int save_passengers(passenger passengers[], int count) {
    FILE *wstream = fopen("/Users/Alberto/Università/Informatica/I anno/Laboratorio di Informatica/BlaBlaC/Carpooling/passengers.dat", "wb");
    if (wstream == NULL) {
        return 0;
    }
    
    fwrite(passengers, sizeof(passenger) * count, 1, wstream);
    return !fclose(wstream);
}
