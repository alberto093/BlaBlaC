//
//  ride.h
//  Carpooling
//
//  Created by Alberto Saltarelli on 29/10/2019.
//  Copyright © 2019 Alberto Saltarelli. All rights reserved.
//

#ifndef ride_h
#define ride_h

#include <stdio.h>

#ifndef FISCAL_CODE_MAX
#define FISCAL_CODE_MAX 17
#endif

#define CITY_MAX 36
#define PROVINCE_MAX 26
#define ADDRESS_MAX 51
#define SEATS_MAX 11

#ifndef NOTE_MAX
#define NOTE_MAX 251
#endif

#define MESSAGES_MAX 20

#ifndef hash_code
typedef char hash_code[FISCAL_CODE_MAX];
#endif

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
    unsigned short int total_seats;
    char description[NOTE_MAX];
    char messages[MESSAGES_MAX][NOTE_MAX];
    hash_code passenger_codes[SEATS_MAX];
} ride;

int load_rides(ride rides[], int count);
ride create_ride(hash_code driver_code);
void edit_ride(ride *edit_ride);
int remove_ride(ride *remove_ride, ride rides[], int *count);
ride *find_ride(ride rides[], int count);
ride *existing_ride(hash_code driver_code, place source, place destination, date date, ride rides[], int count);
int contains_ride(ride* new_ride, ride rides[], int count);
int save_rides(ride rides[], int count);

#endif /* ride_h */
