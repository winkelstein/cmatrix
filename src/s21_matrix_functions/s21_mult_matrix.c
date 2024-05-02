#include "../s21_matrix.h"

int s21_mult_matrix(matrix_t* A, matrix_t* B, matrix_t* result) {
  if (A == NULL || B == NULL) return ERROR;

  int rescode = s21_create_matrix(A->rows, B->columns, result);

  if (rescode != OK) {
  } else if ((A->rows != B->columns) || (A->columns != B->rows))
    rescode = CALCULATION_ERROR;
  else {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < B->columns; j++) {
        for (int k = 0; k < B->rows; k++) {
          result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
          if (result->matrix[i][j] == INFINITY ||
              result->matrix[i][j] == -INFINITY) {
            rescode = CALCULATION_ERROR;
            break;
          }
        }
      }
    }
  }
  return rescode;
}