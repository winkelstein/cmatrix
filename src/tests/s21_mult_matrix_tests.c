#include "tests.h"

START_TEST(s21_mult_matrix_test0) {
  matrix_t a, b, result, expected_result;
  s21_create_matrix(3, 3, &a);
  s21_create_matrix(3, 3, &b);
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

  b.matrix[0][0] = 1;
  b.matrix[0][1] = 0;
  b.matrix[0][2] = 0;
  b.matrix[1][0] = 2;
  b.matrix[1][1] = 0;
  b.matrix[1][2] = 0;
  b.matrix[2][0] = 3;
  b.matrix[2][1] = 4;
  b.matrix[2][2] = 1;

  expected_result.matrix[0][0] = 14;
  expected_result.matrix[0][1] = 12;
  expected_result.matrix[0][2] = 3;
  expected_result.matrix[1][0] = 23;
  expected_result.matrix[1][1] = 20;
  expected_result.matrix[1][2] = 5;
  expected_result.matrix[2][0] = 18;
  expected_result.matrix[2][1] = 24;
  expected_result.matrix[2][2] = 6;

  ck_assert_int_eq(s21_mult_matrix(&a, &b, &result), OK);
  ck_assert(s21_eq_matrix(&result, &expected_result));

  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected_result);
}
END_TEST

START_TEST(s21_mult_matrix_test1) {
  matrix_t a, b, result;
  s21_create_matrix(2, 3, &a);
  s21_create_matrix(2, 2, &b);

  a.matrix[0][0] = 12;
  a.matrix[0][1] = -1;
  a.matrix[1][0] = -5;
  a.matrix[1][1] = 0;

  b.matrix[0][0] = -4;
  b.matrix[0][1] = -3;
  b.matrix[1][0] = 15;
  b.matrix[1][1] = 7;

  ck_assert_int_eq(s21_mult_matrix(&a, &b, &result), CALCULATION_ERROR);

  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_mult_matrix_test2) {
  matrix_t a, b, result, expected_result;
  s21_create_matrix(3, 2, &a);
  s21_create_matrix(2, 3, &b);
  s21_create_matrix(3, 3, &expected_result);

  a.matrix[0][0] = 1;
  a.matrix[0][1] = 4;
  a.matrix[1][0] = 2;
  a.matrix[1][1] = 5;
  a.matrix[2][0] = 3;
  a.matrix[2][1] = 6;

  b.matrix[0][0] = 1;
  b.matrix[0][1] = -1;
  b.matrix[0][2] = 1;
  b.matrix[1][0] = 2;
  b.matrix[1][1] = 3;
  b.matrix[1][2] = 4;

  expected_result.matrix[0][0] = 9;
  expected_result.matrix[0][1] = 11;
  expected_result.matrix[0][2] = 17;
  expected_result.matrix[1][0] = 12;
  expected_result.matrix[1][1] = 13;
  expected_result.matrix[1][2] = 22;
  expected_result.matrix[2][0] = 15;
  expected_result.matrix[2][1] = 15;
  expected_result.matrix[2][2] = 27;

  ck_assert_int_eq(s21_mult_matrix(&a, &b, &result), OK);
  ck_assert(s21_eq_matrix(&result, &expected_result));

  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected_result);
}
END_TEST

START_TEST(s21_mult_matrix_test3) {
  matrix_t a, b, result;
  s21_create_matrix(2, 3, &a);
  s21_create_matrix(3, 3, &b);

  a.matrix[0][0] = 5;
  a.matrix[0][1] = -1;
  a.matrix[0][2] = 9;
  a.matrix[1][0] = 8;
  a.matrix[1][1] = 12;
  a.matrix[1][2] = 14;

  b.matrix[0][0] = -4;
  b.matrix[1][0] = -3;
  b.matrix[2][0] = -6;
  b.matrix[0][1] = 15;
  b.matrix[1][1] = 7;
  b.matrix[2][1] = -1;

  ck_assert_int_eq(s21_mult_matrix(&a, &b, &result), CALCULATION_ERROR);

  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
}
END_TEST

START_TEST(s21_mult_matrix_test4) {
  matrix_t a, b, result;
  s21_create_matrix(3, 3, &a);
  s21_create_matrix(3, 3, &b);

  a.matrix[0][0] = 5;
  a.matrix[0][1] = -1;
  a.matrix[0][2] = 9;
  a.matrix[1][0] = 8;
  a.matrix[1][1] = 12;
  a.matrix[1][2] = INFINITY;

  b.matrix[0][0] = -INFINITY;
  b.matrix[1][0] = -3;
  b.matrix[2][0] = -6;
  b.matrix[0][1] = 15;
  b.matrix[1][1] = 7;
  b.matrix[2][1] = -1;

  ck_assert_int_eq(s21_mult_matrix(&a, &b, &result), CALCULATION_ERROR);

  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
}
END_TEST

Suite *s21_mult_matrix_test_suite() {
  Suite *s = suite_create("s21_mult_matrix");
  TCase *tc_case = tcase_create("s21_mult_matrix");

  tcase_add_test(tc_case, s21_mult_matrix_test0);
  tcase_add_test(tc_case, s21_mult_matrix_test1);
  tcase_add_test(tc_case, s21_mult_matrix_test2);
  tcase_add_test(tc_case, s21_mult_matrix_test3);
  tcase_add_test(tc_case, s21_mult_matrix_test4);

  suite_add_tcase(s, tc_case);

  return s;
}

int s21_mult_matrix_tests() {
  Suite *s = s21_mult_matrix_test_suite();
  SRunner *runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  int failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return failed;
}