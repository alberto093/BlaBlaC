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
#include "route.h"
#include "drider.h"

#define DRIVERS_MAX 101
#define PASSENGERS_MAX 101
#define RIDES_MAX 101

int main() {
    driver drivers[DRIVERS_MAX];
    int total_drivers = load_drivers(drivers, DRIVERS_MAX);
  
    for (int i = 0; i<total_drivers; i++) {
        printf("%s\n", drivers[i].code);
    }
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
                        case drivers_create: {
                            driver new_driver;
                            int isValid = 0;
                            do {
                                new_driver = create_driver();
                                isValid = !contains_driver(&new_driver, drivers, total_drivers);
                                if (!isValid) {
                                    printf("Il conducente con codice fiscale %s è già registrato!\n", new_driver.code);
                                }
                            } while (!isValid);
                            drivers[total_drivers] = new_driver;
                            total_drivers++;
                            save_drivers(drivers, total_drivers);
                            break;
                        }
                        case drivers_edit:
                            break;
                        case drivers_delete:
                            break;
                        case drivers_list:
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
                            break;
                        case passengers_edit:
                            break;
                        case passengers_delete:
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
