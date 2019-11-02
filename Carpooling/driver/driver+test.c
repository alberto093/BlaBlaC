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
    driver test_driver;
    strcpy(test_driver.code, "sltlrt93c22l109n");

    remove_driver(<#driver *remove_driver#>, <#driver *drivers#>, <#int *count#>)
}

void test_existing_driver(void) {
    
}

void test_driver_rating(void) {
    
}

void test_contains_driver(void) {
    
}

void test_save_drivers(void) {
    
}

