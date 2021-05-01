#include <iostream>
#include "Matrix.h"
#include <iomanip>
#include <cstdlib>


//constructor
// in my code, r represents the number of rows and c for the
// number of columns
Matrix::Matrix(uint rows, uint cols) {
  r = rows;
  c = cols;
  double** rPointer = new double*[rows];
  head = rPointer;
  for (uint i = 0; i < rows; i++) {
    double* temp = new double[cols];
    rPointer[i] = temp;
    for (uint j = 0; j < cols; j++) {
      temp[j] = 0;
    } //for
  } //for
} // constructor

//constructor for array
Matrix::Matrix(double** values, int w, int h) {
  head = values;
  r = w;
  c = h;
}//constructor

// constructor
Matrix::Matrix(const Matrix & m) {
  r = m.numRows();
  c = m.numCols();
  double** rPointer = new double*[r];
  head = rPointer;
  for (uint i = 0; i < r; i++) {
    double* temp = new double[c];
    rPointer[i] = temp;
    for (uint j = 0; j < c; j++) {
      temp[j] = m.at(i, j);
    } //for                                                                                                                                                                                              
  } //for              
} //constructor

//destructor
Matrix::~Matrix() {
  for (uint i = 0; i < r; i++) {
    delete[] head[i];
  }
  delete[] head;
} //~Matrix

// the add function adds a user specified double to each value
// in the matrix.
Matrix Matrix::add(double s) const {
  Matrix m(*this);
  for (uint i = 0; i < r; i++) {
    for ( uint j = 0; j < c; j++) {
      m.at(i, j) = m.at(i, j) + s;
    } //for
  } //for
  return m;
} //add

// this add function adds two matrices together
Matrix Matrix::add(const Matrix & m) const {
  Matrix m2(*this);
  for (uint i = 0; i < r; i++) {
    for (uint j = 0; j < c; j++) {
      m2.at(i, j) = m2.at(i, j) + m.at(i, j);
    } //for
  } //for
  return m2;
} // add

// the subtract function subtracts a user specified double from  each
// value in the matrix.
Matrix Matrix::subtract(double s) const {
  Matrix m(*this);
  for (uint i = 0; i < r; i++) {
    for (uint j = 0; j < c; j++) {
      m.at(i, j) = m.at(i, j) - s;
    } //for
  } //for
  return m;
} //subtract

// this subtract functions subtracts one matrix from the other
Matrix Matrix::subtract(const Matrix & m) const{
  Matrix m2(*this);
  for (uint i = 0; i < r; i++) {
    for (uint j = 0; j < c; j++) {
      m2.at(i, j) = m2.at(i, j) - m.at(i, j);
    } //for
  } //for
  return m2;
} //subtract

// this multiplication function multiplies a user specified
// double to each value within the matrix 
Matrix Matrix::multiply(double s) const {
  Matrix m(*this);
  for (uint i = 0; i < r; i++) {
    for (uint j = 0; j < c; j++) {
      m.at(i, j) = m.at(i, j) * s;
    } //for
  } //for
  return m;
} //multiply

//multiplies two matrices together
Matrix Matrix::multiply(const Matrix & m) const {
  Matrix m2(numRows(), m.numCols());
  for (uint i = 0; i < r; i++) {
    for (uint j = 0; j < c; j++) {
      for (uint p = 0; p < c; p++) {
	m2.at(i, j) = m2.at(i, j) * (m.at(p, j));
      } //for
    } //for
  } //for
  return m2;
} //multiply

//divides each number within the matrix with a user specified double
Matrix Matrix::divide(double s) const {
  Matrix m(*this);
  for (uint i = 0; i < r; i++) {
    for (uint j = 0; j < c; j++) {
      m.at(i, j) = m.at(i, j) / s;
    } //for
  } //for
  return m;
} //divide

Matrix Matrix::t() const {
  Matrix m(*this);
  for (uint i = 0; i < r; i++) {
    for (uint j = 0; j < c; j++) {
      m.at(j, i) = at(i, j); 
    } //rows
  } //for
  return m;
} 

// returns the number of rows
const uint Matrix::numRows() const {
  return r;
} //numRows

// returns the number of columns
const uint Matrix::numCols() const {
  return c;
} //numCols

double & Matrix::at(uint row, uint cols) {
  return head[r][c];
} //at

const double & Matrix::at(uint row, uint col) const {
  double & temp = head[row][col];
  return temp;
} //at
