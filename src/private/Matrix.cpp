#include "../public/Matrix.h"

//--------------------------------------
//         CONSTRUCTOR
//--------------------------------------

//base constructor (just row_size and col_size)
Matrix::Matrix(int  row_size, int  col_size) {

  this-> row_size =  row_size;
  this-> col_size =  col_size;
  this->determinant = 0;

  //initialize our vector
  this->my_vector.resize(row_size);

  for(int i = 0; i < this->my_vector.size(); ++i) {
    this->my_vector[i].resize( col_size, 0);
  }

}

Matrix::Matrix(int row_size, int col_size, int initial_value) {

  this->row_size = row_size;
  this->col_size = col_size;
  this->determinant = 0;

  this->my_vector.resize(row_size);

  for(int i = 0; i < this->my_vector.size(); ++i) {
    this->my_vector[i].resize(col_size, initial_value);
  }


}

Matrix::Matrix(int row_size, int col_size, std::vector<int> initial_values) {
  this->row_size = row_size;
  this->col_size = col_size;
  this->determinant = 0;

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

void Matrix::define_values() {
  for(int i = 0; i < this->row_size; ++i) {
    for(int j = 0; j < this->col_size; ++j) {
      std::cout << "Insert value for cell [" << i << "][" << j << "]: ";
      std::cin >> this->my_vector[i][j];
    }
  }
}


//--------------------------------------
//         MATRIX OPERATIONS
//--------------------------------------

Matrix Matrix::operator+(Matrix &other_matrix) const {

  Matrix result(this->row_size, this->col_size, 0);
  //check if the dimension is the same
  if(this->row_size != other_matrix.row_size || this->col_size != other_matrix.col_size) {
    throw std::invalid_argument("Error! Different dimensions");
  }

  for(int i = 0; i < this->row_size; ++i) {
    for(int j = 0; j < this->col_size; ++j) {
      result.my_vector[i][j] = this->my_vector[i][j] + other_matrix.my_vector[i][j];
    }
  }

  return result;

}

Matrix Matrix::operator-(Matrix &other_matrix) const {

  Matrix result(this->row_size, this->col_size, 0);
  //check if the dimension is the same
  if(this->row_size != other_matrix.row_size || this->col_size != other_matrix.col_size) {
    throw std::invalid_argument("Error! Different dimensions");
  }

  for(int i = 0; i < this->row_size; ++i) {
    for(int j = 0; j < this->col_size; ++j) {
      result.my_vector[i][j] = this->my_vector[i][j] - other_matrix.my_vector[i][j];
    }
  }

  return result;

}

Matrix Matrix::operator*(Matrix &other_matrix) const {

  Matrix result(this->row_size, other_matrix.col_size, 0);
  int current_value = 0;
  int row_counter, col_counter;
  int matrix_row, matrix_col;

  //check if the dimension is the same
  if(this->col_size != other_matrix.row_size) {
    throw std::invalid_argument("Error! Different dimensions!");
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

Matrix Matrix::transpose() {

  //rows changed with columns
  Matrix result{this->col_size, this->row_size, 0};

  for(int i = 0; i < this->row_size; ++i) {
    for(int j = 0; j < this->col_size; ++j) {
      //first row = initial first column
      result.my_vector[j][i] = this->my_vector[i][j];
    }
  }

  return result;

}




//--------------------------------------
//         SCALAR OPERATIONS
//--------------------------------------



Matrix Matrix::operator*(int scalar) const {

  Matrix result(this->row_size, this->col_size, 0);

  for(int i = 0; i < this->row_size; ++i) {
    for(int j = 0; j < this->col_size; ++j) {
      result.my_vector[i][j] = this->my_vector[i][j] * scalar;
    }
  }

  return result;

}

//--------------------------------------
//            OTHER METHODS
//--------------------------------------

void Matrix::two_by_two_determinant() {

  int res = 0;

  if(this->row_size == 2 && this->col_size == 2) {
    res += (this->my_vector[0][0] * this->my_vector[1][1]) - (this->my_vector[1][0] * this->my_vector[0][1]);
  } else {
    throw std::invalid_argument("Error! This is not a 2 * 2 Matrix");
  }

  this->determinant = res;

  // return this->determinant;

}

//TODO: call a specific method (depends on the size of the matrix)
int Matrix::get_determinant() {

  if(this->row_size != this->col_size) {
    throw std::invalid_argument("Error! Not nxn matrix");
  }

  //check the dimension
  // if(this->row_size >=)
  if(this->row_size >= 4) {
    // std::cout << this->la_place() << "\n";
    this->la_place();
    std::cout << "\nDeterminant after laplace = " << this->determinant;
  } else if(this->row_size == 3) {
    this->sarrus();
    std::cout << "\nDeterminant after sarruss = " << this->determinant;
  } else if(this->row_size == 2) {
    this->two_by_two_determinant();
    std::cout << "\nDeterminant after two by two determinant = " << this->determinant;
  }

  return this->determinant;
}

void Matrix::sarrus() {
  

  int partial_res = 1;
  int to_sub_res = 1; //to __mul__ three value
  int second_partial_res = 0;
  int total_res = 0;
  int i = 0, j = 0;

  //print initial value of determinant to see what is going on
  std::cout << "\nDeterminant before sarrus: " << this->determinant << "\n";

  if(this->row_size == 3 && this->col_size == 3) {
    
    Matrix partial_matrix{3, 5};

    //load 3x3 matrix in partial_matrix (5x5 matrix)
    for(int i = 0; i < this->row_size; ++i) {
      for(int j = 0; j < this->col_size; ++j) {
        partial_matrix.my_vector[i][j] = this->my_vector[i][j];
      }
    }

    partial_matrix.my_vector[0][3] = this->my_vector[0][0];
    partial_matrix.my_vector[0][4] = this->my_vector[0][1];
    
    partial_matrix.my_vector[1][3] = this->my_vector[1][0];
    partial_matrix.my_vector[1][4] = this->my_vector[1][1];
    
    partial_matrix.my_vector[2][3] = this->my_vector[2][0];
    partial_matrix.my_vector[2][4] = this->my_vector[2][1];

    //print for test
    // partial_matrix.print();

    //principal diagonal
    // 
    total_res = ((this->my_vector[0][0] * this->my_vector[1][1] * this->my_vector[2][2])
    + (this->my_vector[0][1] * this->my_vector[1][2] * this->my_vector[2][3])
    + (this->my_vector[0][2] * this->my_vector[1][3] * this->my_vector[2][4])
    - ( (this->my_vector[2][0] * this->my_vector[1][1] * this->my_vector[0][2])
    + (this->my_vector[2][1] * this->my_vector[1][2] * this->my_vector[0][3]) 
    + (this->my_vector[2][2] * this->my_vector[1][3] * this->my_vector[0][4])));

    std::cout << "Total res: " << total_res << "\n";

    this->determinant += total_res;

    std::cout << "\nDeterminant after sarruss: " << this->determinant;
    // return this->determinant;
    


  } else {
    throw std::invalid_argument("Error! This is not a 3 * 3 Matrix");
  }

}

/*
 * NAME: create_sub_matrix
 */
Matrix Matrix::create_sub_matrix(int selected_row, int selected_col) {
  Matrix sub_matrix{this->row_size-1, this->col_size-1, 0};
  // int i = 0, j = 0;
  // std::vector<int> values(sub_matrix.row_size * sub_matrix.col_size);

  int index = 0;

  for(int current_row = 0; current_row < this->row_size; ++current_row) {
    for(int current_col = 0; current_col < this->col_size; ++current_col) {
      if(current_row != selected_row && current_col != selected_col) {
        sub_matrix.my_vector[index / sub_matrix.row_size][index % sub_matrix.col_size] 
        = this->my_vector[current_row][current_col];
        ++index;
      }
    }
  }
  
  return sub_matrix;

}

//TODO: to finish implementation, now I've found the row where I can do laplace
void Matrix::la_place() {

  //print initial determinant
  std::cout << "Initial value of determinant: " << this->determinant << "\n";

  // Matrix sub_matrix{};
  int zeros_on_row[this->row_size];
  // int zeros_on_col[this->col_size];

  for(int i = 0; i < this->row_size; ++i) {
    zeros_on_row[i] = 0;
  }

  int max_zeros_row = zeros_on_row[0];
  int res = 0;
  int row_with_more_zero;

  //per fare laplace devo prima controllare su quale riga è meglio fare LaPlace

  //scanning matrix to see where we can do easly laplace

  for(int i = 0; i < this->row_size; ++i) {
    for(int j = 0; j < this->col_size;++j) {
      if(this->my_vector[i][j] == 0) {
        zeros_on_row[i]++;
      }
    }
  }

  //print zeros_on_row just for test
  std::cout << "zeros on the rows: \n";
  for(int i = 0; i < this->row_size; ++i) {
    std::cout << zeros_on_row[i] << "\t";
  }
  
  std::cout << "\n";

  //cicle to zeros_on_row to get the max value
  row_with_more_zero = zeros_on_row[0];

  for(int i = 1; i < this->row_size; ++i) {
    if(zeros_on_row[i] > row_with_more_zero) {
      row_with_more_zero = i; //I should save only the position (row index)
    }
  }

  // std::cout << "row with more zero is: " << row_with_more_zero << "\n";

  

  for(int col = 0; col < this->col_size; ++col) {
    if(this->my_vector[row_with_more_zero][col] != 0) {
      Matrix sub_matrix = this->create_sub_matrix(row_with_more_zero, col);
      //print submatrix for test
      std::cout << "sub_matrix: \n";
      sub_matrix.print();
      res += pow(-1, (row_with_more_zero+1 + col+1)) * 
      this->my_vector[row_with_more_zero][col] * sub_matrix.get_determinant();
    }
  }
  

  //print for test
  // std::cout << "\nsubmatrix: \n";
  // sub_matrix.print();

  //print the result
  std::cout << "\nres: = " << res << "\n";

  this->determinant += res;

  // return this->determinant;

}


