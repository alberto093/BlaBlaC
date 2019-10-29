//
//  drider.c
//  Carpooling
//
//  Created by Alberto Saltarelli on 29/10/2019.
//  Copyright © 2019 Alberto Saltarelli. All rights reserved.
//

#include "drider.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    new_driver.experience = experience_newcomer;
    new_driver.total_rides = 0;
    return new_driver;
}

int contains_driver(driver* new_driver, driver drivers[], int count) {
    for (int i=0; i<count; i++) {
        if (strcmp(drivers[i].code, (*new_driver).code) == 0) {
            return 1;
        }
    }
    return 0;
}

int save_drivers(driver drivers[], int count) {
    FILE *wstream = fopen("/Users/Alberto/Università/Informatica/I anno/Laboratorio di Informatica/BlaBlaC/Carpooling/drivers.dat", "wb");
    if (wstream == NULL) {
        return 0;
    }
    
    fwrite(drivers, sizeof(driver) * count, 1, wstream);
    return !fclose(wstream);
}
