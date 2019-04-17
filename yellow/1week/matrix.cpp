#include<iostream>
#include<vector>
#include <fstream>
#include <stdexcept>

using namespace std;

class Matrix{
public:
  Matrix(){
    cols = 0;
    rows = 0;
  }

  Matrix(int num_rows, int num_cols){
    if(num_rows < 0 || num_cols < 0)
      throw std::out_of_range("");
    rows = num_rows;
    cols = num_cols;

    matrix.assign(num_rows, std::vector<int>(num_cols));
  }

  void Reset(int new_num_rows, int new_num_cols){
    if(new_num_cols < 0 || new_num_rows < 0)
      throw std::out_of_range("");

    matrix.assign(new_num_rows, std::vector<int>(new_num_cols));

    cols = new_num_cols;
    rows = new_num_rows;
  }


  int At(int num_rows, int num_cols) const {
    return matrix.at(num_rows).at(num_cols);
  }

  int& At(int num_rows, int num_cols) {
    return matrix.at(num_rows).at(num_cols);
  }

  int GetNumRows() const{
    return rows;
  }

  int GetNumColumns() const{
    return cols;
  }
private:
  int rows;
  int cols;
  std::vector<std::vector<int>> matrix;
};

std::ostream& operator<<(std::ostream& stream, const Matrix& matrix){
  stream << matrix.GetNumRows() << " " << matrix.GetNumColumns() << std::endl;
  for(const auto& row : matrix.matrix){
    for(auto element : row)
      stream << element << " ";

    stream << std::endl;
  }
  return stream;
}

std::istream& operator>>(std::istream& stream, Matrix& matrix){
  int num_cols;
  int num_rows;

  stream >> num_rows >> num_cols;
  matrix.Reset(num_rows, num_cols);

  for(int i = 0; i < num_rows; ++i){
      for(int j = 0; j < num_cols; ++j){
        stream >> matrix.At(i, j);
      }
  }
  return stream;
}

bool operator==(const Matrix& lhs, const Matrix& rhs){
  if(lhs.GetNumColumns() != rhs.GetNumColumns() || lhs.GetNumRows() != rhs.GetNumRows())
    return false;
  for(int i = 0; i < lhs.GetNumRows(); ++i)
    for(int j = 0; j < lhs.GetNumColumns(); ++j)
      if(lhs.At(i, j) != rhs.At(i, j))
        return false;

  return true;

}

Matrix operator+(const Matrix& lhs, const Matrix& rhs){
  if(lhs.GetNumColumns() != rhs.GetNumColumns() || lhs.GetNumRows() != rhs.GetNumRows())
    throw std::invalid_argument("");

  Matrix res(lhs.GetNumRows(), lhs.GetNumColumns());

  for(int i = 0; i < lhs.GetNumRows(); ++i)
    for(int j = 0; j < lhs.GetNumColumns(); ++j)
      res.At(i, j) = lhs.At(i, j) + rhs.At(i, j);
  return res;
}


int main() {
  Matrix one;
  Matrix two;

  std::cin >> one >> two;
  std::cout << one + two << std::endl;
  return 0;
}
