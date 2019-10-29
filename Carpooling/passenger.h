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

#ifndef FISCAL_CODE_MAX
#define FISCAL_CODE_MAX 17
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

#ifndef hash_code
typedef char hash_code[FISCAL_CODE_MAX];
#endif

typedef struct {
    hash_code code;
    char name[NAME_MAX];
    char surname[SURNAME_MAX];
    unsigned short int age;
    char description[NOTE_MAX];
} passenger;

int load_passengers(passenger passengers[], int count);

#endif /* passenger_h */
