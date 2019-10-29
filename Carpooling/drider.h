//
//  drider.h
//  Carpooling
//
//  Created by Alberto Saltarelli on 29/10/2019.
//  Copyright © 2019 Alberto Saltarelli. All rights reserved.
//

#ifndef rider_h
#define rider_h

#include <stdio.h>

#ifndef FISCAL_CODE_MAX
#define FISCAL_CODE_MAX 15
#endif

#ifndef NAME_MAX
#define NAME_MAX 25
#endif

#ifndef SURNAME_MAX
#define SURNAME_MAX 25
#endif

#ifndef NOTE_MAX
#define NOTE_MAX 250
#endif

#ifndef REVIEW_MAX
#define REVIEW_MAX 100
#endif

#ifndef hash_code
typedef char hash_code[FISCAL_CODE_MAX];
#endif

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

#endif /* rider_h */
