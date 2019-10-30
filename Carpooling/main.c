//
//  main.c
//  Carpooling
//
//  Created by Alberto Saltarelli on 28/10/2019.
//  Copyright © 2019 Alberto Saltarelli. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"
#include "route.h"
#include "driver.h"
#include "passenger.h"

#define PASSENGERS_MAX 101
#define RIDES_MAX 101

void show_drivers_create(driver drivers[], int *total_drivers);
void show_drivers_edit(driver drivers[], int total_drivers);
void show_drivers_delete(driver drivers[], int *total_drivers);
void show_passengers_create(passenger passengers[], int *total_passengers);
void show_passengers_edit(passenger passengers[], int total_passengers);
void show_passengers_delete(passenger passengers[], int *total_passengers);

int main() {
    driver drivers[DRIVERS_MAX];
    int total_drivers = load_drivers(drivers, DRIVERS_MAX);
    passenger passengers[PASSENGERS_MAX];
    int total_passengers = load_passengers(passengers, PASSENGERS_MAX);
  
    printf("BENVENUTO IN FLAVIA");
    home_result selection = home_drivers;
    
    while (selection != home_exit) {
        selection = show_main_menu();
        
        switch (selection) {
            case home_drivers: {
                drivers_result result = drivers_create;

                while (result != drivers_back) {
                    result = show_driver_menu();
        
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
                            break;
                        case rides_edit:
                            break;
                        case rides_delete:
                            break;
                        case rides_search:
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
    
    return EXIT_SUCCESS;
}

void show_drivers_create(driver drivers[], int *total_drivers) {
    driver new_driver;
    int isValid = 0;
    do {
        new_driver = create_driver();
        isValid = !contains_driver(&new_driver, drivers, *total_drivers);
        if (!isValid) {
            printf("Il conducente con codice fiscale %s è già registrato!\n", new_driver.code);
        }
    } while (!isValid);
    drivers[*total_drivers] = new_driver;
    (*total_drivers)++;
    save_drivers(drivers, *total_drivers);
}

void show_drivers_edit(driver drivers[], int total_drivers) {
    driver *actual_driver = find_driver(drivers, total_drivers);
    if (actual_driver != NULL) {
        edit_driver(actual_driver);
        save_drivers(drivers, total_drivers);
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
            if (!isincluded(selection, 1, 2)) {
                printf("\nScelta non valida!\n");
            }
        } while (!isincluded(selection, 1, 2));
        if (selection == 1 && remove_driver(actual_driver, drivers, total_drivers)) {
            save_drivers(drivers, *total_drivers);
        }
    }
}

void show_passengers_create(passenger passengers[], int *total_passengers) {
    passenger new_passenger;
    int isValid = 0;
    do {
        new_passenger = create_passenger();
        isValid = !contains_passenger(&new_passenger, passengers, *total_passengers);
        if (!isValid) {
            printf("Il passeggero con codice fiscale %s è già registrato!\n", new_passenger.code);
        }
    } while (!isValid);
    passengers[*total_passengers] = new_passenger;
    (*total_passengers)++;
    save_passengers(passengers, *total_passengers);
}

void show_passengers_edit(passenger passengers[], int total_passengers) {
    passenger *actual_passenger = find_passenger(passengers, total_passengers);
    if (actual_passenger != NULL) {
        edit_passenger(actual_passenger);
        save_passengers(passengers, total_passengers);
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
            if (!isincluded(selection, 1, 2)) {
                printf("\nScelta non valida!\n");
            }
        } while (!isincluded(selection, 1, 2));
        if (selection == 1 && remove_passenger(actual_passenger, passengers, total_passengers)) {
            save_passengers(passengers, *total_passengers);
        }
    }
}
