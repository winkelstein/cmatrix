#include "../s21_matrix.h"

int s21_sub_matrix(matrix_t* A, matrix_t* B, matrix_t* result) {
  if (A == NULL || B == NULL) return ERROR;

  int rescode = s21_create_matrix(A->rows, B->columns, result);

  if (rescode != OK) {
  } else if ((A->rows != B->rows) || (A->columns != B->columns))
    rescode = CALCULATION_ERROR;
  else {
    int rows = A->rows;
    int columns = A->columns;
    for (int i = 0; i < rows; i++)
      for (int j = 0; j < columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
        if (result->matrix[i][j] == INFINITY ||
            result->matrix[i][j] == -INFINITY) {
          rescode = CALCULATION_ERROR;
          break;
        }
      }
  }

  return rescode;
}