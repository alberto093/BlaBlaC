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

#ifndef REVIEW_MAX
#define REVIEW_MAX 101
#endif

#define DRIVERS_MAX 100

#ifndef hash_code
typedef char hash_code[FISCAL_CODE_LEN]; // Pointer to a char. Should be unique in order to use it as the hash value
#endif

/**
 The driver's rating options.
 Values of the enum goes by 1 to 5. It is intended to be used to rate a driver with a finite range of values.
 */
typedef enum {
    rating_very_poor = 1,
    rating_poor,
    rating_good,
    rating_excellent,
    rating_oustanding
} rating;

/**
 The driver's review structure. It is composed of the passenger's code, the rating value (enum) and the message.
 */
typedef struct {
    hash_code passenger_code;
    char text[NOTE_MAX];
    rating rating;
} review;

/**
 The driver structure. The code should be unique in order to identify a driver within a collection.
 */
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

/**
 This function load drivers from the file using "ab" format by populating the input drivers array and returns the total number of the drivers.

 @param drivers pointer to the driver struct
 @param max_drivers the max number of the drivers that can be retrived from the file
 @return It returns the total number of the drivers.
 */
int load_drivers(driver *drivers, int max_drivers);

/**
 This method using stdin to create and populate a driver struct.

 @return It returns the created driver struct.
 */
driver create_driver(void);

/**
 It takes a pointer to a driver struct in order to edit it by user using stdin.

 @param edit_driver pointer to a driver struct
 */
void edit_driver(driver *edit_driver);

/**
 This method removes the driver provided by the first parameter from the drivers array and decrease the value pointed by the count pointer.
 It returns false if the driver was not found in the array.

 @param remove_driver pointer to a driver struct
 @param drivers array of driver struct
 @param count count of the drivers array
 @return It returns 1 if the driver was removed from the input array else 0.
 */
int remove_driver(const driver *remove_driver, driver drivers[], int *count);

/**
 This method takes an array of drivers and its count and returns a pointer to the driver was selected by the user using stdin.

 @param drivers array of driver struct
 @param count count of the drivers array
 @return It returns a pointer to the selected driver
 */
driver *find_driver(driver drivers[], int count);

/**
 This function requires the driver's code, an array of drivers and its count in order to find the driver who match the input code.

 @param driver_code code of the driver
 @param drivers array of driver struct
 @param count count of the drivers array
 @return It returns a pointer to the found driver
 */
driver *existing_driver(const hash_code driver_code, driver drivers[], int count);

/**
 This function calculate the average of the ratings of the provided driver. It returns 0 if the driver has not any reviews.

 @param driver pointer to a driver struct
 @return It returns the average of the driver's reviews.
 */
float driver_rating(const driver *driver);

/**
 It takes an array of drivers and its count in order to filter the drivers who has the highest rating and prints them in a pretty way.

 @param drivers array of driver struct
 @param count count of the drivers array
 */
void print_toprated_drivers(const driver drivers[], int count);

/**
 It takes a pointer to a driver struct and a passenger's code in order to populate a review struct by stdin and adds it to array of reviews of the driver pointed.
 At the end of function the total reviews of the driver is increased by one.
 It returns 0 if the pointer is NULL or the user exit from the menu.

 @param driver pointer to a driver struct
 @param passenger_code code of the passenger who leave the review
 @return It returns the value of the rating
 */
int add_review(driver *driver, const hash_code passenger_code);

/**
 This function searches into the array of drivers and returns 1 if the driver provided by the first parameter was found within the array else 0.

 @param new_driver pointer to a driver struct
 @param drivers array of driver struct
 @param count count of the drivers array
 @return It returns 1 if the driver was found else 0.
 */
int contains_driver(const driver* new_driver, driver drivers[], int count);

/**
 This function save drivers into the file using "wb" and returns 1 if no error occured else 0.

 @param drivers array of driver struct are going to be saved
 @param count count of the drivers array
 @return It returns 1 if no error occured else 0.
 */
int save_drivers(const driver drivers[], int count);

#endif /* driver_h */
