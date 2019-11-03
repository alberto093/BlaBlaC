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

#define RIDE_FILE_NAME "rides.dat"
#define PLACE_DESC_MAX 72

/**
 This method edits the place parameter using the user's input (stdin).

 @param place pointer to a place struct
 */
void edit_place(place *place);

/**
 This method edits the date parameter (dd/MM/yyyy) using the user's input (stdin).

 @param date pointer to a date struct
 */
void edit_date(date *date);

/**
 This method edits the time (24H format) of the date parameter using the user's input (stdin).

 @param date pointer to a date struct
 */
void edit_time(date *date);

/**
 This method validates the price of the ride that user provides using stdin.

 @param price pointer to a float value
 */
void edit_price(float *price);

/**
 This method validates the number of seats of the ride that user provides using stdin.

 @param seats pointer to an unsigned short int value
 */
void edit_total_seats(unsigned short int *seats);

/**
 This function is intended to equate two ride struct.

 @param lhs pointer to a ride struct
 @param rhs pointer to a ride struct
 @return It returns 1 (true) if both rides have the same driver, the same source/destination place and the same departure date.
 */
int is_same_ride(const ride *lhs, const ride *rhs);

/**
 This function is intended to equate two place struct.

 @param lhs pointer to a place struct
 @param rhs pointer to a place struct
 @return It returns 1 (true) if both places are identical.
 */
int is_same_place(const place *lhs, const place *rhs);

/**
 This function is intended to equate two date struct.

 @param lhs pointer to a date struct
 @param rhs pointer to a date struct
 @return It returns 1 (true) if both dates are identical.
 */
int is_same_date(const date *lhs, const date *rhs);

/**
 This function is intended to check if two place are similar.

 @param complete pointer to a place struct
 @param partial pointer to a place struct
 @return It returns 1 (true) is the other place properties are a subsstrings of the original place properties.
 */
int is_similar_place(const place *complete, const place *partial);

/**
 This function checks if two date have the same day.

 @param lhs pointer to a date struct
 @param rhs pointer to a date struct
 @return It returns 1 (true) if both dates represent the same date in the gregorian calendar.
 */
int is_same_day(const date *lhs, const date *rhs);

/**
 This method is used to compare two rides by their price and the rating of the driver.

 @param lhs pointer to a ride struct
 @param rhs pointer to a ride struct
 @param drivers array of driver struct
 @param drivers_count count of the drivers array
 @return It returns 0 if both have the same price and the same driver's rating, 1 if the first ride has an higher price or a minor driver's rating else -1.
 */
int rides_compare(const ride *lhs, const ride *rhs, driver drivers[], int drivers_count);

int load_rides(ride *rides, int max_rides) {
    if (rides == NULL || max_rides < 1) {
        return 0;
    }
    
    FILE *rstream = fopen("/Users/Alberto/Università/Informatica/I anno/Laboratorio di Informatica/BlaBlaC/Carpooling/rides.dat", "rb");
    if (rstream == NULL) {
        printf("\nErrore durante l'apertura del file dei viaggi.\n");
        return 0;
    }
    
    fread(rides, sizeof(ride) * max_rides, 1, rstream);
    int total_rides = (int)ftell(rstream) / sizeof(ride);
    fclose(rstream);
    return total_rides;
}

ride create_ride(const hash_code driver_code) {
    ride new_ride;
    strcpy(new_ride.driver_code, driver_code);
    
    if (driver_code == NULL) {
        return new_ride;
    }
    
    printf("\nDa dove parti?\n\n");
    edit_place(&new_ride.source);
    printf("\nDove vai?\n\n");
    edit_place(&new_ride.destination);
    printf("\nE quando parti?\n\n");
    edit_date(&new_ride.date);
    edit_time(&new_ride.date);
    edit_price(&new_ride.price);
    edit_total_seats(&new_ride.total_seats);
    
    printf("Inserisci una breve descrizione del viaggio: ");
    scanf("%250[a-zA-Z ]", new_ride.description);
    fflush(stdin);
    
    new_ride.total_messages = 0;
    new_ride.total_passenger_codes = 0;
    return new_ride;
}

