//
//  driver.c
//  Carpooling
//
//  Created by Alberto Saltarelli on 29/10/2019.
//  Copyright © 2019 Alberto Saltarelli. All rights reserved.
//

#include "driver.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define DRIVER_PRINT_MAX NAME_MAX + SURNAME_MAX + 4

int is_same_driver(driver *lhs, driver *rhs);

int load_drivers(driver drivers[], int count) {
    FILE *rstream = fopen("/Users/Alberto/Università/Informatica/I anno/Laboratorio di Informatica/BlaBlaC/Carpooling/drivers.dat", "rb");
    if (rstream == NULL) {
        return 0;
    }

    fread(drivers, sizeof(driver) * count, 1, rstream);
    int total_drivers = (int)ftell(rstream) / sizeof(driver);
    fclose(rstream);
    return total_drivers;
}

driver create_driver(void) {
    driver new_driver;
    printf("\nInserisci il nome: ");
    scanf("%s", new_driver.name);
    printf("Inserisci il cognome: ");
    scanf("%s", new_driver.surname);
    printf("Inserisci età: ");
    scanf("%hd", &new_driver.age);
    printf("Inserisci il codice fiscale: ");
    scanf("%s", new_driver.code);
    printf("Inserisci una breve biografia: ");
    scanf("%s", new_driver.description);
    printf("\n");
    new_driver.total_rides = 0;
    new_driver.total_reviews = 0;
    return new_driver;
}

void edit_driver(driver *edit_driver) {
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
            is_valid_selection = is_included(selection, 1, 5);
            if (!is_valid_selection) {
                printf("\nScelta non valida\n\n");
            }
        } while (!is_valid_selection);
        
        switch (selection) {
            case 1: {
                printf("\nIl nome è %s, inserisci il nuovo nome: ", (*edit_driver).name);
                scanf("%s", (*edit_driver).name);
                break;
            }
            case 2: {
                printf("\nIl cognome è %s, inserisci il nuovo cognome: ", (*edit_driver).surname);
                scanf("%s", (*edit_driver).surname);
                break;
            }
            case 3: {
                printf("\nL'età è %hd, inserisci la nuova età: ", (*edit_driver).age);
                scanf("%hd", &(*edit_driver).age);
                break;
            }
            case 4: {
                printf("La biografia è \n%s\n\nInserisci la nuova biografia: ", (*edit_driver).description);
                scanf("%s", (*edit_driver).description);
                break;
            }
            default:
                break;
        }
    } while (selection != 5);
}

int remove_driver(driver *remove_driver, driver drivers[], int *count) {
    int end = *count;
    int found = 0;
    for (int i=0; i<end; i++) {
        if (!found && is_same_driver(remove_driver, &drivers[i])) {
            end--;
            found = 1;
        }
        if (found) {
            drivers[i] = drivers[i+1];
        }
    }
    if (found) {
        (*count)--;
    }
    return found;
}

driver *find_driver(driver drivers[], int count) {
    hash_code driver_code;
    driver *actual_driver = NULL;
    printf("\nInserisci il codice fiscale del conducente: ");
    scanf("%s", driver_code);
    actual_driver = existing_driver(driver_code, drivers, count);
    if (!actual_driver) {
        printf("Conducente non trovato!");
    }
    return actual_driver;
}

driver *existing_driver(hash_code driver_code, driver drivers[], int count) {
    for (int i=0; i<count; i++) {
        if (!strcmp(drivers[i].code, driver_code)) {
            return &drivers[i];
        }
    }
    return NULL;
}

float driver_rating(driver *driver) {
    float rating_sum = 0;
    int total_rating = 0;
    for (int i=0; i<(*driver).total_reviews; i++) {
        rating_sum += (*driver).reviews[i].rating + 1;
        total_rating++;
    }
    return total_rating > 0 ? roundf((rating_sum / total_rating)*10)/10 : 0;
}

void print_toprated_drivers(driver drivers[], int count) {
    if (count == 0) {
        printf("\nNessun conducente trovato!\n");
        return;
    }
    
    float max_rate = 0.0;
    char toprated_drivers[DRIVERS_MAX][DRIVER_PRINT_MAX];
    int toprated_drivers_count = 0;
    
    for (int i=0; i<count; i++) {
        float rating = driver_rating(&drivers[i]);
        if (rating > 0) {
            if (rating > max_rate) {
                max_rate = rating;
                toprated_drivers_count = 0;
            }
            if (rating == max_rate) {
                strcat(toprated_drivers[toprated_drivers_count], drivers[i].name);
                strcat(toprated_drivers[toprated_drivers_count], "\t");
                strcat(toprated_drivers[toprated_drivers_count], drivers[i].surname);
                toprated_drivers_count++;
            }
        }
    }
    
    if (toprated_drivers_count > 0) {
        printf("\nLa media delle valutazioni più alta è pari a: %-3.1f/5\n", max_rate);
        
        if (toprated_drivers_count == 1) {
            printf("Il conducente è: %s", toprated_drivers[0]);
        } else {
            printf("I conducenti sono:\n");
            for (int i=0; i<toprated_drivers_count; i++) {
                printf("%s\n", toprated_drivers[i]);
            }
        }
    } else {
        printf("\nIl numero di valutazioni dei conducenti non è sufficiente per eleggere il miglior conducente.\n");
    }
}

void add_review(driver *driver, hash_code passenger_code) {
    review new_review;
    strcpy(new_review.passenger_code, passenger_code);
    int is_valid = 0;
    do {
        printf("\nInserisci un voto compreso tra 1 e 5\n");
        printf("1: Pessimo\n");
        printf("2: Mediocre\n");
        printf("3: Buono\n");
        printf("4: Ottimo\n");
        printf("5: Eccellente\n");
        scanf("%i", &new_review.rating);
        new_review.rating--;
        is_valid = is_included(new_review.rating, 0, 4);
        if (!is_valid) {
            printf("\nScelta non valida!\n");
        }
    } while (!is_valid);
    
    printf("Inserisci un breve commento: ");
    scanf("%250s", new_review.text);
    
    (*driver).reviews[(*driver).total_reviews] = new_review;
    (*driver).total_reviews++;
}

int contains_driver(driver* new_driver, driver drivers[], int count) {
    return existing_driver((*new_driver).code, drivers, count) != NULL;
}

int save_drivers(driver drivers[], int count) {
    FILE *wstream = fopen("/Users/Alberto/Università/Informatica/I anno/Laboratorio di Informatica/BlaBlaC/Carpooling/drivers.dat", "wb");
    if (wstream == NULL) {
        return 0;
    }
    
    fwrite(drivers, sizeof(driver) * count, 1, wstream);
    return !fclose(wstream);
}

int is_same_driver(driver *lhs, driver *rhs) {
    return !strcmp((*lhs).code, (*rhs).code);
}
