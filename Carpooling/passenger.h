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
typedef char hash_code[FISCAL_CODE_LEN];
#endif

typedef struct {
    hash_code code;
    char name[NAME_MAX];
    char surname[SURNAME_MAX];
    unsigned short int age;
    char description[NOTE_MAX];
} passenger;

int load_passengers(passenger passengers[], int count);
passenger create_passenger(void);
void edit_passenger(passenger *edit_passenger);
int remove_passenger(passenger *remove_passenger, passenger passengers[], int *count);
passenger *find_passenger(passenger passengers[], int count);
passenger *existing_passenger(hash_code passenger_code, passenger passengers[], int count);
int contains_passenger(passenger* new_passenger, passenger passengers[], int count);
int save_passengers(passenger passengers[], int count);

#endif /* passenger_h */
