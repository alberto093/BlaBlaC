//
//  main.c
//  Carpooling
//
//  Created by Alberto Saltarelli on 28/10/2019.
//  Copyright © 2019 Alberto Saltarelli. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include "utils.h"
#include "route.h"
#include "driver.h"
#include "passenger.h"
#include "ride.h"
#include "unittest.h"
#include "mock.h"

#define RUN_TEST 0
#define RESET 0

/**
 It accepts an array of drivers in which will be appended the driver was created by the user using stdin and an int pointer of its count that will be increased by one.
 At the end of function the new array will be saved into the drivers file.

 @param drivers array of driver struct
 @param total_drivers pointer to the count of the array
 */
void show_drivers_create(driver drivers[], int *total_drivers);

/**
 It accepts an array of drivers in which will be edited the driver was selected by the user using stdin and its count.
 At the end of function the new array will be saved into the drivers file.

 @param drivers array of driver struct
 @param total_drivers the count of the array
 */
void show_drivers_edit(driver drivers[], int total_drivers);

/**
 It accepts an array of drivers in which will be removed the driver was selected by the user using stdin and an int pointer of its count that will be decreased by one.
 At the end of function the new array will be saved into the drivers file.

 @param drivers array of driver struct
 @param total_drivers pointer to the count of the array
 */
void show_drivers_delete(driver drivers[], int *total_drivers);

/**
 It accepts an array of passengers in which will be appended the passenger was created by the user using stdin and an int pointer of its count that will be increased by one.
 At the end of function the new array will be saved into the passengers file.

 @param passengers array of passenger struct
 @param total_passengers pointer to the count of the array
 */
void show_passengers_create(passenger passengers[], int *total_passengers);

/**
 It accepts an array of passengers in which will be edited the passenger was selected by the user using stdin and its count.
 At the end of function the new array will be saved into the passengers file.

 @param passengers array of passenger struct
 @param total_passengers the count of the array
 */
void show_passengers_edit(passenger passengers[], int total_passengers);

/**
 It accepts an array of passengers in which will be removed the driver was selected by the user using stdin and an int pointer of its count that will be decreased by one.
 At the end of function the new array will be saved into the passengers file.

 @param passengers array of passenger struct
 @param total_passengers pointer to the count of the array
 */
void show_passengers_delete(passenger passengers[], int *total_passengers);

/**
 It accepts an array of rides in which will be appended the ride was created by the user using stdin and an int pointer of its count that will be increased by one.
 show_rides_create requires an array of drivers and its count in order to select the ride's driver.
 At the end of function both the arrays will be saved into their files.

 @param rides array of ride struct
 @param total_rides pointer to the count of the rides array
 @param drivers array of driver struct
 @param total_drivers count of the drivers array
 */
void show_rides_create(ride rides[], int *total_rides, driver drivers[], int total_drivers);

/**
 It accepts an array of rides in which will be edited the ride was selected by the user using stdin and its count.
 show_rides_edit requires an array of drivers and its count in order to show the selected driver's rides.
 At the end of function the array of rides will be saved into the rides file.

 @param rides array of ride struct
 @param total_rides count of the rides array
 @param drivers array of driver struct
 @param total_drivers count of the drivers array
 */
void show_rides_edit(ride rides[], int total_rides, driver drivers[], int total_drivers);

/**
 It accepts an array of rides in which will be removed the ride was selected by the user using stdin and an int pointer of its count that will be decreased by one.
 show_rides_delete requires an array of drivers and its count in order to show the selected driver's rides.
 At the end of function both the arrays will be saved into their files.

 @param rides array of ride struct
 @param total_rides pointer to the count of the rides array
 @param drivers array of driver struct
 @param total_drivers count of the drivers array
 */
void show_rides_delete(ride rides[], int *total_rides, driver drivers[], int total_drivers);

/**
 It requires an array of rides, an array of drivers, an array of passengers and their count.
 show_rides_search takes input from stdin in order to search the matched rides, show them sorted by price and drivers' rating and allows user to reserve a ride.
 At the end of function the array of rides will be saved into the rides file.
 

 @param rides array of ride struct
 @param total_rides count of the rides array
 @param drivers array of driver struct
 @param total_drivers count of the drivers array
 @param passengers array of passenger struct
 @param total_passengers count of the passengers array
 */
void show_rides_search(ride rides[], int total_rides, driver drivers[], int total_drivers, passenger passengers[], int total_passengers);

/**
 It requires an array of rides, an array of drivers, an array of passengers and their count.
 show_rides_review takes input from stdin in order to show the selected driver's rides and allows user to select and to review a ride.
 At the end of function the array of drivers will be saved into the drivers file.

 @param rides array of ride struct
 @param total_rides count of the rides array
 @param drivers array of driver struct
 @param total_drivers count of the drivers array
 @param passengers array of passenger struct
 @param total_passengers count of the passengers array
 */
