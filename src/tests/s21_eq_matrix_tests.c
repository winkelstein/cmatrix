#include "tests.h"

START_TEST(s21_eq_matrix_test0) {
  matrix_t A, B;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);

  ck_assert_int_eq(s21_eq_matrix(&A, &B), 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_test1) {
  matrix_t A, B;
  s21_create_matrix(2, 3, &A);
  s21_create_matrix(2, 2, &B);

  ck_assert_int_eq(s21_eq_matrix(&A, &B), 0);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_test2) {
  matrix_t A, B;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(3, 2, &B);

  ck_assert_int_eq(s21_eq_matrix(&A, &B), 0);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_test3) {
  matrix_t A, B;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);

  A.matrix[0][0] = 10;

  ck_assert_int_eq(s21_eq_matrix(&A, &B), 0);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_test4) {
  matrix_t A, B;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);

  A.matrix[0][0] = 10;
  B.matrix[0][0] = 10;

  ck_assert_int_eq(s21_eq_matrix(&A, &B), 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

Suite *s21_eq_matrix_test_suite() {
  Suite *s = suite_create("s21_eq_matrix");
  TCase *tc_case = tcase_create("s21_eq_matrix");

  tcase_add_test(tc_case, s21_eq_matrix_test0);
  tcase_add_test(tc_case, s21_eq_matrix_test1);
  tcase_add_test(tc_case, s21_eq_matrix_test2);
  tcase_add_test(tc_case, s21_eq_matrix_test3);
  tcase_add_test(tc_case, s21_eq_matrix_test4);

  suite_add_tcase(s, tc_case);

  return s;
}

int s21_eq_matrix_tests() {
  Suite *s = s21_eq_matrix_test_suite();
  SRunner *runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  int failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return failed;
}