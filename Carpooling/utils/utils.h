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

int is_included(int value, int lower_bound, int upper_bound);
int is_valid_date(unsigned short int day, unsigned short int month, unsigned short int year);
int is_valid_time(unsigned short int hour, unsigned short int minutes);
int is_string_lenght(const char string[], int check_lenght);
int is_equal_insensitive(const char lhs[], const char rhs[]);

#endif /* utils_h */
