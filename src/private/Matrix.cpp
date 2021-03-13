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

Matrix::Matrix(int row_size, int col_size, std::vector<int> initial_values) {
  this->row_size = row_size;
  this->col_size = col_size;

  int vector_counter = 0;

  if(initial_values.size() != (this->row_size * this->col_size)) {
    std::cout << "Error! You should know why.";
  } else {
    this->my_vector.resize(row_size);
    for(int i = 0; i < this->my_vector.size(); ++i) {
      this->my_vector[i].resize(col_size);
    }
    //initialize values
    for(int row_counter = 0; row_counter < this->row_size; ++row_counter) {
      for(int col_counter = 0; col_counter < this->col_size; ++col_counter) {
        this->my_vector[row_counter][col_counter] = initial_values[vector_counter];
        ++vector_counter;
      }
    }
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

  Matrix result(this->row_size, other_matrix.col_size, 0);
  int current_value = 0;
  int row_counter, col_counter;
  int matrix_row, matrix_col;

  //check if the dimension is the same
  if(this->col_size != other_matrix.row_size) {
    std::cout << "Error!";
    return result;
  }

  //this->my_vector[row_counter][col_counter] * other_matrix.my_vector[col_counter][row_counter]; (questo è giusto)

  for(row_counter = 0; row_counter < result.row_size; ++row_counter) {
    for(col_counter = 0; col_counter < result.col_size; ++col_counter) {
      for(int i = 0; i < this->col_size; ++i) {
        result.my_vector[row_counter][col_counter] += this->my_vector[row_counter][i] * other_matrix.my_vector[i][col_counter];
      }
    }
  }
  
  return result;

}

// Matrix Matrix::operator/(Matrix &other_matrix) {

//   Matrix result(this->row_size, this->col_size, 0);
//   //check if the dimension is the same
//   if(this->my_vector.size() != other_matrix.my_vector.size() 
//   || this->my_vector[0].size() != other_matrix.my_vector[0].size()) {
//     return result;
//   }

//   for(int i = 0; i < this->row_size; ++i) {
//     for(int j = 0; j < this->col_size; ++j) {
//       if(other_matrix.my_vector[i][j] != 0) {
//         result.my_vector[i][j] = this->my_vector[i][j] / other_matrix.my_vector[i][j];
//       } else {
//         return result;
//       }
//     }
//   }

//   return result;

// }


void Matrix::define_values() {
  for(int i = 0; i < this->row_size; ++i) {
    for(int j = 0; j < this->col_size; ++j) {
      std::cout << "Insert value for cell [" << i << "][" << j << "]: ";
      std::cin >> this->my_vector[i][j];
    }
  }
}



//--------------------------------------
//         SCALAR OPERATIONS
//--------------------------------------



Matrix Matrix::operator*(int scalar) {

  Matrix result(this->row_size, this->col_size, 0);

  for(int i = 0; i < this->row_size; ++i) {
    for(int j = 0; j < this->col_size; ++j) {
      result.my_vector[i][j] = this->my_vector[i][j] * scalar;
    }
  }

  return result;

}