void show_rides_review(ride rides[], int total_rides, driver drivers[], int total_drivers, passenger passengers[], int total_passengers);

/**
 It requires an array of rides, an array of drivers and their count.
 print_full_rides uses printf (stdout) to show to the user all the input rides in a pretty way.

 @param rides array of ride struct
 @param total_rides count of the rides array
 @param drivers array of driver struct
 @param total_drivers count of the drivers array
 */
void print_full_rides(const ride rides[], int total_rides, driver drivers[], int total_drivers);

int main() {
//    if (RUN_TEST) {
//        return run_all_tests();
//    }
    
    if (RESET) {
        setup_default();
        return 0;
    }

    driver drivers[DRIVERS_MAX];
    int total_drivers = load_drivers(drivers, DRIVERS_MAX);
    passenger passengers[PASSENGERS_MAX];
    int total_passengers = load_passengers(passengers, PASSENGERS_MAX);
    ride rides[RIDES_MAX];
    int total_rides = load_rides(rides, RIDES_MAX);
  
    printf("BENVENUTO IN FLAVIA");
    home_result selection = home_drivers;
    
    while (selection != home_exit) {
        selection = show_main_menu();
        
        switch (selection) {
            case home_drivers: {
                drivers_result result = drivers_create;

                while (result != drivers_back) {
                    result = show_drivers_menu();
        
                    switch (result) {
                        case drivers_create:
                            show_drivers_create(drivers, &total_drivers);
                            break;
                        case drivers_edit:
                            show_drivers_edit(drivers, total_drivers);
                            break;
                        case drivers_delete:
                            show_drivers_delete(drivers, &total_drivers);
                            break;
                        case drivers_list:
                            print_toprated_drivers(drivers, total_drivers);
                            break;
                        case drivers_back:
                            break;
                    }
                }
                break;
            }
            case home_passengers: {
                passengers_result result = passengers_create;
                
                while (result != passengers_back) {
                    result = show_passengers_menu();
                    
                    switch (result) {
                        case passengers_create:
                            show_passengers_create(passengers, &total_passengers);
                            break;
                        case passengers_edit:
                            show_passengers_edit(passengers, total_passengers);
                            break;
                        case passengers_delete:
                            show_passengers_create(passengers, &total_passengers);
                            break;
                        case passengers_back:
                            break;
                    }
                }
                break;
            }
            case home_rides: {
                rides_result result = rides_create;
                
                while (result != rides_back) {
                    result = show_rides_menu();
                    switch (result) {
                        case rides_create:
                            show_rides_create(rides, &total_rides, drivers, total_drivers);
                            break;
                        case rides_edit:
                            show_rides_edit(rides, total_rides, drivers, total_drivers);
                            break;
                        case rides_delete:
                            show_rides_delete(rides, &total_rides, drivers, total_drivers);
                            break;
                        case rides_search:
                            show_rides_search(rides, total_rides, drivers, total_drivers, passengers, total_passengers);
                            break;
                        case rides_review:
                            show_rides_review(rides, total_rides, drivers, total_drivers, passengers, total_passengers);
                            break;
                        case rides_back:
                            break;
                    }
                }
                break;
            }
            case home_exit:
                break;
        }
    }
    
    return 0;
}

void show_drivers_create(driver drivers[], int *total_drivers) {
    driver new_driver;
    int is_valid = 0;
    do {
        new_driver = create_driver();
        is_valid = !contains_driver(&new_driver, drivers, *total_drivers);
        if (!is_valid) {
            printf("Il conducente con codice fiscale %s è già registrato!\n", new_driver.code);
        }
    } while (!is_valid);
    drivers[*total_drivers] = new_driver;
    (*total_drivers)++;
    save_drivers(drivers, *total_drivers);
    printf("Conducente creato con successo!");
}

void show_drivers_edit(driver drivers[], int total_drivers) {
    driver *actual_driver = find_driver(drivers, total_drivers);
    if (actual_driver != NULL) {
        edit_driver(actual_driver);
        save_drivers(drivers, total_drivers);
        printf("Conducente modificato con successo!");
    }
}

void show_drivers_delete(driver drivers[], int *total_drivers) {
    driver *actual_driver = find_driver(drivers, *total_drivers);
    if (actual_driver != NULL) {
        int selection = 0;
        do {
            printf("\nPremi 1 per confermare l'eliminazione");
            printf("\nPremi 2 per annullare\n");
            scanf("%i", &selection);
            fflush(stdin);
            if (!is_included(selection, 1, 2)) {
                printf("\nScelta non valida!\n");
            }
        } while (!is_included(selection, 1, 2));
        if (selection == 1 && remove_driver(actual_driver, drivers, total_drivers)) {
            save_drivers(drivers, *total_drivers);
            printf("Conducente eliminato con successo!");
        }
    }
}

