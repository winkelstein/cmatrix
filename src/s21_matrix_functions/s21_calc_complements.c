#include "../s21_matrix.h"

int s21_minor_of(matrix_t* A, int exclude_row, int exclude_col,
                 matrix_t* result);
int s21_complement_of(matrix_t* A, int i, int j, matrix_t* result);

int s21_calc_complements(matrix_t* A, matrix_t* result) {
  if (A == NULL) return ERROR;

  int rescode = OK;

  if (A->rows != A->columns) {
    rescode = CALCULATION_ERROR;
  } else if (s21_create_matrix(A->rows, A->columns, result)) {
    rescode = ERROR;
  } else {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        rescode = s21_complement_of(A, i, j, result);
        if (rescode) break;
      }
    }
  }

  return rescode;
}

int s21_complement_of(matrix_t* A, int i, int j, matrix_t* result) {
  matrix_t minor = {};
  int rescode = OK;
  rescode = s21_minor_of(A, i, j, &minor);
  if (!rescode) {
    double det = 0.0;
    rescode = s21_determinant(&minor, &det);
    if (!rescode) result->matrix[i][j] = pow(-1, i + j) * det;
    s21_remove_matrix(&minor);
  }

  return rescode;
}

int s21_minor_of(matrix_t* A, int exclude_row, int exclude_col,
                 matrix_t* result) {
  if (A == NULL) return ERROR;

  int rescode = OK;

  if (s21_create_matrix(A->rows - 1, A->columns - 1, result)) {
    rescode = ERROR;
  } else {
    for (int i = 0, minor_i = 0; i < A->rows; i++)
      if (i != exclude_row) {
        for (int j = 0, minor_j = 0; j < A->columns; j++) {
          if (j != exclude_col) {
            result->matrix[minor_i][minor_j] = A->matrix[i][j];
            minor_j++;
          }
        }
        minor_i++;
      }
  }

  return rescode;
}