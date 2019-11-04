////
////  driver+test.c
////  Carpooling
////
////  Created by Alberto Saltarelli on 02/11/2019.
////  Copyright © 2019 Alberto Saltarelli. All rights reserved.
////
//
//#include "driver+test.h"
//#include "driver.h"
//#include <string.h>
//#include "/usr/local/Cellar/cunit/2.1-3/doc/CUnit/headers/Basic.h"
//
//void test_load_drivers(void) {
//    int max_drivers = 1;
//    driver drivers[max_drivers];
//    
//    CU_ASSERT_FALSE(load_drivers(drivers, 0));
//    CU_ASSERT_FALSE(load_drivers(NULL, 0));
//}
//
//void test_remove_driver(void) {
//    int total_drivers = 1;
//    driver drivers[total_drivers];
//    driver test_driver;
//    strcpy(test_driver.code, "sltlrt93c22l109n");
//    drivers[0] = test_driver;
//    
//    CU_ASSERT_TRUE(remove_driver(&test_driver, drivers, &total_drivers));
//    CU_ASSERT_EQUAL(total_drivers, 0);
//    CU_ASSERT_FALSE(remove_driver(NULL, drivers, &total_drivers));
//}
//
//void test_existing_driver(void) {
//    int total_drivers = 1;
//    driver drivers[total_drivers];
//    driver test_driver;
//    
//    strcpy(test_driver.code, "sltlrt93c22l109n");
//    CU_ASSERT_EQUAL(existing_driver(test_driver.code, drivers, total_drivers), &test_driver);
//    CU_ASSERT_EQUAL(existing_driver(NULL, NULL, 0), NULL);
//    
//    strcpy(drivers[0].code, "");
//    CU_ASSERT_EQUAL(existing_driver(test_driver.code, drivers, total_drivers), NULL);
//}
//
//void test_driver_rating(void) {
//    driver test_driver;
//    test_driver.total_reviews = 0;
//    CU_ASSERT_EQUAL(driver_rating(NULL), 0);
//    CU_ASSERT_EQUAL(driver_rating(&test_driver), 0);
//    
//    test_driver.total_reviews = 5;
//    test_driver.reviews[0].rating = rating_good;
//    test_driver.reviews[1].rating = rating_poor;
//    test_driver.reviews[2].rating = rating_oustanding;
//    test_driver.reviews[3].rating = rating_good;
//    test_driver.reviews[4].rating = rating_excellent;
//    CU_ASSERT_DOUBLE_EQUAL(driver_rating(&test_driver), 3.4, 0.1);
//}
//
//void test_contains_driver(void) {
//    int total_drivers = 1;
//    driver drivers[total_drivers];
//    driver test_driver;
//    
//    strcpy(test_driver.code, "sltlrt93c22l109n");
//    CU_ASSERT(contains_driver(&test_driver, drivers, total_drivers))
//    CU_ASSERT_FALSE(contains_driver(NULL, NULL, 0));
//    
//    strcpy(drivers[0].code, "");
//    CU_ASSERT_FALSE(contains_driver(&test_driver, drivers, total_drivers));
//}
//
//void test_save_drivers(void) {
//    int max_drivers = 1;
//    driver drivers[max_drivers];
//    
//    CU_ASSERT_TRUE(save_drivers(drivers, max_drivers));
//    CU_ASSERT_TRUE(save_drivers(drivers, 0));
//    CU_ASSERT_FALSE(save_drivers(NULL, 0));
//}
//
