////
////  unittest.c
////  Carpooling
////
////  Created by Alberto Saltarelli on 02/11/2019.
////  Copyright © 2019 Alberto Saltarelli. All rights reserved.
////
//
//#include "unittest.h"
//#include "/usr/local/Cellar/cunit/2.1-3/doc/CUnit/headers/Basic.h"
//#include "utils+test.h"
//#include "driver+test.h"
//#include "passenger+test.h"
//#include "ride+test.h"
//
///**
// Creates a new utils test suite in which utils' tests are added and adds it to the environment test registry
// */
//void create_utils_suite(void);
//
///**
//  Creates a new drivers test suite in which drivers' tests are added and adds it to the environment test registry
// */
//void create_drivers_suite(void);
//
///**
//  Creates a new passengers test suite in which passengers' tests are added and adds it to the environment test registry
// */
//void create_passengers_suite(void);
//
///**
//  Creates a new rides test suite in which rides' tests are added and adds it to the environment test registry
// */
//void create_rides_suite(void);
//
///**
// This method is called by a test suite before it's begin in order to initialize the test state.
// Default implementation does nothing and returns 0.
// 
// @return exit code to the current suite
// */
//int init_suite_default(void);
//
///**
// This method is called by a test suite after it's end in order to clean the test state.
// Default implementation does nothing and returns 0.
// 
// @return exit code to the current suite
// */
//int clean_suite_default(void);
//
//int run_all_tests(void) {
//    CU_initialize_registry();
//    create_utils_suite();
//    create_drivers_suite();
//    create_passengers_suite();
//    create_rides_suite();
//    
//    CU_basic_set_mode(CU_BRM_VERBOSE);
//    CU_basic_run_tests();
//    CU_cleanup_registry();
//    return CU_get_error();
//}
//
//void create_utils_suite(void) {
//    CU_pSuite suite_utils = CU_add_suite("Suite Utils", init_suite_default, clean_suite_default);
//    
//    CU_add_test(suite_utils, "test of is_included", test_is_included);
//    CU_add_test(suite_utils, "test of is_valid_date", test_is_valid_date);
//    CU_add_test(suite_utils, "test of is_valid_time", test_is_valid_time);
//    CU_add_test(suite_utils, "test of is_string_lenght", test_is_string_lenght);
//    CU_add_test(suite_utils, "test of is_equal_insensitive", test_is_equal_insensitive);
//}
//
//void create_drivers_suite(void) {
//    CU_pSuite suite_drivers = CU_add_suite("Suite Drivers", init_suite_default, clean_suite_default);
//    
//    CU_add_test(suite_drivers, "test of load_drivers", test_load_drivers);
//    CU_add_test(suite_drivers, "test of remove_drivers", test_remove_driver);
//    CU_add_test(suite_drivers, "test of existing_driver", test_existing_driver);
//    CU_add_test(suite_drivers, "test of driver_rating", test_driver_rating);
//    CU_add_test(suite_drivers, "test of contains_driver", test_contains_driver);
//    CU_add_test(suite_drivers, "test of save_drivers", test_save_drivers);
//}
//
//void create_passengers_suite(void) {
//    CU_pSuite suite_passengers = CU_add_suite("Suite Passengers", init_suite_default, clean_suite_default);
//    
//    CU_add_test(suite_passengers, "test of load_passengers", test_load_passengers);
//    CU_add_test(suite_passengers, "test of remove_passenger", test_remove_passenger);
//    CU_add_test(suite_passengers, "test of existing_passenger", test_existing_passenger);
//    CU_add_test(suite_passengers, "test of contains_passenger", test_contains_passenger);
//    CU_add_test(suite_passengers, "test of save_passengers", test_save_passengers);
//}
//
//void create_rides_suite(void) {
//    CU_pSuite suite_rides = CU_add_suite("Suite Rides", init_suite_default, clean_suite_default);
//    
//    CU_add_test(suite_rides, "test of load_rides", test_load_rides);
//    CU_add_test(suite_rides, "test of remove_ride", test_remove_ride);
//    CU_add_test(suite_rides, "test of sort_rides", test_sort_rides);
//    CU_add_test(suite_rides, "test of contains_ride", test_contains_ride);
//    CU_add_test(suite_rides, "test of save_rides", test_save_rides);
//}
//
//int init_suite_default(void) {
//    return 0;
//}
//
//int clean_suite_default(void) {
//    return 0;
//}
