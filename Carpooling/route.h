//
//  route.h
//  Carpooling
//
//  Created by Alberto Saltarelli on 29/10/2019.
//  Copyright © 2019 Alberto Saltarelli. All rights reserved.
//

#ifndef route_h
#define route_h

#include <stdio.h>

typedef enum {
    home_drivers,
    home_passengers,
    home_rides,
    home_exit
} home_result;

typedef enum {
    drivers_create,
    drivers_edit,
    drivers_delete,
    drivers_list,
    drivers_back
} drivers_result;

typedef enum {
    passengers_create,
    passengers_edit,
    passengers_delete,
    passengers_back
} passengers_result;

typedef enum {
    rides_create,
    rides_edit,
    rides_delete,
    rides_search,
    rides_review,
    rides_back
} rides_result;

home_result show_main_menu(void);
drivers_result show_driver_menu(void);
passengers_result show_passengers_menu(void);
rides_result show_rides_menu(void);

#endif /* route_h */
