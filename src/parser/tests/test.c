#include <check.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "../s21_parser.h"

START_TEST(parser_array) {
    indexes a;
    main_parser("parser/tests/test.obj", &a);
    ck_assert_float_eq_tol(a.array[0], 4, 1e-6);
    ck_assert_float_eq_tol(a.array[1], 0, 1e-6);
    ck_assert_float_eq_tol(a.array[2], 1, 1e-6);
    ck_assert_float_eq_tol(a.array[3], 2, 1e-6);
    ck_assert_float_eq_tol(a.array[4], 2, 1e-6);
    ck_assert_float_eq_tol(a.array[5], 4, 1e-6);

    free(a.array);
    free(a.indexess);
}
END_TEST

START_TEST(parser_polygon) {
  indexes a;
    main_parser("parser/tests/test.obj", &a);

  ck_assert_uint_eq(a.indexess[0], 1);
  ck_assert_uint_eq(a.indexess[1], 2);
  ck_assert_uint_eq(a.indexess[2], 2);
  ck_assert_uint_eq(a.indexess[3], 1);
  ck_assert_uint_eq(a.indexess[4], 2);
  ck_assert_uint_eq(a.indexess[5], 1);
  ck_assert_uint_eq(a.indexess[6], 1);
  ck_assert_uint_eq(a.indexess[7], 2);

  free(a.array);
  free(a.indexess);
}
END_TEST


Suite *s21_3d_suite(void) {
    Suite *suite;

    suite = suite_create("s21_3d");
    TCase *tcase_core = tcase_create("Core");

    tcase_add_test(tcase_core, parser_array);
    tcase_add_test(tcase_core, parser_polygon);

    suite_add_tcase(suite, tcase_core);

    return suite;
}

int main(void) {
    Suite *suite = s21_3d_suite();
    SRunner *suite_runner = srunner_create(suite);
    srunner_run_all(suite_runner, CK_VERBOSE);
    int failed_count = srunner_ntests_failed(suite_runner);
    srunner_free(suite_runner);
    return (failed_count == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}