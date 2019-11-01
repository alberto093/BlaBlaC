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

int is_same_ride(ride *lhs, ride *rhs);
int is_same_place(place *lhs, place *rhs);
int is_same_date(date *lhs, date *rhs);
int is_similar_place(place *complete, place *partial);
int is_same_day(date *lhs, date *rhs);
int rides_compare(ride *lhs, ride *rhs, driver drivers[], int drivers_count);

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
    printf("\nInserisci l'orario di partenza nel formato 24 ore: ");
    scanf("%hd:%hd", &new_ride.date.hour, &new_ride.date.minutes);
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
    int end = *count;
    int found = 0;
    for (int i=0; i<end; i++) {
        if (!found && is_same_ride(remove_ride, &rides[i])) {
            end--;
            found = 1;
        }
        if (found) {
            rides[i] = rides[i+1];
        }
    }
    if (found) {
        (*count)--;
    }
    return found;
}

void print_rides(ride rides[], int count, driver drivers[], int drivers_count, ride *find_rides[], int *find_rides_count) {
    driver *ride_driver = find_driver(drivers, drivers_count);
    if (ride_driver == NULL) {
        return;
    }
    if ((*ride_driver).total_rides == 0) {
        printf("\nIl conducente inserito non ha pubblicato alcun viaggio!\n");
        return;
    }
    
    printf("\nViaggi pubblicati dal conducente con codice fiscale %s\n\n", (*ride_driver).code);
    printf("  |    Data    |          Città di partenza          |           Città di arrivo            |\n");
    (*find_rides_count) = 0;
    for (int i=0; i<drivers_count; i++) {
        if (!strcmp((*ride_driver).code, rides[i].driver_code)) {
            printf("%i.| %hd/%hd/%hd | %35s | %35s |\n", (*find_rides_count) + 1, rides[i].date.day, rides[i].date.month, rides[i].date.year, rides[i].source.city, rides[i].destination.city);
            find_rides[(*find_rides_count)] = &rides[i];
            (*find_rides_count)++;
        }
    }
}

void search_rides(ride rides[], int count, ride *find_rides[], int *find_rides_count) {
    place source;
    place destination;
    date date;
    unsigned short int total_seats = 0;
    printf("\nDa dove parti?\n\n");
    edit_place(&source);
    printf("\nDove vai?\n\n");
    edit_place(&destination);
    printf("\nE quando parti?\n\n");
    edit_date(&date);
    
    do {
        printf("\nInserisci il numero di posti da prenotare: ");
        scanf("%hd", &total_seats);
        
        if (total_seats == 0) {
            printf("\nIl numero minimo di posti prenotabili è pari a 1!\n");
        }
    } while (total_seats == 0);
    
    (*find_rides_count) = 0;
    for (int i=0; i<count; i++) {
        if (is_similar_place(&rides[i].source, &source) && is_similar_place(&rides[i].destination, &destination) && is_same_day(&rides[i].date, &date) && (rides[i].total_seats - rides[i].total_passenger_codes) >= total_seats) {
            find_rides[(*find_rides_count)] = &rides[i];
            (*find_rides_count)++;
        }
    }
}

void sort_rides(ride rides[], int count, driver drivers[], int drivers_count) {
    int i, j;
    ride temp_element;
    for (i=1; i<count; i++) {
        temp_element = rides[i];

        for (j=i-1; j>=0 && rides_compare(&rides[j], &temp_element, drivers, drivers_count)>0; j--) {
            rides[j+1] = rides[j];
        }
        
        rides[j+1] = temp_element;
    }
}

int contains_ride(ride* new_ride, ride rides[], int count) {
    for (int i=0; i<count; i++) {
        if (is_same_ride(new_ride, &rides[i])) {
            return 1;
        }
    }
    return 0;
}

int save_rides(ride rides[], int count) {
    FILE *wstream = fopen("/Users/Alberto/Università/Informatica/I anno/Laboratorio di Informatica/BlaBlaC/Carpooling/rides.dat", "wb");
    if (wstream == NULL) {
        return 0;
    }
    
    fwrite(rides, sizeof(ride) * count, 1, wstream);
    return !fclose(wstream);
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

int is_same_ride(ride *lhs, ride *rhs) {
    return !strcmp((*lhs).driver_code, (*rhs).driver_code) && is_same_place(&(*lhs).source, &(*rhs).source) && is_same_place(&(*lhs).destination, &(*rhs).destination) && is_same_date(&(*lhs).date, &(*rhs).date);
}

int is_same_place(place *lhs, place *rhs) {
    return !strcmp((*lhs).address, (*rhs).address) && !strcmp((*lhs).city, (*rhs).city) && !strcmp((*lhs).province, (*rhs).province) && (*lhs).postal_code == (*rhs).postal_code;
}

int is_same_date(date *lhs, date *rhs) {
    return (*lhs).day == (*rhs).day && (*lhs).month == (*rhs).month && (*lhs).year == (*rhs).year && (*lhs).hour == (*rhs).hour && (*lhs).minutes == (*rhs).minutes;
}

int is_similar_place(place *complete, place *partial) {
    return strstr((*complete).city, (*partial).city) != NULL && strstr((*complete).province, (*partial).province) != NULL;
}

int is_same_day(date *lhs, date *rhs) {
    return (*lhs).day == (*rhs).day && (*lhs).month == (*rhs).month && (*lhs).year == (*rhs).year;
}

int rides_compare(ride *lhs, ride *rhs, driver drivers[], int drivers_count) {
    if ((*lhs).price == (*rhs).price) {
        driver *lhs_driver = existing_driver((*lhs).driver_code, drivers, drivers_count);
        driver *rhs_driver = existing_driver((*rhs).driver_code, drivers, drivers_count);
        float lhs_rating = driver_rating(lhs_driver);
        float rhs_rating = driver_rating(rhs_driver);
        
        if (lhs_rating == rhs_rating) {
            return 0;
        } else {
            return lhs_rating > rhs_rating ? 1 : -1;
        }
    } else {
        return (*lhs).price > (*rhs).price ? 1 : -1;
    }
}
