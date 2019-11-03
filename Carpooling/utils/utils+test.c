////
////  utils+test.c
////  Carpooling
////
////  Created by Alberto Saltarelli on 02/11/2019.
////  Copyright © 2019 Alberto Saltarelli. All rights reserved.
////
//
//#include "utils+test.h"
//#include "utils.h"
//#include "/usr/local/Cellar/cunit/2.1-3/doc/CUnit/headers/Basic.h"
//
//void test_is_included(void)  {
//    CU_ASSERT_TRUE(is_included(0, -10, 10));
//    CU_ASSERT_FALSE(is_included(10, -10, 0));
//}
//
//void test_is_valid_date(void)  {
//    CU_ASSERT_TRUE(is_valid_date(01, 01, DATE_YEAR_MIN));
//    CU_ASSERT_TRUE(is_valid_date(22, 03, DATE_YEAR_MAX));
//    CU_ASSERT_TRUE(is_valid_date(29, 02, 2020));
//    CU_ASSERT_TRUE(is_valid_date(29, 02, 2020));
//    CU_ASSERT_FALSE(is_valid_date(32, 13, 2019));
//    CU_ASSERT_FALSE(is_valid_date(0, -1, 1));
//}
//
//void test_is_valid_time(void)  {
//    CU_ASSERT_TRUE(is_valid_time(23, 59));
//    CU_ASSERT_TRUE(is_valid_time(0, 0));
//    CU_ASSERT_FALSE(is_valid_time(12, 100));
//    CU_ASSERT_FALSE(is_valid_time(100, 0));
//}
//
//void test_is_string_lenght(void)  {
//    CU_ASSERT_TRUE(is_string_lenght("alberto", 7));
//    CU_ASSERT_TRUE(is_string_lenght("", 0));
//    CU_ASSERT_FALSE(is_string_lenght("saltarelli", 11));
//    CU_ASSERT_FALSE(is_string_lenght(NULL, 0));
//}
//
//void test_is_equal_insensitive(void) {
//    CU_ASSERT_TRUE(is_equal_insensitive("AlBerto", "alberto"));
//    CU_ASSERT_TRUE(is_equal_insensitive("123", "123"));
//    CU_ASSERT_TRUE(is_equal_insensitive("", ""));
//    CU_ASSERT_FALSE(is_equal_insensitive("alberto", "saltarelli"));
//    CU_ASSERT_FALSE(is_equal_insensitive(NULL, ""));
//}
