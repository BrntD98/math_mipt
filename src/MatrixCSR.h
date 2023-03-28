#include <iostream>
#pragma once
#include <vector>

class MatrixCSR {
public:
  MatrixCSR(int numRows, int numCols);
  void setElement(int row, int col, double value);
  double getElement(int row, int col) const;
  int getNumRows() const;
  int getNumCols() const;

private:
  std::vector<double> values_;
  std::vector<int> colIndices_;
  std::vector<int> rowIndices_;
  int numRows_;
  int numCols_;
};
