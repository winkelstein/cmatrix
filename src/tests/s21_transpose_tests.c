#include "tests.h"

START_TEST(s21_transpose_test0) {
  matrix_t a, result, expected_result;

  s21_create_matrix(2, 3, &a);
  s21_create_matrix(3, 2, &expected_result);

  a.matrix[0][0] = 0.14;
  a.matrix[0][1] = -9;
  a.matrix[0][2] = 5;
  a.matrix[1][0] = 16;
  a.matrix[1][1] = 98;
  a.matrix[1][2] = 3;

  expected_result.matrix[0][0] = 0.14;
  expected_result.matrix[0][1] = 16;
  expected_result.matrix[1][0] = -9;
  expected_result.matrix[1][1] = 98;
  expected_result.matrix[2][0] = 5;
  expected_result.matrix[2][1] = 3;

  ck_assert_int_eq(s21_transpose(&a, &result), OK);
  ck_assert(s21_eq_matrix(&result, &expected_result));

  s21_remove_matrix(&a);
  s21_remove_matrix(&expected_result);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_transpose_test1) {
  matrix_t a, result, expected_result;

  s21_create_matrix(3, 2, &a);
  s21_create_matrix(2, 3, &expected_result);

  expected_result.matrix[0][0] = 0.14;
  expected_result.matrix[0][1] = -9;
  expected_result.matrix[0][2] = 5;
  expected_result.matrix[1][0] = 16;
  expected_result.matrix[1][1] = 98;
  expected_result.matrix[1][2] = 3;

  a.matrix[0][0] = 0.14;
  a.matrix[0][1] = 16;
  a.matrix[1][0] = -9;
  a.matrix[1][1] = 98;
  a.matrix[2][0] = 5;
  a.matrix[2][1] = 3;

  ck_assert_int_eq(s21_transpose(&a, &result), OK);
  ck_assert(s21_eq_matrix(&result, &expected_result));

  s21_remove_matrix(&a);
  s21_remove_matrix(&expected_result);
  s21_remove_matrix(&result);
}
END_TEST

Suite *s21_transpose_test_suite() {
  Suite *s = suite_create("s21_transpose_matrix");
  TCase *tc_case = tcase_create("s21_transpose_matrix");

  tcase_add_test(tc_case, s21_transpose_test0);
  tcase_add_test(tc_case, s21_transpose_test1);

  suite_add_tcase(s, tc_case);

  return s;
}

int s21_transpose_tests() {
  Suite *s = s21_transpose_test_suite();
  SRunner *runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  int failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return failed;
}