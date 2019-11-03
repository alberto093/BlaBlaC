//
//  driver.c
//  Carpooling
//
//  Created by Alberto Saltarelli on 29/10/2019.
//  Copyright © 2019 Alberto Saltarelli. All rights reserved.
//

#include "driver.h"
#include "utils.h"
#include <string.h>
#include <math.h>

#define DRIVER_PRINT_MAX NAME_MAX + SURNAME_MAX + 4
#define DRIVER_FILE_NAME "drivers.dat"

/**
 This function is intended to equate two driver struct.

 @param lhs pointer to driver struct
 @param rhs pointer to driver struct
 @return It returns 1 (true) if both drivers' codes are case insensitive equal else 0.
 */
int is_same_driver(const driver *lhs, const driver *rhs);

int load_drivers(driver *drivers, int max_drivers) {
    if (drivers == NULL || max_drivers < 1) {
        return 0;
    }
    
    FILE *rstream = fopen("/Users/Alberto/Università/Informatica/I anno/Laboratorio di Informatica/BlaBlaC/Carpooling/drivers.dat", "rb");
    if (rstream == NULL) {
        printf("\nErrore durante l'apertura del file dei conducenti.\n");
        return 0;
    }

    fread(drivers, sizeof(driver) * max_drivers, 1, rstream);
    int total_drivers = (int)ftell(rstream) / sizeof(driver);
    fclose(rstream);
    return total_drivers;
}

driver create_driver(void) {
    driver new_driver;

    printf("\nInserisci il nome: ");
    scanf("%25[a-zA-Z ]", new_driver.name);
    fflush(stdin);
    
    printf("Inserisci il cognome: ");
    scanf("%25[a-zA-Z ]", new_driver.surname);
    fflush(stdin);
    
    printf("Inserisci età: ");
    scanf("%hd", &new_driver.age);
    fflush(stdin);
    
    int is_valid_code = 0;
    do {
        printf("Inserisci il codice fiscale: ");
        scanf("%16s", new_driver.code);
        fflush(stdin);
        is_valid_code = is_string_lenght(new_driver.code, 16);
        if (!is_valid_code) {
            printf("\nCodice fiscale non valido!\n");
        }
    } while (!is_valid_code);
    
    printf("Inserisci una breve biografia: ");
    scanf("%250[a-zA-Z ]", new_driver.description);
    fflush(stdin);
    
    printf("\n");

    new_driver.total_rides = 0;
    new_driver.total_reviews = 0;
    return new_driver;
}

void edit_driver(driver *edit_driver) {
    if (edit_driver == NULL) {
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
                printf("\nIl nome è %s, inserisci il nuovo nome: ", (*edit_driver).name);
                scanf("%25[a-zA-Z ]", (*edit_driver).name);
                break;
            }
            case 2: {
                printf("\nIl cognome è %s, inserisci il nuovo cognome: ", (*edit_driver).surname);
                scanf("%25[a-zA-Z ]", (*edit_driver).surname);
                break;
            }
            case 3: {
                printf("\nL'età è %hd, inserisci la nuova età: ", (*edit_driver).age);
                scanf("%hd", &(*edit_driver).age);
                break;
            }
            case 4: {
                printf("La biografia è \n%s\n\nInserisci la nuova biografia: ", (*edit_driver).description);
                scanf("%250[a-zA-Z ]", (*edit_driver).description);
                break;
            }
            default:
                break;
        }
        fflush(stdin);
    } while (selection != 5);
}

int remove_driver(const driver *remove_driver, driver drivers[], int *count) {
    if (remove_driver == NULL || drivers == NULL || count == NULL) {
        return 0;
    }
    
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
    if (drivers == NULL || count < 1) {
        return NULL;
    }
    
    hash_code driver_code;
    driver *actual_driver = NULL;
    
    int is_valid_code = 0;
    do {
        printf("\nInserisci il codice fiscale del conducente: ");
        scanf("%16s", driver_code);
        fflush(stdin);
        is_valid_code = is_string_lenght(driver_code, 16);
        if (!is_valid_code) {
            printf("\nCodice fiscale non valido!\n");
        }
    } while (!is_valid_code);
    
    actual_driver = existing_driver(driver_code, drivers, count);
    if (!actual_driver) {
        printf("Conducente non trovato!");
    }
    return actual_driver;
}

