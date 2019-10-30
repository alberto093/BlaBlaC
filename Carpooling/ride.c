//
//  ride.c
//  Carpooling
//
//  Created by Alberto Saltarelli on 29/10/2019.
//  Copyright © 2019 Alberto Saltarelli. All rights reserved.
//

#include "ride.h"
#include "utils.h"
#include <string.h>

void edit_place(place *place);
void edit_date(date *date);

int load_rides(ride rides[], int count) {
    FILE *rstream = fopen("/Users/Alberto/Università/Informatica/I anno/Laboratorio di Informatica/BlaBlaC/Carpooling/rides.dat", "rb");
    if (rstream == NULL) {
        return 0;
    }
    
    fread(rides, sizeof(ride) * count, 1, rstream);
    int total_rides = (int)ftell(rstream) / sizeof(ride);
    fclose(rstream);
    return total_rides;
}

ride create_ride(hash_code driver_code) {
    ride new_ride;
    strcpy(new_ride.driver_code, driver_code);
    
    printf("\nDa dove parti?\n\n");
    edit_place(&new_ride.source);
    printf("\nDove vai?\n\n");
    edit_place(&new_ride.destination);
    printf("\nE quando parti?\n\n");
    edit_date(&new_ride.date);
    printf("Inserisci il costo del viaggio per passeggero: € ");
    scanf("%2f", &new_ride.price);
    printf("Inserisci il numero di posti disponibili: ");
    scanf("%hd", &new_ride.total_seats);
    printf("Inserisci una breve descrizione del viaggio: ");
    scanf("%s", new_ride.description);
    new_ride.total_messages = 0;
    new_ride.total_passenger_codes = 0;
    return new_ride;
}

void edit_ride(ride *edit_ride) {
    int selection = 0;
    do {
        int is_valid_selection = 0;
        do {
            printf("\n• Premi 1 per modificare il luogo di partenza\n");
            printf("\n• Premi 2 per modificare il luogo di arrivo\n");
            printf("\n• Premi 3 per modificare la data del viaggio\n");
            printf("\n• Premi 4 per modificare il prezzo\n");
            printf("\n• Premi 5 per modificare il numero di posti disponibili\n");
            printf("\n• Premi 6 per modificare la descrizione del viaggio\n");
            printf("\n• Premi 7 per aggiungere un messaggio\n");
            printf("\n• Premi 8 per annullare\n\n");
            scanf("%i", &selection);
            is_valid_selection = is_included(selection, 1, 8);
            if (!is_valid_selection) {
                printf("\nScelta non valida\n\n");
            }
        } while (!is_valid_selection);
        
        switch (selection) {
            case 1: {
                printf("Il luogo di partenza è: %s\n%s %u\n%s", (*edit_ride).source.address, (*edit_ride).source.city, (*edit_ride).source.postal_code, (*edit_ride).source.province);
                printf("\nInserisci il nuovo luogo\n");
                edit_place(&(*edit_ride).source);
                break;
            }
            case 2: {
                printf("Il luogo di arrivo è: %s\n%s %u\n%s", (*edit_ride).destination.address, (*edit_ride).destination.city, (*edit_ride).destination.postal_code, (*edit_ride).destination.province);
                printf("\nInserisci il nuovo luogo\n");
                edit_place(&(*edit_ride).destination);
                break;
            }
            case 3: {
                printf("Data del viaggio: %hd/%hd/%hd", (*edit_ride).date.day, (*edit_ride).date.month, (*edit_ride).date.year);
                printf("\nInserisci la nuova data\n");
                edit_date(&(*edit_ride).date);
                break;
            }
            case 4: {
                printf("Il prezzo per passeggero è pari a € %2f", (*edit_ride).price);
                printf("Inserisci il nuovo prezzo: € ");
                scanf("%2f", &(*edit_ride).price);
                break;
            }
            case 5: {
                unsigned short int new_total_seats;
                int is_valid;
                printf("Il numero di posti totale é %hd", (*edit_ride).total_seats);
                do {
                    printf("Inserisci il numero di posti aggiornato: ");
                    scanf("%hd", &new_total_seats);
                    is_valid = new_total_seats >= (*edit_ride).total_passenger_codes;
                    if (!is_valid) {
                        if ((*edit_ride).total_passenger_codes == 1) {
                            printf("Un passeggero ha già prenotato un posto.");
                        } else {
                            printf("I passeggeri hanno già prenotato %hd posti.", (*edit_ride).total_passenger_codes);
                        }
                        printf("Inserisci un valore uguale o maggiore");
                    }
                } while (!is_valid);
                (*edit_ride).total_passenger_codes = new_total_seats;
                break;
            }
            case 6: {
                printf("La descrizione è \n%s\n\nInserisci la nuova descrizione del viaggio: ", (*edit_ride).description);
                scanf("%s", (*edit_ride).description);
                break;
            }
            case 7: {
                printf("Inserisci il contenuto del messaggio:\n\n");
                scanf("%s", (*edit_ride).messages[(*edit_ride).total_messages]);
                (*edit_ride).total_messages++;
                break;
            }
            default:
                break;
        }
    } while (selection != 7);
}

int remove_ride(ride *remove_ride, ride rides[], int *count) {
    return 0;
}

ride *find_ride(ride rides[], int count) {
    return NULL;
}

ride *existing_ride(hash_code driver_code, place source, place destination, date date, ride rides[], int count) {
    return NULL;
}

int contains_ride(ride* new_ride, ride rides[], int count) {
    return 0;
}

int save_rides(ride rides[], int count) {
    return 0;
}

void edit_place(place *place) {
    printf("Città: ");
    scanf("%s", (*place).city);
    printf("Provincia: ");
    scanf("%s", (*place).province);
    printf("Indirizzo: ");
    scanf("%s", (*place).address);
    printf("CAP: ");
    scanf("%u", &(*place).postal_code);
}

void edit_date(date *date) {
    int is_valid = 0;
    do {
        printf("Inserisci la data nel formato dd/MM/yyyy: ");
        scanf("%hd/%hd/%hd", &(*date).day, &(*date).month, &(*date).year);
        is_valid = is_valid_date((*date).day, (*date).month, (*date).year);
        if (!is_valid) {
            printf("\nLa data inserita non è valida!\n");
        }
    } while (!is_valid);
}