void edit_ride(ride *edit_ride) {
    if (edit_ride == NULL) {
        return;
    }
    
    if ((*edit_ride).total_passenger_codes > 0) {
        printf("\nQuesto viaggio ha già ricevuto delle prenotazioni! Ricordati di notificare eventuali modifiche ai passeggeri\n");
    }
    int selection = 0;
    do {
        int is_valid_selection = 0;
        do {
            printf("\n• Premi 1 per modificare il luogo di partenza\n");
            printf("• Premi 2 per modificare il luogo di arrivo\n");
            printf("• Premi 3 per modificare la data del viaggio\n");
            printf("• Premi 4 per modificare l'orario di partenza\n");
            printf("• Premi 5 per modificare il prezzo\n");
            printf("• Premi 6 per modificare il numero di posti disponibili\n");
            printf("• Premi 7 per modificare la descrizione del viaggio\n");
            printf("• Premi 8 per aggiungere un messaggio\n");
            printf("• Premi 9 per annullare\n\n");
            scanf("%i", &selection);
            fflush(stdin);
            
            is_valid_selection = is_included(selection, 1, 9);
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
                printf("Data del viaggio: %02hd/02%hd/4%hd", (*edit_ride).date.day, (*edit_ride).date.month, (*edit_ride).date.year);
                printf("\nInserisci la nuova data\n");
                edit_date(&(*edit_ride).date);
                break;
            }
            case 4: {
                printf("L'orario del viaggio è: %02hd:%02hd", (*edit_ride).date.hour, (*edit_ride).date.minutes);
                printf("\nInserisci il nuovo orario nel formato 24 ore hh:mm\n");
                edit_time(&(*edit_ride).date);
                break;
            }
            case 5: {
                printf("Il prezzo per passeggero è pari a € %-5.2f", (*edit_ride).price);
                printf("\nInserisci il nuovo prezzo\n");
                edit_price(&(*edit_ride).price);
                break;
            }
            case 6: {
                unsigned short int new_total_seats;
                int is_valid;
                printf("Il numero di posti totale é %hd", (*edit_ride).total_seats);
                do {
                    edit_total_seats(&new_total_seats);
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
            case 7: {
                printf("La descrizione è \n%s\n\nInserisci la nuova descrizione del viaggio: ", (*edit_ride).description);
                scanf("%250[a-zA-Z ]", (*edit_ride).description);
                fflush(stdin);
                break;
            }
            case 8: {
                printf("Inserisci il contenuto del messaggio:\n\n");
                scanf("%250[a-zA-Z ]", (*edit_ride).messages[(*edit_ride).total_messages]);
                (*edit_ride).total_messages++;
                fflush(stdin);
                break;
            }
            default:
                break;
        }
    } while (selection != 9);
}

int remove_ride(const ride *remove_ride, ride rides[], int *count) {
    if (remove_ride == NULL || rides == NULL || count == NULL) {
        return 0;
    }
    
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
    //   |    Data    | Luogo di Partenza |  Luogo di Arrivo  |
    // 1.| 25/12/2019 | Indirizzo, Città  | Indirizzo, Città  |
    
    if (rides == NULL || drivers == NULL || find_rides == NULL || find_rides_count == NULL) {
        return;
    }
    
    driver *ride_driver = find_driver(drivers, drivers_count);
    if (ride_driver == NULL) {
        return;
    }
    if ((*ride_driver).total_rides == 0) {
        printf("\nIl conducente inserito non ha pubblicato alcun viaggio!\n");
        return;
    }

    printf("\nViaggi pubblicati dal conducente con codice fiscale %s\n\n", (*ride_driver).code);
    printf("    ________________________________________________________________________");
    printf("__________________________________________________________________________________________\n");
    printf("   |    Data    |                             Luogo di Partenza                            |");
    printf("                              Luogo di Arrivo                             |\n");
    
    (*find_rides_count) = 0;
    char source_description[PLACE_DESC_MAX];
    char destination_description[PLACE_DESC_MAX];
    
    for (int i=0; i<drivers_count; i++) {
        if (is_equal_insensitive((*ride_driver).code, rides[i].driver_code)) {
            strcpy(source_description, "");
            strncat(source_description, rides[i].source.address, 35);
            strcat(source_description, ", ");
            strcat(source_description, rides[i].source.city);
            
            strcpy(destination_description, "");
            strncat(destination_description, rides[i].destination.address, 35);
            strcat(destination_description, ", ");
            strcat(destination_description, rides[i].destination.city);
            
            printf("%2i.| %02hd/%02hd/%4hd | %-72s | %-72s |\n", (*find_rides_count)+1, rides[i].date.day, rides[i].date.month, rides[i].date.year, source_description, destination_description);
            find_rides[(*find_rides_count)] = &rides[i];
            (*find_rides_count)++;
        }
    }
    
    printf("    ------------------------------------------------------------------------");
    printf("------------------------------------------------------------------------------------------\n");
}

void search_rides(ride rides[], int count, ride *find_rides[], int *find_rides_count) {
    if (rides == NULL || find_rides == NULL || find_rides_count == NULL) {
        return;
    }
    
    place source;
    place destination;
    date date;
    
    printf("\nDa dove parti?\n\n");
    edit_place(&source);
    printf("\nDove vai?\n\n");
    edit_place(&destination);
    printf("\nE quando parti?\n\n");
    edit_date(&date);
    
    unsigned short int total_seats = 0;
    int is_valid_seats = 0;
    do {
        printf("\nInserisci il numero di posti da prenotare (max 10 posti): ");
        scanf("%hd", &total_seats);
        fflush(stdin);
        is_valid_seats = is_included(total_seats, 1, 10);
        if (!is_valid_seats) {
            printf("\nNumero di posti non valido. Inserisci un valore compreso tra 1 e 10!\n");
        }
    } while (!is_valid_seats);
    
    (*find_rides_count) = 0;
    for (int i=0; i<count; i++) {
        if (rides[i].total_seats > 0 && (rides[i].total_seats - rides[i].total_passenger_codes) >= total_seats && is_similar_place(&rides[i].source, &source) && is_similar_place(&rides[i].destination, &destination) && is_same_day(&rides[i].date, &date)) {
            find_rides[(*find_rides_count)] = &rides[i];
            (*find_rides_count)++;
        }
    }
}

void sort_rides(ride rides[], int count, driver drivers[], int drivers_count) {
    if (rides == NULL || drivers == NULL) {
        return;
    }
    
    // Insertion sort
    int i, j;
    ride temp_element;
    for (i=1; i<count; i++) {
        temp_element = rides[i];

        for (j=i-1; j>=0 && rides_compare(&rides[j], &temp_element, drivers, drivers_count) == 1; j--) {
            rides[j+1] = rides[j];
        }
        
        rides[j+1] = temp_element;
    }
}

int contains_ride(const ride* new_ride, const ride rides[], int count) {
    if (new_ride == NULL || rides == NULL) {
        return 0;
    }
    
    for (int i=0; i<count; i++) {
        if (is_same_ride(new_ride, &rides[i])) {
            return 1;
        }
    }
    return 0;
}

int save_rides(const ride rides[], int count) {
    if (rides == NULL || count < 0) {
        return 0;
    }
    
    FILE *wstream = fopen("/Users/Alberto/Università/Informatica/I anno/Laboratorio di Informatica/BlaBlaC/Carpooling/rides.dat", "wb");
    if (wstream == NULL) {
        printf("\nrrore durante il salvataggio del file dei viaggi.\n");
        return 0;
    }
    
    fwrite(rides, sizeof(ride) * count, 1, wstream);
    return !fclose(wstream);
}

void edit_place(place *place) {
    if (place == NULL) {
        return;
    }
    
    printf("Città: ");
    scanf("%35[a-zA-Z ]", (*place).city);
    fflush(stdin);
    
    printf("Provincia: ");
    scanf("%25[a-zA-Z ]", (*place).province);
    fflush(stdin);
    
    printf("Indirizzo: ");
    scanf("%50[a-zA-Z ]", (*place).address);
    fflush(stdin);
    
    printf("CAP: ");
    scanf("%5u", &(*place).postal_code);
    fflush(stdin);
}

void edit_date(date *date) {
    if (date == NULL) {
        return;
    }
    
    int is_valid = 0;
    do {
        printf("Inserisci la data nel formato dd/MM/yyyy: ");
        scanf("%hd/%hd/%hd", &(*date).day, &(*date).month, &(*date).year);
        fflush(stdin);
        is_valid = is_valid_date((*date).day, (*date).month, (*date).year);
        if (!is_valid) {
            printf("\nLa data inserita non è valida!\n");
        }
    } while (!is_valid);
}

void edit_time(date *date) {
    if (date == NULL) {
        return;
    }
    
    int is_valid_24time = 0;
    do {
        printf("\nInserisci l'orario di partenza nel formato 24 ore hh:mm: ");
        scanf("%hd:%hd", &(*date).hour, &(*date).minutes);
        fflush(stdin);
        is_valid_24time = is_valid_time((*date).hour, (*date).minutes);
        if (!is_valid_24time) {
            printf("\nFormato ora non valido!\n");
        }
    } while (!is_valid_24time);
}

void edit_price(float *price) {
    if (price == NULL) {
        return;
    }
    
    int is_valid_price = 0;
    do {
        printf("Inserisci il costo del viaggio per passeggero: € ");
        scanf("%5f", price);
        fflush(stdin);
        is_valid_price = *price > 0;
        if (!is_valid_price) {
            printf("\nCosto del viaggio non valido. Inserisci un valore superiore a 0!\n");
        }
    } while (!is_valid_price);
}

void edit_total_seats(unsigned short int *seats) {
    if (seats == NULL) {
        return;
    }
    
    int is_valid_seats = 0;
    do {
        printf("Inserisci il numero di posti disponibili (max 10 posti): ");
        scanf("%hd", seats);
        fflush(stdin);
        is_valid_seats = is_included(*seats, 1, 10);
        if (!is_valid_seats) {
            printf("\nNumero di posti non valido. Inserisci un valore compreso tra 1 e 10!\n");
        }
    } while (!is_valid_seats);
}

int is_same_ride(const ride *lhs, const ride *rhs) {
    if (lhs == NULL || rhs == NULL) {
        return 0;
    }
    
    return is_equal_insensitive((*lhs).driver_code, (*rhs).driver_code) && is_same_place(&(*lhs).source, &(*rhs).source) && is_same_place(&(*lhs).destination, &(*rhs).destination) && is_same_date(&(*lhs).date, &(*rhs).date);
}

int is_same_place(const place *lhs, const place *rhs) {
    if (lhs == NULL || rhs == NULL) {
        return 0;
    }
    
    return !strcmp((*lhs).address, (*rhs).address) && !strcmp((*lhs).city, (*rhs).city) && !strcmp((*lhs).province, (*rhs).province) && (*lhs).postal_code == (*rhs).postal_code;
}

int is_same_date(const date *lhs, const date *rhs) {
    if (lhs == NULL || rhs == NULL) {
        return 0;
    }
    
    return (*lhs).day == (*rhs).day && (*lhs).month == (*rhs).month && (*lhs).year == (*rhs).year && (*lhs).hour == (*rhs).hour && (*lhs).minutes == (*rhs).minutes;
}

int is_similar_place(const place *complete, const place *partial) {
    if (complete == NULL || partial == NULL) {
        return 0;
    }
    
    return strstr((*complete).city, (*partial).city) != NULL || strstr((*complete).province, (*partial).province) != NULL;
}

int is_same_day(const date *lhs, const date *rhs) {
    if (lhs == NULL || rhs == NULL) {
        return 0;
    }
    
    return (*lhs).day == (*rhs).day && (*lhs).month == (*rhs).month && (*lhs).year == (*rhs).year;
}

int rides_compare(const ride *lhs, const ride *rhs, driver drivers[], int drivers_count) {
    if (lhs == NULL || rhs == NULL || drivers == NULL) {
        return 0;
    }
    
    if ((*lhs).price == (*rhs).price) {
        driver *lhs_driver = existing_driver((*lhs).driver_code, drivers, drivers_count);
        driver *rhs_driver = existing_driver((*rhs).driver_code, drivers, drivers_count);
        float lhs_rating = driver_rating(lhs_driver);
        float rhs_rating = driver_rating(rhs_driver);
        
        if (lhs_rating == rhs_rating) {
            return 0;
        } else {
            return lhs_rating > rhs_rating ? -1 : 1;
        }
    } else {
        return (*lhs).price > (*rhs).price ? 1 : -1;
    }
}
