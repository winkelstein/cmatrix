#include "../s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t* result) {
  if (result == NULL || rows < 1 || columns < 1) return ERROR;

  int rescode = 0;

  result->rows = rows;
  result->columns = columns;
  result->matrix = calloc(rows, sizeof(double*));

  if (!result->matrix)
    rescode = ERROR;
  else {
    for (int i = 0; i < rows; i++)
      result->matrix[i] = calloc(columns, sizeof(double));
  }

  return rescode;
}