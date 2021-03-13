#pragma once

#include <iostream>
#include <vector>

class Matrix {

private:
  int row_size;
  int col_size;
  std::vector< std::vector<int> > my_vector;

public:

  // CONSTRUCTOR
  Matrix(int, int); //like zeros method of numpy
  Matrix(int, int, int);  //it takes the inizial values for each cells
  Matrix(int, int, std::vector<int>);
  void define_values();
  
  //TODO: define Matrix operations
  Matrix operator+(Matrix &);
  Matrix operator-(Matrix &);
  Matrix operator*(Matrix &);
  // Matrix operator/(Matrix &);
  Matrix transpose();

  //OTHER DEFINITIONS
  
  
  

  //SCALAR OPERATIONS
  // Matrix operator+(double);
  // Matrix operator-(double);
  Matrix operator*(int);
  // Matrix operator/(double);


  void print() const;

};
