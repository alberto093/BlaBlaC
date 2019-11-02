//
//  driver+test.c
//  Carpooling
//
//  Created by Alberto Saltarelli on 02/11/2019.
//  Copyright © 2019 Alberto Saltarelli. All rights reserved.
//

#include "driver+test.h"
#include "driver.h"
#include <string.h>
#include "/usr/local/Cellar/cunit/2.1-3/doc/CUnit/headers/Basic.h"

void test_load_drivers(void) {
    int max_drivers = 1;
    driver drivers[max_drivers];
    
    CU_ASSERT_TRUE(load_drivers(drivers, max_drivers));
    CU_ASSERT_FALSE(load_drivers(drivers, 0));
    CU_ASSERT_FALSE(load_drivers(NULL, 0));
}

void test_remove_driver(void) {
    int total_drivers = 1;
    driver drivers[total_drivers];
    driver test_driver;
    strcpy(test_driver.code, "sltlrt93c22l109n");
    drivers[0] = test_driver;
    
    CU_ASSERT_EQUAL(remove_driver(&test_driver, drivers, &total_drivers), 0);
    CU_ASSERT_FALSE(remove_driver(NULL, drivers, &total_drivers));
}

void test_existing_driver(void) {
    
}

void test_driver_rating(void) {
    
}

void test_contains_driver(void) {
    
}

void test_save_drivers(void) {
    
}

