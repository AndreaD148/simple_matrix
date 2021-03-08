#pragma once

#include <iostream>
#include <vector>

class Matrix {

private:
  unsigned row_size;
  unsigned col_size;
  std::vector< std::vector<int> > my_vector;

public:

  Matrix(int, int); //like zeros method of numpy
  Matrix(int, int, int);  //it takes the inizial values for each cells
  
  //TODO: define Matrix operations
  Matrix operator+(Matrix &);
  Matrix operator-(Matrix &);
  Matrix operator*(Matrix &);
  Matrix operator/(Matrix &);
  Matrix transpose();
  
  

  //SCALAR OPERATIONS
  Matrix operator+(double);
  Matrix operator-(double);
  Matrix operator*(double);
  Matrix operator/(double);


  void print() const;

};
