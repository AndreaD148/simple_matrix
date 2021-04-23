#pragma once

#include <iostream>
#include <vector>
#include <cmath>

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
  int get_determinant();
  Matrix create_sub_matrix(int, int);
  void two_by_two_determinant();
  void sarrus();
  void la_place();
  
  
  

  //SCALAR OPERATIONS
  // Matrix operator+(double);
  // Matrix operator-(double);
  Matrix operator*(int) const;
  // Matrix operator/(double);


  void print() const;

};
