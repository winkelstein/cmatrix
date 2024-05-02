#include "../s21_matrix.h"

int s21_mult_number(matrix_t* A, double number, matrix_t* result) {
  if (A == NULL) return ERROR;
  int rescode = s21_create_matrix(A->rows, A->columns, result);

  if (rescode != OK) {
  } else {
    for (int i = 0; i < A->rows; i++)
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] * number;
        if (result->matrix[i][j] == INFINITY ||
            result->matrix[i][j] == -INFINITY) {
          rescode = CALCULATION_ERROR;
          break;
        }
      }
  }
  return rescode;
}