#ifndef TESTPYBIND11_MATRIX_H
#define TESTPYBIND11_MATRIX_H

#include <iostream>
#include <vector>

class Matrix {

private:
  unsigned m_rowSize;
  unsigned m_colSize;
  std::vector< std::vector<int> > m_matrix;

public:

  Matrix(unsigned, unsigned); //like zeros method of numpy
  
  //TODO: define matrix operations
  Matrix operator+(Matrix &);
  Matrix operator-(Matrix &);
  Matrix operator*(Matrix &);
  Matrix transpose();

  //SCALAR OPERATIONS
  Matrix operator+(double);
  Matrix operator-(double);
  Matrix operator*(double);
  Matrix operator/(double);

  void print() const;

};


#endif