////
////  passenger+test.c
////  Carpooling
////
////  Created by Alberto Saltarelli on 02/11/2019.
////  Copyright © 2019 Alberto Saltarelli. All rights reserved.
////
//
//#include "passenger+test.h"
//#include "passenger.h"
//#include "/usr/local/Cellar/cunit/2.1-3/doc/CUnit/headers/Basic.h"
//
//void test_load_passengers(void) {
//    int max_passengers = 1;
//    passenger passengers[max_passengers];
//    
//    CU_ASSERT_FALSE(load_passengers(passengers, 0));
//    CU_ASSERT_FALSE(load_passengers(NULL, 0));
//}
//
//void test_remove_passenger(void) {
//    int total_passengers = 1;
//    passenger passengers[total_passengers];
//    passenger test_passenger;
//    strcpy(test_passenger.code, "sltlrt93c22l109n");
//    passengers[0] = test_passenger;
//    
//    CU_ASSERT_EQUAL(remove_passenger(&test_passenger, passengers, &total_passengers), 0);
//    CU_ASSERT_EQUAL(total_passengers, 0);
//    CU_ASSERT_FALSE(remove_passenger(NULL, passengers, &total_passengers));
//}
//
//void test_existing_passenger(void) {
//    int total_passengers = 1;
//    passenger passengers[total_passengers];
//    passenger test_passenger;
//    
//    strcpy(test_passenger.code, "sltlrt93c22l109n");
//    CU_ASSERT_EQUAL(existing_passenger(test_passenger.code, passengers, total_passengers), &test_passenger);
//    CU_ASSERT_EQUAL(existing_passenger(NULL, NULL, 0), NULL);
//    
//    strcpy(passengers[0].code, "");
//    CU_ASSERT_EQUAL(existing_passenger(test_passenger.code, passengers, total_passengers), NULL);
//}
//
//void test_contains_passenger(void) {
//    int total_passengers = 1;
//    passenger passengers[total_passengers];
//    passenger test_passenger;
//    
//    strcpy(test_passenger.code, "sltlrt93c22l109n");
//    CU_ASSERT(contains_passenger(&test_passenger, passengers, total_passengers));
//    CU_ASSERT_FALSE(contains_passenger(NULL, NULL, 0));
//    
//    strcpy(passengers[0].code, "");
//    CU_ASSERT_FALSE(contains_passenger(&test_passenger, passengers, total_passengers));
//}
//
//void test_save_passengers(void) {
//    int max_passengers = 1;
//    passenger passengers[max_passengers];
//    
//    CU_ASSERT_TRUE(save_passengers(passengers, max_passengers));
//    CU_ASSERT_TRUE(save_passengers(passengers, 0));
//    CU_ASSERT_FALSE(save_passengers(NULL, 0));
//}
//
