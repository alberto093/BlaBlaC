//
//  ride.c
//  Carpooling
//
//  Created by Alberto Saltarelli on 29/10/2019.
//  Copyright © 2019 Alberto Saltarelli. All rights reserved.
//

#include "ride.h"

int load_rides(ride rides[], int count) {
    FILE *rstream = fopen("/Documents/rides.dat", "rb");
    if (rstream == NULL) {
        return 0;
    }

    int result = (int)fread(rides, sizeof(ride) * count, 1, rstream);
    fclose(rstream);
    return result;
}
