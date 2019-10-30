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
    printf("Inserisci il costo del viaggio per passeggero: ");
    scanf("%2f", &new_ride.price);
    printf("Inserisci il numero di posti disponibili: ");
    scanf("%hd", &new_ride.total_seats);
    printf("Inserisci una breve descrizione del viaggio: ");
    scanf("%s", new_ride.description);
    return new_ride;
}

void edit_ride(ride *edit_ride) {
    
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
    scanf("%d", &(*place).postal_code);
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
