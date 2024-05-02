#include "tests.h"

START_TEST(s21_calc_complements_test0) {
  matrix_t a, result, expected_result;
  s21_create_matrix(3, 3, &a);
  s21_create_matrix(3, 3, &expected_result);

  s21_calc_complements(&a, &result);

  a.matrix[0][0] = 1;
  a.matrix[0][1] = 2;
  a.matrix[0][2] = 3;
  a.matrix[1][0] = 0;
  a.matrix[1][1] = 4;
  a.matrix[1][2] = 2;
  a.matrix[2][0] = 5;
  a.matrix[2][1] = 2;
  a.matrix[2][2] = 1;

  expected_result.matrix[0][0] = 0;
  expected_result.matrix[0][1] = 10;
  expected_result.matrix[0][2] = -20;
  expected_result.matrix[1][0] = 4;
  expected_result.matrix[1][1] = -14;
  expected_result.matrix[1][2] = 8;
  expected_result.matrix[2][0] = -8;
  expected_result.matrix[2][1] = -2;
  expected_result.matrix[2][2] = 4;

  ck_assert_int_eq(s21_calc_complements(&a, &result), 0);
  ck_assert_int_eq(s21_eq_matrix(&result, &expected_result), 1);

  s21_remove_matrix(&a);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_calc_complements_test1) {
  matrix_t a, result;
  s21_create_matrix(2, 3, &a);

  ck_assert_int_eq(s21_calc_complements(&a, &result), CALCULATION_ERROR);

  s21_remove_matrix(&a);
}
END_TEST

Suite *s21_calc_complements_test_suite() {
  Suite *s = suite_create("s21_calc_complements");
  TCase *tc_case = tcase_create("s21_calc_complements");

  tcase_add_test(tc_case, s21_calc_complements_test0);
  tcase_add_test(tc_case, s21_calc_complements_test1);

  suite_add_tcase(s, tc_case);

  return s;
}

int s21_calc_complements_tests() {
  Suite *s = s21_calc_complements_test_suite();
  SRunner *runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  int failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return failed;
}