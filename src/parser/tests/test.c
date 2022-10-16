#include <check.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "../s21_parser.h"

START_TEST(parser_array) {
    indexes a;
    main_parser("parser/tests/cube.obj", &a);
    ck_assert_float_eq_tol(a.array[0], 0, 1e-6);
    ck_assert_float_eq_tol(a.array[1], 0, 1e-6);
    ck_assert_float_eq_tol(a.array[2], 0, 1e-6);
    ck_assert_float_eq_tol(a.array[3], 0, 1e-6);
    ck_assert_float_eq_tol(a.array[4], 0, 1e-6);
    ck_assert_float_eq_tol(a.array[5], 1, 1e-6);
    ck_assert_float_eq_tol(a.array[6], 0, 1e-6);
    ck_assert_float_eq_tol(a.array[7], 1, 1e-6);
    ck_assert_float_eq_tol(a.array[8], 0, 1e-6);
    ck_assert_float_eq_tol(a.array[9], 0, 1e-6);
    ck_assert_float_eq_tol(a.array[10], 1, 1e-6);
    ck_assert_float_eq_tol(a.array[11], 1, 1e-6);
    ck_assert_float_eq_tol(a.array[12], 1, 1e-6);
    ck_assert_float_eq_tol(a.array[13], 0, 1e-6);
    ck_assert_float_eq_tol(a.array[14], 0, 1e-6);
    ck_assert_float_eq_tol(a.array[15], 1, 1e-6);
    ck_assert_float_eq_tol(a.array[16], 0, 1e-6);
    ck_assert_float_eq_tol(a.array[17], 1, 1e-6);
    ck_assert_float_eq_tol(a.array[18], 1, 1e-6);
    ck_assert_float_eq_tol(a.array[19], 1, 1e-6);
    ck_assert_float_eq_tol(a.array[20], 0, 1e-6);
    ck_assert_float_eq_tol(a.array[21], 1, 1e-6);
    ck_assert_float_eq_tol(a.array[22], 1, 1e-6);
    ck_assert_float_eq_tol(a.array[23], 1, 1e-6);
    free(a.array);
    free(a.polygon);
}
END_TEST


Suite *s21_3d_suite(void) {
    Suite *suite;

    suite = suite_create("s21_3d");
    TCase *tcase_core = tcase_create("Core");

    tcase_add_test(tcase_core, parser_array);

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