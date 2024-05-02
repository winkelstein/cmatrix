#include "tests.h"

START_TEST(s21_determinant_test0) {
  matrix_t a;
  double det = 0.0;

  s21_create_matrix(3, 3, &a);

  a.matrix[0][0] = 2;
  a.matrix[0][1] = 5;
  a.matrix[0][2] = 7;
  a.matrix[1][0] = 6;
  a.matrix[1][1] = 3;
  a.matrix[1][2] = 4;
  a.matrix[2][0] = 5;
  a.matrix[2][1] = -2;
  a.matrix[2][2] = -3;

  ck_assert_int_eq(s21_determinant(&a, &det), 0);
  ck_assert_double_eq(det, -1);

  s21_remove_matrix(&a);
}
END_TEST

START_TEST(s21_determinant_test1) {
  matrix_t a;
  double det = 0.0;

  s21_create_matrix(2, 3, &a);

  ck_assert_int_eq(s21_determinant(&a, &det), CALCULATION_ERROR);

  s21_remove_matrix(&a);
}
END_TEST

START_TEST(s21_determinant_test2) {
  matrix_t a;
  double det = 0.0;

  s21_create_matrix(1, 1, &a);

  a.matrix[0][0] = -9;

  ck_assert_int_eq(s21_determinant(&a, &det), 0);
  ck_assert_double_eq(det, -9);

  s21_remove_matrix(&a);
}
END_TEST

START_TEST(s21_determinant_test3) {
  matrix_t a;
  double det = 0.0;

  s21_create_matrix(3, 3, &a);

  a.matrix[0][0] = 1;
  a.matrix[0][1] = 2;
  a.matrix[0][2] = 3;
  a.matrix[1][0] = 4;
  a.matrix[1][1] = 5;
  a.matrix[1][2] = 6;
  a.matrix[2][0] = 7;
  a.matrix[2][1] = 8;
  a.matrix[2][2] = 9;

  ck_assert_int_eq(s21_determinant(&a, &det), 0);
  ck_assert_double_eq(det, 0);

  s21_remove_matrix(&a);
}
END_TEST

Suite *s21_determinant_test_suite() {
  Suite *s = suite_create("s21_determinant");
  TCase *tc_case = tcase_create("s21_determinant");

  tcase_add_test(tc_case, s21_determinant_test0);
  tcase_add_test(tc_case, s21_determinant_test1);
  tcase_add_test(tc_case, s21_determinant_test2);
  tcase_add_test(tc_case, s21_determinant_test3);

  suite_add_tcase(s, tc_case);

  return s;
}

int s21_determinant_tests() {
  Suite *s = s21_determinant_test_suite();
  SRunner *runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  int failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return failed;
}