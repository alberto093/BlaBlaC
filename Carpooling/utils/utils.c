//
//  utils.c
//  Carpooling
//
//  Created by Alberto Saltarelli on 28/10/2019.
//  Copyright © 2019 Alberto Saltarelli. All rights reserved.
//

#include "utils.h"
#include <string.h>
#include <ctype.h>

int is_leap(int year);

int is_included(int value, int lower_bound, int upper_bound) {
    if (lower_bound <= upper_bound) {
        return value >= lower_bound && value <= upper_bound;
    } else {
        return 0;
    }
}

int is_valid_date(unsigned short int day, unsigned short int month, unsigned short int year) {
    int is_valid_year = is_included(year, DATE_YEAR_MIN, DATE_YEAR_MAX);
    int is_valid_month = is_included(month, 1, 12);
    int is_valid_day = is_included(month, 1, 31);
    
    if (!is_valid_day || !is_valid_month || !is_valid_year) {
        return 0;
    }
    
    if (month == 2) {
        return is_leap(year) ? day <= 29 : day <= 28;
    }
    
    if (month == 4 || month == 6 || month == 9 || month == 11) {
        return day <= 30;
    }
    return 1;
}

int is_valid_time(unsigned short int hour, unsigned short int minutes) {
    return is_included(hour, 0, 23) && is_included(minutes, 0, 59);
}

int is_string_lenght(const char string[], int check_lenght) {
    if (string == NULL) {
        return 0;
    }
    return strlen(string) == check_lenght;
}

int is_equal_insensitive(const char lhs[], const char rhs[]) {
    if (lhs == NULL || rhs == NULL) {
        return 0;
    }
    unsigned long lhs_len = strlen(lhs);

    if (strlen(rhs) != lhs_len) {
        return 0;
    }
    
    for (int i=0; i<lhs_len; i++) {
        if (tolower(lhs[i] != tolower(rhs[i]))) {
            return 0;
        }
    }
    return 1;
}

int is_leap(int year) {
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}
