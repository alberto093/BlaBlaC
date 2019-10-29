//
//  utils.c
//  Carpooling
//
//  Created by Alberto Saltarelli on 28/10/2019.
//  Copyright © 2019 Alberto Saltarelli. All rights reserved.
//

#include "utils.h"

int isincluded(int value, int lower_bound, int upper_bound) {
    if (lower_bound <= upper_bound) {
        return value >= lower_bound && value <= upper_bound;
    } else {
        return 0;
    }
}
