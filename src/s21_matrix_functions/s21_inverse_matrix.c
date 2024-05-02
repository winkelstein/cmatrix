#include "../s21_matrix.h"

int s21_inverse_matrix(matrix_t* A, matrix_t* result) {
  if (A == NULL) return ERROR;

  int rescode = OK;

  if (A->rows != A->columns) {
    rescode = CALCULATION_ERROR;
  } else if (s21_create_matrix(A->rows, A->columns, result)) {
    rescode = ERROR;
  } else if (A->rows == 1 && A->columns == 1) {
    result->matrix[0][0] = 1.0 / A->matrix[0][0];
  } else {
    matrix_t alg_comp = {};
    matrix_t alg_comp_t = {};

    s21_calc_complements(A, &alg_comp);
    s21_transpose(&alg_comp, &alg_comp_t);
    s21_remove_matrix(&alg_comp);

    double det = 0.0;
    rescode = s21_determinant(A, &det);

    if (det == 0.0)
      rescode = CALCULATION_ERROR;
    else
      s21_mult_number(&alg_comp_t, det, result);
  }

  return rescode;
}