void show_passengers_create(passenger passengers[], int *total_passengers) {
    passenger new_passenger;
    int is_valid = 0;
    do {
        new_passenger = create_passenger();
        is_valid = !contains_passenger(&new_passenger, passengers, *total_passengers);
        if (!is_valid) {
            printf("Il passeggero con codice fiscale %s è già registrato!\n", new_passenger.code);
        }
    } while (!is_valid);
    passengers[*total_passengers] = new_passenger;
    (*total_passengers)++;
    save_passengers(passengers, *total_passengers);
    printf("Passeggero creato con successo!");
}

void show_passengers_edit(passenger passengers[], int total_passengers) {
    passenger *actual_passenger = find_passenger(passengers, total_passengers);
    if (actual_passenger != NULL) {
        edit_passenger(actual_passenger);
        save_passengers(passengers, total_passengers);
        printf("Passeggero modificato con successo!");
    }
}

void show_passengers_delete(passenger passengers[], int *total_passengers) {
    passenger *actual_passenger = find_passenger(passengers, *total_passengers);
    if (actual_passenger != NULL) {
        int selection = 0;
        do {
            printf("\nPremi 1 per confermare l'eliminazione");
            printf("\nPremi 2 per annullare\n");
            scanf("%i", &selection);
            fflush(stdin);
            if (!is_included(selection, 1, 2)) {
                printf("\nScelta non valida!\n");
            }
        } while (!is_included(selection, 1, 2));
        if (selection == 1 && remove_passenger(actual_passenger, passengers, total_passengers)) {
            save_passengers(passengers, *total_passengers);
            printf("Passeggero eliminato con successo!");
        }
    }
}

void show_rides_create(ride rides[], int *total_rides, driver drivers[], int total_drivers) {
    driver *actual_driver = find_driver(drivers, total_drivers);
    if (actual_driver == NULL) {
        return;
    }
    ride new_ride;
    int is_valid = 0;
    do {
        new_ride = create_ride((*actual_driver).code);
        is_valid = contains_ride(&new_ride, rides, *total_rides);
        if (!is_valid) {
            printf("\nDati non validi! Hai già inserito questo viaggio.\n\n");
        }
    } while (!is_valid);
    (*actual_driver).total_rides++;
    rides[*total_rides] = new_ride;
    (*total_rides)++;
    
    save_drivers(drivers, total_drivers);
    save_rides(rides, *total_rides);
    printf("Viaggio creato con successo!");
}

void show_rides_edit(ride rides[], int total_rides, driver drivers[], int total_drivers) {
    ride *valid_rides[total_rides];
    int total_valid_rides = 0;
    print_rides(rides, total_rides, drivers, total_drivers, valid_rides, &total_valid_rides);
    
    int selection = 0;
    int is_valid_selection = 0;
    do {
        printf("\nInserisci il numero del viaggio che vuoi modificare: ");
        scanf("%2i", &selection);
        fflush(stdin);
        is_valid_selection = is_included(selection, 1, total_valid_rides);
        if (!is_valid_selection) {
            printf("\nScelta non valida\n");
        }
    } while (!is_valid_selection);
    
    edit_ride(valid_rides[selection - 1]);
    save_rides(rides, total_rides);
}

void show_rides_delete(ride rides[], int *total_rides, driver drivers[], int total_drivers) {
    ride *valid_rides[*total_rides];
    int total_valid_rides = 0;
    print_rides(rides, *total_rides, drivers, total_drivers, valid_rides, &total_valid_rides);
    
    if (!total_valid_rides) {
        return;
    }
    
    int selection = 0;
    int is_valid_selection = 0;
    do {
        printf("\nInserisci il numero del viaggio che vuoi eliminare: ");
        scanf("%2i", &selection);
        fflush(stdin);
        is_valid_selection = is_included(selection, 1, total_valid_rides);
        selection--;
        if (!is_valid_selection) {
            printf("\nScelta non valida\n");
        }
    } while (!is_valid_selection);
    driver *actual_driver = existing_driver((*valid_rides[selection]).driver_code, drivers, total_drivers);
    
    if (remove_ride(valid_rides[selection], rides, total_rides)) {
        (*actual_driver).total_rides--;
        save_drivers(drivers, total_drivers);
        save_rides(rides, *total_rides);
        printf("Viaggio eliminato con successo!");
    }
}

