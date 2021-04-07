#pragma once

#include <iostream>
#include <vector>

class Matrix {

private:
  int row_size;
  int col_size;
  std::vector< std::vector<int> > my_vector;
  int determinant;

public:

  // CONSTRUCTOR
  Matrix(int, int); //like zeros method of numpy
  Matrix(int, int, int);  //it takes the inizial values for each cells
  Matrix(int, int, std::vector<int>);
  void define_values();
  
  //TODO: define Matrix operations
  Matrix operator+(Matrix &) const;
  Matrix operator-(Matrix &) const;
  Matrix operator*(Matrix &) const;
  // Matrix operator/(Matrix &);
  Matrix transpose();

  //OTHER OPERATIONS
  void two_by_two_determinant();
  int get_determinant();
  void sarrus();
  

  //SCALAR OPERATIONS
  // Matrix operator+(double);
  // Matrix operator-(double);
  Matrix operator*(int) const;
  // Matrix operator/(double);


  void print() const;

};
