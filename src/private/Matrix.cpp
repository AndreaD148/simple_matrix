#include "../public/Matrix.h"

//define contructor
Matrix::Matrix(int  row_size, int  col_size) {

  this-> row_size =  row_size;
  this-> col_size =  col_size;

  //initialize our vector
  this->matrix.resize(row_size);

  for(int i = 0; i < this->matrix.size(); ++i) {
    this->matrix[i].resize( col_size, 0);
  }

}

Matrix::Matrix(int row_size, int col_size, int initial_value) {

  this->row_size = row_size;
  this->col_size = col_size;

  this->matrix.resize(row_size);

  for(int i = 0; i < this->matrix.size(); ++i) {
    this->matrix[i].resize(col_size, initial_value);
  }



}

void Matrix::print() const {
  for(int i = 0; i < this->matrix.size(); ++i) {
    for(int j = 0; j < this->matrix[i].size(); ++j) {
      // std::cout<<"element in position <" << i << ", " << j << ">: " << this-> matrix[i][j];
      std::cout << this->matrix[i][j] << "\t";
    }
    std::cout << std::endl;
  }
}

Matrix Matrix::operator+(double scalar) {

  Matrix result(this->row_size, this->col_size, 0);

  for(int i = 0; i < row_size; ++i) {
    for(int j = 0; j < col_size; ++j) {
      result.matrix[i][j] = this->matrix[i][j] + scalar;
    }
  }

  return result;

}


Matrix Matrix::operator-(double scalar) {

  Matrix result(this->row_size, this->col_size, 0);

  for(int i = 0; i < this->row_size; ++i) {
    for(int j = 0; j < this->col_size; ++j) {
      result.matrix[i][j] = this->matrix[i][j] - scalar;
    }
  }

  return result;

}


Matrix Matrix::operator*(double scalar) {

  Matrix result(this->row_size, this->col_size, 0);

  for(int i = 0; i < this->row_size; ++i) {
    for(int j = 0; j < this->col_size; ++j) {
      result.matrix[i][j] = this->matrix[i][j] * scalar;
    }
  }

  return result;

}


Matrix Matrix::operator/(double scalar) {

  Matrix result(this->row_size, this->col_size, 0);

  if(scalar == 0) {
    return result;
  }

  for(int i = 0; i < this->row_size; ++i) {
    for(int j = 0; j < this->col_size; ++j) {
      result.matrix[i][j] = this->matrix[i][j] / scalar;
    }
  }

  return result;

}