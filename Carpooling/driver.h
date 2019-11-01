//
//  driver.h
//  Carpooling
//
//  Created by Alberto Saltarelli on 29/10/2019.
//  Copyright © 2019 Alberto Saltarelli. All rights reserved.
//

#ifndef driver_h
#define driver_h

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

#ifndef REVIEW_MAX
#define REVIEW_MAX 101
#endif

#define DRIVERS_MAX 101

#ifndef hash_code
typedef char hash_code[FISCAL_CODE_MAX];
#endif

typedef enum {
    rating_very_poor,
    rating_poor,
    rating_good,
    rating_excellent,
    rating_oustanding
} rating;

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
    unsigned short int total_reviews;
    unsigned int total_rides;
} driver;

int load_drivers(driver drivers[], int count);
driver create_driver(void);
void edit_driver(driver *edit_driver);
int remove_driver(driver *remove_driver, driver drivers[], int *count);
driver *find_driver(driver drivers[], int count);
driver *existing_driver(hash_code driver_code, driver drivers[], int count);
float driver_rating(driver *driver);
void print_toprated_drivers(driver drivers[], int count);
int add_review(driver *driver, hash_code passenger_code);
int contains_driver(driver* new_driver, driver drivers[], int count);
int save_drivers(driver drivers[], int count);

#endif /* driver_h */
