//
//  ride+test.c
//  Carpooling
//
//  Created by Alberto Saltarelli on 02/11/2019.
//  Copyright © 2019 Alberto Saltarelli. All rights reserved.
//

#include "ride+test.h"
#include <stdlib.h>
#include "driver.h"
#include "ride.h"
#include "/usr/local/Cellar/cunit/2.1-3/doc/CUnit/headers/Basic.h"

driver create_driver_with(hash_code code, rating ratings[], int total_ratings);
ride create_ride_with(hash_code driver_code, float price);

void test_load_rides(void) {
    int max_rides = 1;
    ride rides[max_rides];
    
    CU_ASSERT_FALSE(load_rides(rides, 0));
    CU_ASSERT_FALSE(load_rides(NULL, 0));
}

void test_remove_ride(void) {
    int total_rides = 1;
    ride rides[total_rides];
    ride test_ride;
    strcpy(test_ride.driver_code, "sltlrt93c22l109n");

    strcpy(test_ride.source.address, "Via di Morena 144");
    strcpy(test_ride.source.city, "Ciampino");
    strcpy(test_ride.source.province, "Roma");
    test_ride.source.postal_code = 43;

    strcpy(test_ride.destination.address, "Via tenente Silvestri 56");
    strcpy(test_ride.destination.city, "Molfetta");
    strcpy(test_ride.destination.province, "Bari");
    test_ride.source.postal_code = 70056;
    
    test_ride.date.day = 12;
    test_ride.date.month = 11;
    test_ride.date.year = 2019;
    test_ride.date.hour = 9;
    test_ride.date.minutes = 0;
    
    CU_ASSERT_FALSE(remove_ride(&test_ride, rides, &total_rides));
    
    rides[0] = test_ride;
    CU_ASSERT_EQUAL(remove_ride(&test_ride, rides, &total_rides), 0);
    CU_ASSERT_EQUAL(total_rides, 0);
    CU_ASSERT_FALSE(remove_ride(NULL, rides, &total_rides));
}

void test_sort_rides(void) {
    const int total_ratings1 = 4;
    const int total_ratings2 = 3;
    const int total_ratings3 = 2;
    rating ratings1[total_ratings1] = {rating_excellent, rating_oustanding, rating_oustanding, rating_excellent}; // 4.5
    rating ratings2[total_ratings2] = {rating_poor, rating_oustanding, rating_good}; // 3.3
    rating ratings3[total_ratings3] = {rating_good, rating_very_poor}; // 2
    
    hash_code code1 = "sltlrt93c22l109n";
    hash_code code2 = "ctnflv92h48g113v";
    hash_code code3 = "sltgnn51a07l109k";
    driver driver1 = create_driver_with(code1, ratings1, total_ratings1);
    driver driver2 = create_driver_with(code2, ratings2, total_ratings2);
    driver driver3 = create_driver_with(code3, ratings3, total_ratings3);
    driver drivers[3] = {driver1, driver2, driver3};
    
    ride ride1 = create_ride_with(code1, 25);
    ride ride2 = create_ride_with(code2, 20);
    ride ride3 = create_ride_with(code3, 15);
    ride ride4 = create_ride_with(code1, 13);
    ride ride5 = create_ride_with(code2, 20);
    ride ride6 = create_ride_with(code3, 25);
    ride ride7 = create_ride_with(code1, 20);
    ride ride8 = create_ride_with(code2, 15);
    ride ride9 = create_ride_with(code3, 20);
    ride rides[9] = {ride1, ride2, ride3, ride4, ride5, ride6, ride7, ride8, ride9};
    
    ride sorted_rides[9] = {ride4, ride8, ride3, ride7, ride2, ride5, ride9, ride1, ride6};
    sort_rides(rides, 9, drivers, 3);
    
    CU_ASSERT_EQUAL(rides, sorted_rides);
}

void test_contains_ride(void) {
    int total_rides = 1;
    ride rides[total_rides];
    ride test_ride;
    strcpy(test_ride.driver_code, "sltlrt93c22l109n");
    
    strcpy(test_ride.source.address, "Via di Morena 144");
    strcpy(test_ride.source.city, "Ciampino");
    strcpy(test_ride.source.province, "Roma");
    test_ride.source.postal_code = 43;
    
    strcpy(test_ride.destination.address, "Via tenente Silvestri 56");
    strcpy(test_ride.destination.city, "Molfetta");
    strcpy(test_ride.destination.province, "Bari");
    test_ride.source.postal_code = 70056;
    
    test_ride.date.day = 12;
    test_ride.date.month = 11;
    test_ride.date.year = 2019;
    test_ride.date.hour = 9;
    test_ride.date.minutes = 0;
    
    CU_ASSERT_FALSE(contains_ride(NULL, NULL, 0));
    CU_ASSERT_FALSE(contains_ride(&test_ride, rides, total_rides));
    
    rides[0] = test_ride;
    CU_ASSERT_TRUE(contains_ride(&test_ride, rides, total_rides));
}

void test_save_rides(void) {
    int max_rides = 1;
    ride rides[max_rides];
    
    CU_ASSERT_TRUE(save_rides(rides, max_rides));
    CU_ASSERT_TRUE(save_rides(rides, 0));
    CU_ASSERT_FALSE(save_rides(NULL, 0));
}

driver create_driver_with(hash_code code, rating ratings[], int total_ratings) {
    driver new_driver;
    strcpy(new_driver.code, code);
    review reviews[total_ratings];
    
    for (int i=0; i<total_ratings; i++) {
        reviews[i].rating = ratings[i];
    }
    new_driver.total_reviews = total_ratings;
    return new_driver;
}

ride create_ride_with(hash_code driver_code, float price) {
    ride new_ride;
    strcpy(new_ride.driver_code, driver_code);
    new_ride.price = price;
    return new_ride;
}
