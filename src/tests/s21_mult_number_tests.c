#include "tests.h"

START_TEST(s21_mult_number_test0) {
  matrix_t a, result, expected_result;
  s21_create_matrix(3, 3, &a);
  s21_create_matrix(3, 3, &expected_result);

  a.matrix[0][0] = 1;
  a.matrix[0][1] = 2;
  a.matrix[0][2] = 3;
  a.matrix[1][0] = 0;
  a.matrix[1][1] = 4;
  a.matrix[1][2] = 5;
  a.matrix[2][0] = 0;
  a.matrix[2][1] = 0;
  a.matrix[2][2] = 6;

  double num = 6;

  expected_result.matrix[0][0] = 6;
  expected_result.matrix[0][1] = 12;
  expected_result.matrix[0][2] = 18;
  expected_result.matrix[1][0] = 0;
  expected_result.matrix[1][1] = 24;
  expected_result.matrix[1][2] = 30;
  expected_result.matrix[2][0] = 0;
  expected_result.matrix[2][1] = 0;
  expected_result.matrix[2][2] = 36;

  ck_assert_int_eq(s21_mult_number(&a, num, &result), OK);
  ck_assert(s21_eq_matrix(&result, &expected_result));

  s21_remove_matrix(&a);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected_result);
}
END_TEST

START_TEST(s21_mult_number_test1) {
  matrix_t a, result, expected_result;
  s21_create_matrix(2, 2, &a);
  s21_create_matrix(2, 2, &expected_result);

  a.matrix[0][0] = 12;
  a.matrix[0][1] = -1;
  a.matrix[1][0] = -5;
  a.matrix[1][1] = 0;

  double num = 4.9;

  expected_result.matrix[0][0] = 58.8;
  expected_result.matrix[0][1] = -4.9;
  expected_result.matrix[1][0] = -24.5;
  expected_result.matrix[1][1] = 0;

  ck_assert_int_eq(s21_mult_number(&a, num, &result), OK);
  ck_assert(s21_eq_matrix(&result, &expected_result));

  s21_remove_matrix(&a);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected_result);
}
END_TEST

START_TEST(s21_mult_number_test2) {
  matrix_t a, result, expected_result;
  s21_create_matrix(2, 3, &a);
  s21_create_matrix(2, 3, &expected_result);

  a.matrix[0][0] = 5;
  a.matrix[0][1] = -1;
  a.matrix[0][2] = 9;
  a.matrix[1][0] = 8;
  a.matrix[1][1] = 12;
  a.matrix[1][2] = 14;

  double num = -1.45;

  expected_result.matrix[0][0] = -7.25;
  expected_result.matrix[0][1] = 1.45;
  expected_result.matrix[0][2] = -13.05;
  expected_result.matrix[1][0] = -11.6;
  expected_result.matrix[1][1] = -17.4;
  expected_result.matrix[1][2] = -20.3;

  ck_assert_int_eq(s21_mult_number(&a, num, &result), OK);
  ck_assert(s21_eq_matrix(&result, &expected_result));

  s21_remove_matrix(&a);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected_result);
}
END_TEST

START_TEST(s21_mult_number_test3) {
  matrix_t a, result;
  s21_create_matrix(2, 3, &a);

  a.matrix[0][0] = 5;
  a.matrix[0][1] = -1;
  a.matrix[0][2] = 9;
  a.matrix[1][0] = INFINITY;
  a.matrix[1][1] = 12;
  a.matrix[1][2] = 14;

  double num = -INFINITY;

  ck_assert_int_eq(s21_mult_number(&a, num, &result), CALCULATION_ERROR);

  s21_remove_matrix(&a);
  s21_remove_matrix(&result);
}
END_TEST

Suite *s21_mult_number_test_suite() {
  Suite *s = suite_create("s21_mult_number");
  TCase *tc_case = tcase_create("s21_mult_number");

  tcase_add_test(tc_case, s21_mult_number_test0);
  tcase_add_test(tc_case, s21_mult_number_test1);
  tcase_add_test(tc_case, s21_mult_number_test2);
  tcase_add_test(tc_case, s21_mult_number_test3);

  suite_add_tcase(s, tc_case);

  return s;
}

int s21_mult_number_tests() {
  Suite *s = s21_mult_number_test_suite();
  SRunner *runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  int failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return failed;
}