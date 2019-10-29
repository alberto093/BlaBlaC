//
//  main.c
//  Carpooling
//
//  Created by Alberto Saltarelli on 28/10/2019.
//  Copyright © 2019 Alberto Saltarelli. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "route.h"

#define FISCAL_CODE_MAX 15
#define NAME_MAX 25
#define SURNAME_MAX 25
#define NOTE_MAX 250
#define REVIEW_MAX 100
#define CITY_MAX 35
#define PROVINCE_MAX 25
#define ADDRESS_MAX 50
#define SEATS_MAX 10

typedef char hash_code[FISCAL_CODE_MAX];

typedef enum {
    very_poor,
    poor,
    good,
    excellent,
    oustanding
} rating;

typedef enum {
    newcomer,
    intermediate,
    experienced,
    expert,
    ambassador
} experience;

typedef struct {
    hash_code passenger_code;
    char text[NOTE_MAX];
    rating rating;
} review;

typedef struct {
    hash_code code;
    char name[NAME_MAX];
    char surname[SURNAME_MAX];
    unsigned short int age;
    char description[NOTE_MAX];
    review reviews[REVIEW_MAX];
    experience experience;
    unsigned int total_rides;
} driver;

typedef struct {
    hash_code code;
    char name[NAME_MAX];
    char surname[SURNAME_MAX];
    unsigned short int age;
    char description[NOTE_MAX];
} passenger;

typedef struct {
    char city[CITY_MAX];
    char province[PROVINCE_MAX];
    char address[ADDRESS_MAX];
    unsigned int postal_code;
} place;

typedef struct {
    unsigned short int day;
    unsigned short int month;
    unsigned short int year;
    unsigned short int hour;
    unsigned short int minutes;
} date;

typedef struct {
    hash_code driver_code;
    place source;
    place destination;
    date date;
    float price;
    char description[NOTE_MAX];
    unsigned short int total_seats;
    hash_code passenger_codes[SEATS_MAX];
} ride;

int main() {
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
                            break;
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
