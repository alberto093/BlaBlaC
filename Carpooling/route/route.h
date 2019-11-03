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

/**
 The home menu options.
 Values of the enum goes by 0 to 4. It is intended to be used to evaluate the user input in the home menu.
 */
typedef enum {
    home_drivers,
    home_passengers,
    home_rides,
    home_exit
} home_result;

/**
 The drivers menu options.
 Values of the enum goes by 0 to 4. It is intended to be used to evaluate the user input in the drivers menu.
 */
typedef enum {
    drivers_create,
    drivers_edit,
    drivers_delete,
    drivers_list,
    drivers_back
} drivers_result;

/**
 The passengers menu options.
 Values of the enum goes by 0 to 4. It is intended to be used to evaluate the user input in the passengers menu.
 */
typedef enum {
    passengers_create,
    passengers_edit,
    passengers_delete,
    passengers_review,
    passengers_back
} passengers_result;

/**
 The rides menu options.
 Values of the enum goes by 0 to 4. It is intended to be used to evaluate the user input in the rides menu.
 */
typedef enum {
    rides_create,
    rides_edit,
    rides_delete,
    rides_search,
    rides_back
} rides_result;

/**
 This method prints the home menu options and returns the user's choiche.

 @return A value in a range goes by home_drivers (0) to home_exit (4).
 */
home_result show_main_menu(void);

/**
 This method prints the drivers menu options and returns the user's choiche.

 @return A value in a range goes by drivers_create (0) to drivers_back (4).
 */
drivers_result show_drivers_menu(void);

/**
 This method prints the passengers menu options and returns the user's choiche.

 @return A value in a range goes by passengers_create (0) to passengers_back (3).
 */
passengers_result show_passengers_menu(void);

/**
 This method prints the rides menu options and returns the user's choiche.

 @return A value in a range goes by rides_create (0) to rides_back (5).
 */
rides_result show_rides_menu(void);

#endif /* route_h */
