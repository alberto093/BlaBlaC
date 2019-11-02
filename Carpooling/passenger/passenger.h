//
//  passenger.h
//  Carpooling
//
//  Created by Alberto Saltarelli on 29/10/2019.
//  Copyright © 2019 Alberto Saltarelli. All rights reserved.
//

#ifndef passenger_h
#define passenger_h

#include <stdio.h>

#ifndef FISCAL_CODE_LEN
#define FISCAL_CODE_LEN 17
#endif

#ifndef NAME_MAX
#define NAME_MAX 26
#endif

#ifndef SURNAME_MAX
#define SURNAME_MAX 26
#endif

#ifndef NOTE_MAX
#define NOTE_MAX 251
#endif

#define PASSENGERS_MAX 100

#ifndef hash_code
typedef char hash_code[FISCAL_CODE_LEN]; // Pointer to a char. Should be unique in order to use it as the hash value
#endif

/**
 The passenger structure. The code should be unique in order to identify a passenger within a collection.
 */
typedef struct {
    hash_code code;
    char name[NAME_MAX];
    char surname[SURNAME_MAX];
    unsigned short int age;
    char description[NOTE_MAX];
} passenger;

/**
 This function load passengers from the file using "ab" format by populating the input passenger array and returns the total number of the passengers.

 @param passengers pointer to the passenger struct
 @param max_passengers the max number of the passengers that can be retrived from the file
 @return It returns the total number of the passengers
 */
int load_passengers(passenger *passengers, int max_passengers);

/**
 This method using stdin to create and populate a passenger struct.

 @return It returns the created passenger struct
 */
passenger create_passenger(void);

/**
 It takes a pointer to a passenger struct in order to edit it by user using stdin.

 @param edit_passenger pointer to a passenger struct
 */
void edit_passenger(passenger *edit_passenger);

/**
 This method removes the passenger provided by the first parameter from the passengers array and decrease the value pointed by the count pointer.
 It returns false if the passenger was not found in the array.

 @param remove_passenger pointer to a passenger struct
 @param passengers array of passenger struct
 @param count count of the passengers array
 @return It returns 1 if the passenger was removed from the input array else 0.
 */
int remove_passenger(passenger *remove_passenger, passenger passengers[], int *count);

/**
 This method takes an array of passengers and its count and returns a pointer to the passenger was selected by the user using stdin.

 @param passengers array of passenger struct
 @param count count of the passengers array
 @return It returns a pointer to the selected passenger
 */
passenger *find_passenger(passenger passengers[], int count);

/**
 This function requires the passenger's code, an array of passengers and its count in order to find the passenger who match the input code.

 @param passenger_code code of the passenger
 @param passengers array of passenger struct
 @param count count of the passengers array
 @return It returns a pointer to the found passenger
 */
passenger *existing_passenger(hash_code passenger_code, passenger passengers[], int count);

/**
 This function searches into the array of passengers and returns 1 if the passenger provided by the first parameter was found within the array else 0.

 @param new_passenger pointer to a passenger struct
 @param passengers array of passenger struct
 @param count count of the passengers array
 @return It returns 1 if the passenger was found else 0.
 */
int contains_passenger(passenger* new_passenger, passenger passengers[], int count);

/**
 This function save passengers into the file using "wb" and returns 1 if no error occured else 0.

 @param passengers array of passenger struct are going to be saved
 @param count count of the passengers array
 @return It returns 1 if no error occured else 0.
 */
int save_passengers(passenger passengers[], int count);

#endif /* passenger_h */
