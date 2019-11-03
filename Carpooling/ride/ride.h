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
#include "driver.h"

#ifndef FISCAL_CODE_LEN
#define FISCAL_CODE_LEN 17
#endif

#define CITY_MAX 36
#define PROVINCE_MAX 26
#define ADDRESS_MAX 51
#define SEATS_MAX 10

#ifndef NOTE_MAX
#define NOTE_MAX 251
#endif

#define MESSAGES_MAX 20
#define RIDES_MAX 100

#ifndef hash_code
typedef char hash_code[FISCAL_CODE_LEN]; // Pointer to a char. Should be unique in order to use it as the hash value
#endif

/**
 The ride's place structure. It is composed of the address, the city, the province and the postal code.
 */
typedef struct {
    char city[CITY_MAX];
    char province[PROVINCE_MAX];
    char address[ADDRESS_MAX];
    unsigned int postal_code;
} place;

/**
 The date structure. It is composed of the day, month, year and the time in 24H format.
 */
typedef struct {
    unsigned short int day;
    unsigned short int month;
    unsigned short int year;
    unsigned short int hour; //24H format
    unsigned short int minutes;
} date;

/**
 The ride structure. It is identified by the driver's code, the source place, the destination place, the departure date and the decimal price.
 */
typedef struct {
    hash_code driver_code;
    place source;
    place destination;
    date date;
    float price;
    unsigned short int total_seats;
    char description[NOTE_MAX];
    char messages[MESSAGES_MAX][NOTE_MAX];
    unsigned short int total_messages;
    hash_code passenger_codes[SEATS_MAX];
    unsigned short int total_passenger_codes;
} ride;

/**
 This function load rides from the file using "rb" format by populating the input rides array and returns the total number of the rides.

 @param rides pointer to the ride struct
 @param max_rides the max number of the rides that can be retrived from the file
 @return It returns the total number of the rides.
 */
int load_rides(ride *rides, int max_rides);

/**
 This method using stdin to create and populate a ride struct. It requires a valid driver code. If the relative driver does not exist the function returns an empty ride.

 @param driver_code code of the driver
 @return It returns the created ride struct.
 */
ride create_ride(const hash_code driver_code);

/**
 It takes a pointer to a ride struct in order to edit it by user using stdin.

 @param edit_ride pointer to a ride struct
 */
void edit_ride(ride *edit_ride);

/**
 This method removes the ride provided by the first parameter from the rides array and decrease the value pointed by the count pointer.
 It returns false if the ride was not found in the array.

 @param remove_ride pointer to a ride struct
 @param rides array of ride struct
 @param count pointer to the count of the rides array
 @return It returns 1 if the ride was removed from the input array else 0.
 */
int remove_ride(const ride *remove_ride, ride rides[], int *count);

/**
 This method removes the driver's rides from the rides array and decrease the value pointed by the count pointer.

 @param driver_code code of the driver
 @param rides array of ride struct
 @param count pointer to the count of the rides array
 */
void remove_rides(const hash_code driver_code, ride rides[], int *count);

/**
 It takes an array of rides and the array of drivers in order to improve printing values.
 This function uses a driver provided by the user using stdin and prints its rides in a pretty way, then populates the find_rides array and its count pointer as returning values.

 @param rides array of ride struct
 @param count count of the rides array
 @param drivers array of driver struct
 @param drivers_count count of the drivers array
 @param find_rides pointer to a ride struct that is used as returning value
 @param find_rides_count pointer to a count of the rides array that is used as returning value
 */
void print_rides(ride rides[], int count, driver drivers[], int drivers_count, ride *find_rides[], int *find_rides_count);

/**
 It searches in the input rides array and returns in the other parameters the similar rides that match the user input (stdin).

 @param rides array of ride struct
 @param count count of the rides array
 @param find_rides pointer to a ride struct that is used as returning value
 @param find_rides_count pointer to a count of the rides array that is used as returning value
 */
void search_rides(ride rides[], int count, ride *find_rides[], int *find_rides_count);

/**
 It sorts the input rides array by the price of the ride and the rating of the relative driver.

 @param rides array of ride struct
 @param count count of the rides array
 @param drivers array of driver struct
 @param drivers_count count of the drivers array
 */
void sort_rides(ride rides[], int count, driver drivers[], int drivers_count);

/**
 This function searches into the array of rides and returns 1 if the ride provided by the first parameter was found within the array else 0.

 @param new_ride pointer to a ride struct
 @param rides array of rides struct
 @param count count of the rides array
 @return It returns 1 if the driver was found else 0.
 */
int contains_ride(const ride* new_ride, const ride rides[], int count);

/**
 This function save rides into the file using "wb" and returns 1 if no error occured else 0.

 @param rides array of ride struct are going to be saved
 @param count count of the rides array
 @return It returns 1 if no error occured else 0.
 */
int save_rides(const ride rides[], int count);

#endif /* ride_h */
