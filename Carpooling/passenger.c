//
//  passenger.c
//  Carpooling
//
//  Created by Alberto Saltarelli on 29/10/2019.
//  Copyright © 2019 Alberto Saltarelli. All rights reserved.
//

#include "passenger.h"
#include "utils.h"
#include <string.h>

int is_same_passenger(passenger *lhs, passenger *rhs);

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
    fgets(new_passenger.name, 25, stdin);
    printf("Inserisci il cognome: ");
    fgets(new_passenger.surname, 25, stdin);
    printf("Inserisci età: ");
    scanf("%2hd", &new_passenger.age);
    printf("Inserisci il codice fiscale: ");
    scanf("%16s", new_passenger.code);
    printf("Inserisci una breve biografia: ");
    fgets(new_passenger.description, 250, stdin);
    printf("\n");
    return new_passenger;
}

void edit_passenger(passenger *edit_passenger) {
    int selection = 0;
    do {
        int is_valid_selection = 0;
        do {
            printf("\n• Premi 1 per modificare il nome\n");
            printf("\n• Premi 2 per modificare il cognome\n");
            printf("\n• Premi 3 per modificare l'età\n");
            printf("\n• Premi 4 per modificare la biografia\n");
            printf("\n• Premi 5 per annullare\n\n");
            scanf("%1i", &selection);
            is_valid_selection = is_included(selection, 1, 5);
            if (!is_valid_selection) {
                printf("\nScelta non valida\n\n");
            }
        } while (!is_valid_selection);
        
        switch (selection) {
            case 1: {
                printf("\nIl nome è %s, inserisci il nuovo nome: ", (*edit_passenger).name);
                fgets((*edit_passenger).name, 25, stdin);
                break;
            }
            case 2: {
                printf("\nIl cognome è %s, inserisci il nuovo cognome: ", (*edit_passenger).surname);
                fgets((*edit_passenger).surname, 25, stdin);
                break;
            }
            case 3: {
                printf("\nL'età è %hd, inserisci la nuova età: ", (*edit_passenger).age);
                scanf("%2hd", &(*edit_passenger).age);
                break;
            }
            case 4: {
                printf("La biografia è \n%s\n\nInserisci la nuova biografia: ", (*edit_passenger).description);
                fgets((*edit_passenger).description, 250, stdin);
                break;
            }
            default:
                break;
        }
    } while (selection != 5);
}

int remove_passenger(passenger *remove_passenger, passenger passengers[], int *count) {
    int end = *count;
    int found = 0;
    for (int i=0; i<end; i++) {
        if (!found && is_same_passenger(remove_passenger, &passengers[i])) {
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
    printf("\nInserisci il codice fiscale del passeggero: ");
    scanf("%16s", passenger_code);
    actual_passenger = existing_passenger(passenger_code, passengers, count);
    if (!actual_passenger) {
        printf("Passeggero non trovato!");
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

int is_same_passenger(passenger *lhs, passenger *rhs) {
    return !strcmp((*lhs).code, (*rhs).code);
}
