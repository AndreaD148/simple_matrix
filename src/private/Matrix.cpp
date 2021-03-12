#include "../public/Matrix.h"

//--------------------------------------
//         CONSTRUCTOR
//--------------------------------------
Matrix::Matrix(int  row_size, int  col_size) {

  this-> row_size =  row_size;
  this-> col_size =  col_size;

  //initialize our vector
  this->my_vector.resize(row_size);

  for(int i = 0; i < this->my_vector.size(); ++i) {
    this->my_vector[i].resize( col_size, 0);
  }

}

Matrix::Matrix(int row_size, int col_size, int initial_value) {

  this->row_size = row_size;
  this->col_size = col_size;

  this->my_vector.resize(row_size);

  for(int i = 0; i < this->my_vector.size(); ++i) {
    this->my_vector[i].resize(col_size, initial_value);
  }



}

void Matrix::print() const {
  for(int i = 0; i < this->my_vector.size(); ++i) {
    for(int j = 0; j < this->my_vector[i].size(); ++j) {
      // std::cout<<"element in position <" << i << ", " << j << ">: " << this-> Matrix[i][j];
      std::cout << this->my_vector[i][j] << "\t";
    }
    std::cout << std::endl;
  }
}

//--------------------------------------
//         MATRIX OPERATIONS
//--------------------------------------

Matrix Matrix::operator+(Matrix &other_matrix) {

  Matrix result(this->row_size, this->col_size, 0);
  //check if the dimension is the same
  if(this->my_vector.size() != other_matrix.my_vector.size() 
  || this->my_vector[0].size() != other_matrix.my_vector[0].size()) {
    return result;
  }

  for(int i = 0; i < this->row_size; ++i) {
    for(int j = 0; j < this->col_size; ++j) {
      result.my_vector[i][j] = this->my_vector[i][j] + other_matrix.my_vector[i][j];
    }
  }

  return result;

}

Matrix Matrix::operator-(Matrix &other_matrix) {

  Matrix result(this->row_size, this->col_size, 0);
  //check if the dimension is the same
  if(this->my_vector.size() != other_matrix.my_vector.size() 
  || this->my_vector[0].size() != other_matrix.my_vector[0].size()) {
    return result;
  }

  for(int i = 0; i < this->row_size; ++i) {
    for(int j = 0; j < this->col_size; ++j) {
      result.my_vector[i][j] = this->my_vector[i][j] - other_matrix.my_vector[i][j];
    }
  }

  return result;

}

Matrix Matrix::operator*(Matrix &other_matrix) {

  Matrix result(this->row_size, this->col_size, 0);
  int current_value = 0;
  int row_counter, col_counter;
  int matrix_row, matrix_col;

  //check if the dimension is the same
  if(this->col_size != other_matrix.row_size) {
    std::cout << "Error!";
    return result;
  }

  //this->my_vector[row_counter][col_counter] * other_matrix.my_vector[col_counter][row_counter]; (questo è giusto)

  for(row_counter = 0; row_counter < this->row_size; ++row_counter) {
    for(col_counter = 0; col_counter < this->col_size; ++col_counter) {
      result.my_vector[matrix_row][matrix_col] += this->my_vector[row_counter][col_counter] * other_matrix.my_vector[col_counter][row_counter];
    }
  }
  
  return result;

}

Matrix Matrix::operator/(Matrix &other_matrix) {

  Matrix result(this->row_size, this->col_size, 0);
  //check if the dimension is the same
  if(this->my_vector.size() != other_matrix.my_vector.size() 
  || this->my_vector[0].size() != other_matrix.my_vector[0].size()) {
    return result;
  }

  for(int i = 0; i < this->row_size; ++i) {
    for(int j = 0; j < this->col_size; ++j) {
      if(other_matrix.my_vector[i][j] != 0) {
        result.my_vector[i][j] = this->my_vector[i][j] / other_matrix.my_vector[i][j];
      } else {
        return result;
      }
    }
  }

  return result;

}



//--------------------------------------
//         SCALAR OPERATIONS
//--------------------------------------



Matrix Matrix::operator*(double scalar) {

  Matrix result(this->row_size, this->col_size, 0);

  for(int i = 0; i < this->row_size; ++i) {
    for(int j = 0; j < this->col_size; ++j) {
      result.my_vector[i][j] = this->my_vector[i][j] * scalar;
    }
  }

  return result;

}





