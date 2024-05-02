#include "tests.h"

START_TEST(s21_inverse_matrix_test0) {
  matrix_t a, result, expected_result;
  s21_create_matrix(3, 3, &a);
  s21_create_matrix(3, 3, &expected_result);

  s21_calc_complements(&a, &result);

  a.matrix[0][0] = 2;
  a.matrix[0][1] = 5;
  a.matrix[0][2] = 7;
  a.matrix[1][0] = 6;
  a.matrix[1][1] = 3;
  a.matrix[1][2] = 4;
  a.matrix[2][0] = 5;
  a.matrix[2][1] = -2;
  a.matrix[2][2] = -3;

  expected_result.matrix[0][0] = 1;
  expected_result.matrix[0][1] = -1;
  expected_result.matrix[0][2] = 1;
  expected_result.matrix[1][0] = -38;
  expected_result.matrix[1][1] = 41;
  expected_result.matrix[1][2] = -34;
  expected_result.matrix[2][0] = 27;
  expected_result.matrix[2][1] = -29;
  expected_result.matrix[2][2] = 24;

  ck_assert_int_eq(s21_inverse_matrix(&a, &result), 0);
  ck_assert_int_eq(s21_eq_matrix(&result, &expected_result), 1);

  s21_remove_matrix(&a);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_inverse_matrix_test1) {
  matrix_t a, result;
  s21_create_matrix(2, 3, &a);

  ck_assert_int_eq(s21_inverse_matrix(&a, &result), CALCULATION_ERROR);

  s21_remove_matrix(&a);
}
END_TEST

START_TEST(s21_inverse_matrix_test2) {
  matrix_t a, result;
  s21_create_matrix(1, 1, &a);
  a.matrix[0][0] = 42.0;

  ck_assert_int_eq(s21_inverse_matrix(&a, &result), OK);

  ck_assert_double_eq(result.matrix[0][0], 1.0 / a.matrix[0][0]);

  s21_remove_matrix(&a);
  s21_remove_matrix(&result);
}

START_TEST(s21_inverse_matrix_test3) {
  matrix_t a, result;
  s21_create_matrix(2, 2, &a);

  a.matrix[0][0] = 8;
  a.matrix[0][1] = 8;

  ck_assert_int_eq(s21_inverse_matrix(&a, &result), CALCULATION_ERROR);

  s21_remove_matrix(&a);
}

Suite *s21_inverse_matrix_test_suite() {
  Suite *s = suite_create("s21_inverse_matrix");
  TCase *tc_case = tcase_create("s21_inverse_matrix");

  tcase_add_test(tc_case, s21_inverse_matrix_test0);
  tcase_add_test(tc_case, s21_inverse_matrix_test1);
  tcase_add_test(tc_case, s21_inverse_matrix_test2);
  tcase_add_test(tc_case, s21_inverse_matrix_test3);
  suite_add_tcase(s, tc_case);

  return s;
}

int s21_inverse_matrix_tests() {
  Suite *s = s21_inverse_matrix_test_suite();
  SRunner *runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  int failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return failed;
}