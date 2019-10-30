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
    printf("Città: ");
    scanf("%s", new_ride.source.city);
    printf("Provincia: ");
    scanf("%s", new_ride.source.province);
    printf("Indirizzo: ");
    scanf("%s", new_ride.source.address);
    printf("CAP: ");
    scanf("%d", &new_ride.source.postal_code);
    
    printf("\nDove vai?\n\n");
    printf("Città: ");
    scanf("%s", new_ride.destination.city);
    printf("Provincia: ");
    scanf("%s", new_ride.destination.province);
    printf("Indirizzo: ");
    scanf("%s", new_ride.destination.address);
    printf("CAP: ");
    scanf("%d", &new_ride.destination.postal_code);
    
    printf("\nE quando parti?\n\n");
    int is_valid = 0;
    do {
        printf("Inserisci la data nel formato dd/MM/yyyy: ");
        scanf("%hd/%hd/%hd", &new_ride.date.day, &new_ride.date.month, &new_ride.date.year);
        is_valid = is_valid_date(new_ride.date.day, new_ride.date.month, new_ride.date.year);
        if (!is_valid) {
            printf("\nLa data inserita non è valida!\n");
        }
    } while (!is_valid);
    
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