driver *existing_driver(const hash_code driver_code, driver drivers[], int count) {
    if (driver_code == NULL || drivers == NULL || count < 1) {
        return NULL;
    }
    
    for (int i=0; i<count; i++) {
        if (is_equal_insensitive(drivers[i].code, driver_code)) {
            return &drivers[i];
        }
    }
    return NULL;
}

float driver_rating(const driver *driver) {
    if (driver == NULL) {
        return 0;
    }
    float rating_sum = 0;
    int total_rating = 0;
    for (int i=0; i<(*driver).total_reviews; i++) {
        rating_sum += (*driver).reviews[i].rating;
        total_rating++;
    }
    return total_rating > 0 ? roundf((rating_sum / total_rating)*10)/10 : 0;
}

void print_toprated_drivers(const driver drivers[], int count) {
    if (drivers == NULL || count < 1) {
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
                sprintf(toprated_drivers[toprated_drivers_count], "%-25s  %-25s", drivers[i].name, drivers[i].surname);
                toprated_drivers_count++;
            }
        }
    }
    
    if (toprated_drivers_count > 0) {
        printf("\nLa media delle valutazioni più alta è pari a: %-3.1f/5\n", max_rate);
        
        if (toprated_drivers_count == 1) {
            printf("Il conducente è: %s", toprated_drivers[0]);
        } else {
            printf("I conducenti sono:\n\n");
            printf("%-26s %-26s\n", "NOME", "COGNOME");
            for (int i=0; i<toprated_drivers_count; i++) {
                printf("%s\n", toprated_drivers[i]);
            }
        }
    } else {
        printf("\nIl numero di valutazioni dei conducenti non è sufficiente per eleggere il miglior conducente.\n");
    }
}

int add_review(driver *driver, const hash_code passenger_code) {
    if (driver == NULL || passenger_code == NULL) {
        return 0;
    }
    if (is_equal_insensitive(passenger_code, (*driver).code)) {
        printf("\nNon puoi lasciare una recensione verso te stesso!\n");
        return 0;
    }
    
    review new_review;
    strcpy(new_review.passenger_code, passenger_code);
    int rating = 0;
    int is_valid = 0;
    do {
        printf("\nInserisci un voto compreso tra 1 e 5\n");
        printf("1: Pessimo\n");
        printf("2: Mediocre\n");
        printf("3: Buono\n");
        printf("4: Ottimo\n");
        printf("5: Eccellente\n\n");
        scanf("%i", &rating);
        fflush(stdin);
        
        is_valid = is_included(rating, rating_very_poor, rating_oustanding);
        if (!is_valid) {
            printf("\nScelta non valida!\n");
        }
    } while (!is_valid);
    new_review.rating = rating;
    printf("Inserisci un breve commento: ");
    scanf("%250[a-zA-Z ]", new_review.text);
    fflush(stdin);
    
    (*driver).reviews[(*driver).total_reviews] = new_review;
    (*driver).total_reviews++;
    return rating;
}

int contains_driver(const driver* new_driver, driver drivers[], int count) {
    return existing_driver((*new_driver).code, drivers, count) != NULL;
}

int save_drivers(const driver drivers[], int count) {
    if (drivers == NULL || count < 0) {
        return 0;
    }
    
    FILE *wstream = fopen("/Users/Alberto/Università/Informatica/I anno/Laboratorio di Informatica/BlaBlaC/Carpooling/drivers.dat", "wb");
    if (wstream == NULL) {
        printf("\nrrore durante il salvataggio del file dei conducenti.\n");
        return 0;
    }
    
    fwrite(drivers, sizeof(driver) * count, 1, wstream);
    return !fclose(wstream);
}

int is_same_driver(const driver *lhs, const driver *rhs) {
    if (lhs == NULL || rhs == NULL) {
        return 0;
    }
    return is_equal_insensitive((*lhs).code, (*rhs).code);
}
