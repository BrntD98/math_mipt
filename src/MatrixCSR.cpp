#include "MatrixCSR.h"

MatrixCSR::MatrixCSR(int numRows, int numCols)
  : numRows_(numRows), numCols_(numCols) {}

void MatrixCSR::setElement(int row, int col, double value) {
  // добавляем значение элемента в массив значений
  values_.push_back(value);
  
  // добавляем индекс столбца в массив индексов столбцов
  colIndices_.push_back(col);
  
  // если это первый элемент в строке, то добавляем индекс строки в массив индексов строк
  if (values_.size() == 1 || row != rowIndices_[rowIndices_.size() - 1]) {
    rowIndices_.push_back(values_.size() - 1);
  }
}

double MatrixCSR::getElement(int row, int col) const {
  // ищем начало строки в массиве индексов строк
  int start = rowIndices_[row];
  
  // ищем конец строки в массиве индексов строк
  int end = row < numRows_ - 1 ? rowIndices_[row + 1] : values_.size();
  
  // ищем индекс столбца в массиве индексов столбцов
  for (int i = start; i < end; ++i) {
    if (colIndices_[i] == col) {
      return values_[i];
    }
  }
  
  return 0;
}

int MatrixCSR::getNumRows() const {
  return numRows_;
}

int MatrixCSR::getNumCols() const {
  return numCols_;
}
