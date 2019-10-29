//
//  passenger.c
//  Carpooling
//
//  Created by Alberto Saltarelli on 29/10/2019.
//  Copyright © 2019 Alberto Saltarelli. All rights reserved.
//

#include "passenger.h"

int load_passengers(passenger passengers[], int count) {
    FILE *rstream = fopen("/Documents/passengers.dat", "rb");
    if (rstream == NULL) {
        return 0;
    }

    int result = (int)fread(passengers, sizeof(passenger) * count, 1, rstream);
    fclose(rstream);
    return result;
}
