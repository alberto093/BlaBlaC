//
//  utils.h
//  Carpooling
//
//  Created by Alberto Saltarelli on 28/10/2019.
//  Copyright © 2019 Alberto Saltarelli. All rights reserved.
//

#ifndef utils_h
#define utils_h

#define DATE_YEAR_MIN 1900
#define DATE_YEAR_MAX 9999

/**
 This function takes a value in order to make a comparison with a range created by the other two parameters.
 If the lower bound is greater than the upper bound the function returns 0.
 
 @param value value to compare with the range
 @param lower_bound the lower bound of the range
 @param upper_bound the upper bound of the range
 @return It returns 1 (true) if the value is inside the range else 0.
 */
int is_included(int value, int lower_bound, int upper_bound);

/**
 This function validates a date.
 It takes the day, the month and the year and checks all values in order to returns 1 or 0.

 @param day value that represents the day of the date
 @param month that represents the month of the date
 @param year that represents the year of the date
 @return It returns 1 (true) if the date is available in the gregorian calendar else 0.
 */
int is_valid_date(unsigned short int day, unsigned short int month, unsigned short int year);

/**
 This function validates time in 24H format.

 @param hour value that represents the hour
 @param minutes value that represents the minutes
 @return It returns 1 (true) if the time is valid else 0.
 */
int is_valid_time(unsigned short int hour, unsigned short int minutes);

/**
 This function checks if the string provided matches the lenght.

 @param string string value
 @param check_lenght value that is compared with the lenght of the string
 @return It returns 1 (true) if the string's lenght is equal to the lenght provided else 0.
 */
int is_string_lenght(const char string[], int check_lenght);

/**
 This function compares two strings and returns 1 (true) if both strings are the same lower characters.

 @param lhs pointer to a string
 @param rhs pointer to a string
 @return It returns 1 (true) if both strings are the same lower characters else 0.
 */
int is_equal_insensitive(const char lhs[], const char rhs[]);

#endif /* utils_h */
