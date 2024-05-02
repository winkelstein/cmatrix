#include "../s21_matrix.h"

int s21_eq_matrix(matrix_t* A, matrix_t* B) {
  int result = SUCCESS;

  if ((A->rows != B->rows) || (A->columns != B->columns) || A == NULL ||
      B == NULL)
    result = FAILURE;
  else {
    int rows = A->rows;
    int columns = A->columns;
    for (int i = 0; i < rows; i++)
      for (int j = 0; j < columns; j++)
        if (fabs(A->matrix[i][j] - B->matrix[i][j]) >= 1e-7) result = FAILURE;
  }

  return result;
}