void show_rides_search(ride rides[], int total_rides, driver drivers[], int total_drivers, passenger passengers[], int total_passengers) {
    if (total_rides == 0) {
        printf("\nNessun viaggio disponibile!\n");
        return;
    }
    ride *find_rides[total_rides];
    int total_find_rides = 0;
    search_rides(rides, total_rides, find_rides, &total_find_rides);
    
    if (!total_find_rides) {
        printf("\nLa ricerca non ha prodotto risultati.\n");
        return;
    }
    
    sort_rides((*find_rides), total_find_rides, drivers, total_drivers);
    print_full_rides((*find_rides), total_find_rides, drivers, total_drivers);
    
    int selection = 0;
    int is_valid_selection = 0;
    do {
        printf("\nInserisci il numero del viaggio che vuoi prenotare: ");
        scanf("%2i", &selection);
        fflush(stdin);
        is_valid_selection = is_included(selection, 1, total_find_rides);
        selection--;
        if (!is_valid_selection) {
            printf("\nScelta non valida\n");
        }
    } while (!is_valid_selection);
    
    passenger *actual_passenger;
    do {
        actual_passenger = find_passenger(passengers, total_passengers);
    } while (actual_passenger == NULL);
    
    if (is_equal_insensitive((*actual_passenger).code, (*find_rides)[selection].driver_code)) {
        printf("\nNon puoi prenotare un viaggio con te stesso!\n");
        return;
    }
    
    strcpy((*find_rides)[selection].passenger_codes[(*find_rides)[selection].total_passenger_codes], (*actual_passenger).code);
    (*find_rides)[selection].total_passenger_codes++;
    save_rides(rides, total_rides);
    printf("Viaggio prenotato con successo!");
}

void show_rides_review(ride rides[], int total_rides, driver drivers[], int total_drivers, passenger passengers[], int total_passengers) {
    passenger *actual_passenger;
    do {
        actual_passenger = find_passenger(passengers, total_passengers);
    } while (actual_passenger == NULL);
    
    ride *find_rides[total_rides];
    int total_find_rides = 0;
    
    for (int i=0; i<total_rides; i++) {
        for (int j=0; j<rides[i].total_passenger_codes; j++) {
            int is_reserved = is_equal_insensitive(rides[i].passenger_codes[j], (*actual_passenger).code);
            int is_review_available = 1;
            
            for (int k=0; k<total_drivers; k++) {
                for (int l=0; l<drivers[k].total_reviews; l++) {
                    if (is_equal_insensitive(drivers[k].reviews[l].passenger_code, (*actual_passenger).code)) {
                        is_review_available = 0;
                        l=drivers[k].total_reviews;
                        k=total_drivers;
                        break;
                    }
                }
            }
            
            if (is_reserved && is_review_available) {
                find_rides[total_find_rides] = &rides[i];
                total_find_rides++;
            }
        }
    }
    
    print_full_rides((*find_rides), total_find_rides, drivers, total_drivers);
    
    int selection = 0;
    int is_valid_selection = 0;
    do {
        printf("\nInserisci il numero del viaggio che vuoi recensire: ");
        scanf("%2i", &selection);
        fflush(stdin);
        is_valid_selection = is_included(selection, 1, total_find_rides);
        selection--;
        if (!is_valid_selection) {
            printf("\nScelta non valida\n");
        }
    } while (!is_valid_selection);
    
    driver *actual_driver = existing_driver((*find_rides)[selection].driver_code, drivers, total_drivers);
    if (actual_driver == NULL) {
        printf("\nERRORE: Il conducente non è stato trovato!\n");
        return;
    }
    
    if (add_review(actual_driver, (*actual_passenger).code)) {
        save_drivers(drivers, total_drivers);
        printf("\nRecensione aggiunta con successo!\n");
    }
}

void print_full_rides(const ride rides[], int total_rides, driver drivers[], int total_drivers) {
    //   |  Ora  | Luogo di Partenza |  Luogo di Arrivo  |  Prezzo |  Valutazione Conducente  |
    // 1.| 08:30 |       Città       |       Città       | € 25,00 |     Alberto S. 4,9/5     |
    
    if (total_rides == 0) {
        printf("\nNessun viaggio disponibile\n");
        return;
    }
    
    printf("\n    _______________________________________________________________________________________________________________________________\n");
    printf("   |  Ora  |         Luogo di Partenza         |          Luogo di Arrivo          |  Prezzo  |       Valutazione Conducente       |\n");

    for (int i=0; i<total_rides; i++) {
        driver *ride_driver = existing_driver(rides[i].driver_code, drivers, total_drivers);
        printf("%2i.| %02hd:%02hd | %-35s |", i+1, rides[i].date.hour, rides[i].date.minutes, rides[i].source.city);
        printf(" %-35s | € %-5.2f |", rides[i].destination.city, rides[i].price);
        char driver_name[NAME_MAX + 3];
        strcat(driver_name, (*ride_driver).name);
        strcat(driver_name, " ");
        strlcat(driver_name, (*ride_driver).surname, 1);
        strcat(driver_name, ".");
        printf(" %-28s %-3.1f/5 |\n", driver_name, driver_rating(ride_driver));
    }

    printf("    -------------------------------------------------------------------------------------------------------------------------------\n");
}
