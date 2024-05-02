#include "tests.h"

START_TEST(s21_create_matrix_test0) {
  matrix_t A;
  int result = s21_create_matrix(1, 1, &A);

  ck_assert_int_eq(A.rows, 1);
  ck_assert_int_eq(A.columns, 1);
  ck_assert_ptr_ne(A.matrix, NULL);
  ck_assert_int_eq(result, OK);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_create_matrix_test1) {
  matrix_t A;
  int result = s21_create_matrix(0, 1, &A);
  ck_assert_int_eq(result, ERROR);
}
END_TEST

START_TEST(s21_create_matrix_test2) {
  matrix_t A;
  int result = s21_create_matrix(1, 0, &A);
  ck_assert_int_eq(result, ERROR);
}
END_TEST

START_TEST(s21_create_matrix_test3) {
  matrix_t A;
  int result = s21_create_matrix(0, 0, &A);
  ck_assert_int_eq(result, ERROR);
}
END_TEST

START_TEST(s21_create_matrix_test4) {
  int result = s21_create_matrix(1, 1, NULL);
  ck_assert_int_eq(result, ERROR);
}
END_TEST

START_TEST(s21_create_matrix_test5) {
  matrix_t A;
  int result = s21_create_matrix(10, 5, &A);

  ck_assert_int_eq(A.rows, 10);
  ck_assert_int_eq(A.columns, 5);
  ck_assert_ptr_ne(A.matrix, NULL);
  ck_assert_int_eq(result, OK);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_create_matrix_test6) {
  matrix_t A;
  int result = s21_create_matrix(10, 5, &A);

  ck_assert_int_eq(A.rows, 10);
  ck_assert_int_eq(A.columns, 5);
  ck_assert_ptr_ne(A.matrix, NULL);
  ck_assert_int_eq(result, OK);

  for (int i = 0; i < A.rows; i++) ck_assert_ptr_nonnull(A.matrix[i]);

  s21_remove_matrix(&A);
}
END_TEST

Suite *s21_create_matrix_test_suite() {
  Suite *s = suite_create("s21_create_matrix");
  TCase *tc_case = tcase_create("s21_create_matrix");

  tcase_add_test(tc_case, s21_create_matrix_test0);
  tcase_add_test(tc_case, s21_create_matrix_test1);
  tcase_add_test(tc_case, s21_create_matrix_test2);
  tcase_add_test(tc_case, s21_create_matrix_test3);
  tcase_add_test(tc_case, s21_create_matrix_test4);
  tcase_add_test(tc_case, s21_create_matrix_test5);
  tcase_add_test(tc_case, s21_create_matrix_test6);

  suite_add_tcase(s, tc_case);

  return s;
}

int s21_create_matrix_tests() {
  Suite *s = s21_create_matrix_test_suite();
  SRunner *runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  int failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return failed;
}