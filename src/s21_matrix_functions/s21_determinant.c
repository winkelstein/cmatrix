#include "../s21_matrix.h"

int s21_determinant_recursive(matrix_t* A, double* result);
double s21_determinant_2x2(matrix_t* A);

int s21_determinant(matrix_t* A, double* result) {
  if (A == NULL || result == NULL) return ERROR;

  int rescode = OK;

  if (A->rows != A->columns)
    rescode = CALCULATION_ERROR;
  else
    rescode = s21_determinant_recursive(A, result);
  return rescode;
}

double s21_determinant_2x2(matrix_t* A) {
  return A->matrix[0][0] * A->matrix[1][1] - A->matrix[0][1] * A->matrix[1][0];
}

int s21_determinant_recursive(matrix_t* A, double* result) {
  int size = A->rows;

  int rescode = OK;

  if (size == 1) {
    *result = A->matrix[0][0];
  } else if (size == 2) {
    *result = s21_determinant_2x2(A);
  } else {
    double det = 0.0;
    matrix_t submatrix = {};
    rescode = s21_create_matrix(size - 1, size - 1, &submatrix);
    if (rescode) return rescode;

    for (int col = 0; col < size; col++) {
      int submatrix_row = 0;
      for (int i = 1; i < size; i++) {
        int submatrix_col = 0;
        for (int j = 0; j < size; j++) {
          if (j != col) {
            submatrix.matrix[submatrix_row][submatrix_col++] = A->matrix[i][j];
          }
        }
        submatrix_row++;
      }

      double submatrix_det = 0.0;

      if (s21_determinant_recursive(&submatrix, &submatrix_det) != 0) {
        return ERROR;
      }

      det += (col % 2 == 0 ? 1 : -1) * A->matrix[0][col] * submatrix_det;
    }

    s21_remove_matrix(&submatrix);

    *result = det;
  }

  return rescode;
}