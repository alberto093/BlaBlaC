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

#define PASSENGER_FILE_NAME "passengers.dat"

/**
 This function is intended to equate two passenger struct.
 It returns 1 (true) if both passengers' codes are case insensitive equal.

 @param lhs pointer to passenger struct
 @param rhs pointer to passenger struct
 @return It returns 1 (true) if both passengers' codes are case insensitive equal else 0.
 */
int is_same_passenger(passenger *lhs, passenger *rhs);

int load_passengers(passenger *passengers, int max_passengers) {
    if (passengers == NULL || max_passengers < 1) {
        return 0;
    }
    FILE *rstream = fopen("/Users/Alberto/Università/Informatica/I anno/Laboratorio di Informatica/BlaBlaC/Carpooling/passengers.dat", "ab");
    if (rstream == NULL) {
        printf("\nErrore durante l'apertura del file dei passeggeri.\n");
        return 0;
    }
    
    fread(passengers, sizeof(passenger) * max_passengers, 1, rstream);
    int total_passengers = (int)ftell(rstream) / sizeof(passenger);
    fclose(rstream);
    return total_passengers;
}

passenger create_passenger(void) {
    passenger new_passenger;
    printf("\nInserisci il nome: ");
    scanf("%25[a-zA-Z ]", new_passenger.name);
    fflush(stdin);
    
    printf("Inserisci il cognome: ");
    scanf("%25[a-zA-Z ]", new_passenger.surname);
    fflush(stdin);
    
    printf("Inserisci età: ");
    scanf("%hd", &new_passenger.age);
    fflush(stdin);
    
    int is_valid_code = 0;
    do {
        printf("Inserisci il codice fiscale: ");
        scanf("%16s", new_passenger.code);
        fflush(stdin);
        is_valid_code = is_string_lenght(new_passenger.code, 16);
        if (!is_valid_code) {
            printf("\nCodice fiscale non valido!\n");
        }
    } while (!is_valid_code);
    
    printf("Inserisci una breve biografia: ");
    scanf("%250[a-zA-Z ]", new_passenger.description);
    fflush(stdin);
    
    printf("\n");
    return new_passenger;
}

void edit_passenger(passenger *edit_passenger) {
    if (edit_passenger == NULL) {
        return;
    }
    
    int selection = 0;
    do {
        int is_valid_selection = 0;
        do {
            printf("\n• Premi 1 per modificare il nome\n");
            printf("\n• Premi 2 per modificare il cognome\n");
            printf("\n• Premi 3 per modificare l'età\n");
            printf("\n• Premi 4 per modificare la biografia\n");
            printf("\n• Premi 5 per annullare\n\n");
            scanf("%i", &selection);
            fflush(stdin);
            
            is_valid_selection = is_included(selection, 1, 5);
            if (!is_valid_selection) {
                printf("\nScelta non valida\n\n");
            }
        } while (!is_valid_selection);
        
        switch (selection) {
            case 1: {
                printf("\nIl nome è %s, inserisci il nuovo nome: ", (*edit_passenger).name);
                scanf("%25[a-zA-Z ]", (*edit_passenger).name);
                break;
            }
            case 2: {
                printf("\nIl cognome è %s, inserisci il nuovo cognome: ", (*edit_passenger).surname);
                scanf("%25[a-zA-Z ]", (*edit_passenger).surname);
                break;
            }
            case 3: {
                printf("\nL'età è %hd, inserisci la nuova età: ", (*edit_passenger).age);
                scanf("%hd", &(*edit_passenger).age);
                break;
            }
            case 4: {
                printf("La biografia è \n%s\n\nInserisci la nuova biografia: ", (*edit_passenger).description);
                scanf("%250[a-zA-Z ]", (*edit_passenger).description);
                break;
            }
            default:
                break;
        }
        fflush(stdin);
    } while (selection != 5);
}

int remove_passenger(passenger *remove_passenger, passenger passengers[], int *count) {
    if (remove_passenger == NULL || passengers == NULL || count == NULL) {
        return 0;
    }
    
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
    if (passengers == NULL || count < 1) {
        return NULL;
    }
    
    hash_code passenger_code;
    passenger *actual_passenger = NULL;
    
    int is_valid_code = 0;
    do {
        printf("\nInserisci il codice fiscale del passeggero: ");
        scanf("%16s", passenger_code);
        fflush(stdin);
        is_valid_code = is_string_lenght(passenger_code, 16);
        if (!is_valid_code) {
            printf("\nCodice fiscale non valido!\n");
        }
    } while (!is_valid_code);
    
    actual_passenger = existing_passenger(passenger_code, passengers, count);
    if (!actual_passenger) {
        printf("Passeggero non trovato!");
    }
    return actual_passenger;
}

passenger *existing_passenger(hash_code passenger_code, passenger passengers[], int count) {
    if (passenger_code == NULL || passengers == NULL || count < 1) {
        return NULL;
    }
    
    for (int i=0; i<count; i++) {
        if (is_equal_insensitive(passengers[i].code, passenger_code)) {
            return &passengers[i];
        }
    }
    return NULL;
}

int contains_passenger(passenger* new_passenger, passenger passengers[], int count) {
    return existing_passenger((*new_passenger).code, passengers, count) != NULL;
}

int save_passengers(passenger passengers[], int count) {
    if (passengers == NULL || count < 0) {
        return 0;
    }
    
    FILE *wstream = fopen("/Users/Alberto/Università/Informatica/I anno/Laboratorio di Informatica/BlaBlaC/Carpooling/passengers.dat", "wb");
    if (wstream == NULL) {
        printf("\nrrore durante il salvataggio del file dei passeggeri.\n");
        return 0;
    }
    
    fwrite(passengers, sizeof(passenger) * count, 1, wstream);
    return !fclose(wstream);
}

int is_same_passenger(passenger *lhs, passenger *rhs) {
    if (lhs == NULL || rhs == NULL) {
        return 0;
    }
    return is_equal_insensitive((*lhs).code, (*rhs).code);
}
