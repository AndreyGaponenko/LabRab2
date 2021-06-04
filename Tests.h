#ifndef LABA2_TESTS_H
#define LABA2_TESTS_H
#include <iostream>
#include "SquareMatrix.h"
#include "Vector.h"
void floatMatrix() {
    int dim, dim1;
    cout << "Enter dimension of first Matrix:" << endl;
    cin >> dim;
    SquareMatrix<float> *squareMatrix1 = new SquareMatrix<float>(dim);
    squareMatrix1->EnterMatrix(squareMatrix1->GetDim());
    squareMatrix1->Print_Matrix();
    cout << "Enter dimension of second Matrix:" << endl;
    cin >> dim1;
    SquareMatrix<float> *squareMatrix2 = new SquareMatrix<float>(dim1);
    squareMatrix2->EnterMatrix(squareMatrix2->GetDim());
    squareMatrix2->Print_Matrix();
    squareMatrix1->Sum_Matrix(squareMatrix2);
    cout << "Result of Sum Matrix: " << endl;
    squareMatrix1->Print_Matrix();
    squareMatrix1->ScalarMult();
    cout << "Result of mult on scalar: " << endl;
    squareMatrix1->Print_Matrix();
    squareMatrix1->ElemTransformRows(0, 1, 1.5);
    cout << "Result of elem transform row 0: row 0 = row 0 + 1.5 * row 1: " << endl;
    squareMatrix1->Print_Matrix();
    squareMatrix1->ElemTransformCols(1, 0, 2);
    cout << "Result of elem transform col 1: col 1 = col 1 + 2 * col 0: " << endl;
    squareMatrix1->Print_Matrix();
    cout << "Result of Norma: " << endl;
    squareMatrix1->Norm();
}
void intMatrix() {
    int dim, dim1;
    cout << "Enter dimension of first Matrix:" << endl;
    cin >> dim;
    SquareMatrix<int> *squareMatrix1 = new SquareMatrix<int>(dim);
    squareMatrix1->EnterMatrix(squareMatrix1->GetDim());
    squareMatrix1->Print_Matrix();
    cout << "Enter dimension of second Matrix:" << endl;
    cin >> dim1;
    SquareMatrix<int> *squareMatrix2 = new SquareMatrix<int>(dim1);
    squareMatrix2->EnterMatrix(squareMatrix2->GetDim());
    squareMatrix2->Print_Matrix();
    squareMatrix1->Sum_Matrix(squareMatrix2);
    cout << "Result of Sum Matrix: " << endl;
    squareMatrix1->Print_Matrix();
    squareMatrix1->ScalarMult();
    cout << "Result of mult on scalar: " << endl;
    squareMatrix1->Print_Matrix();
    squareMatrix1->ElemTransformRows(0, 1, 3);
    cout << "Result of elem transform row 0: row 0 = row 0 + 3 * row 1: " << endl;
    squareMatrix1->Print_Matrix();
    squareMatrix1->ElemTransformCols(1, 0, 2);
    cout << "Result of elem transform col 1: col 1 = col 1 + 2 * col 0: " << endl;
    squareMatrix1->Print_Matrix();
    cout << "Result of Norma: " << endl;
    squareMatrix1->Norm();
}

void complexMatrix() {
    int dim, dim1;
    cout << "Enter dimension of first Matrix:" << endl;
    cin >> dim;
    SquareMatrix<complex<int>> *squareMatrix1 = new SquareMatrix<complex<int>>(dim);
    squareMatrix1->EnterMatrix(squareMatrix1->GetDim());
    squareMatrix1->Print_MatrixComplex();
    cout << "Enter dimension of second Matrix:" << endl;
    cin >> dim1;
    SquareMatrix<complex<int>> *squareMatrix2 = new SquareMatrix<complex<int>>(dim1);
    squareMatrix2->EnterMatrix(squareMatrix2->GetDim());
    squareMatrix2->Print_MatrixComplex();
    squareMatrix1->Sum_Matrix(squareMatrix2);
    cout << "Result of Sum Matrix: " << endl;
    squareMatrix1->Print_MatrixComplex();
    squareMatrix1->ScalarMult();
    cout << "Result of mult on scalar: " << endl;
    squareMatrix1->Print_MatrixComplex();
    squareMatrix1->ElemTransformRows(0, 1, 3);
    cout << "Result of elem transform row 0: row 0 = row 0 + 3 * row 1: " << endl;
    squareMatrix1->Print_MatrixComplex();
    squareMatrix1->ElemTransformCols(1, 0, 2);
    cout << "Result of elem transform col 1: col 1 = col 1 + 2 * col 0: " << endl;
    squareMatrix1->Print_MatrixComplex();
    cout << "Result of Norma: " << endl;
    squareMatrix1->Norm();
}

void intVector(){
    int dim, dim1;
    cout << "Enter dimension of first Vector:" << endl;
    cin >> dim;
    Vector<int> *vector1 = new Vector<int>(dim);
    vector1->EnterVector(vector1->GetDim());
    vector1->Print_Vector();
    cout << "Enter dimension of second Vector:" << endl;
    cin >> dim1;
    Vector<int> *vector2 = new Vector<int>(dim1);
    vector2->EnterVector(vector2->GetDim());
    vector2->Print_Vector();
    vector1->ScalarVectorMult(vector2);
    vector1->Sum_Vector(vector2);
    cout << "Result of Sum Vectors: " << endl;
    vector1->Print_Vector();
    vector1->ScalarMult();
    cout << "Result mult on scalar:\n";
    vector1->Print_Vector();
    vector1->Norm();
}

void floatVector(){
    int dim, dim1;
    cout << "Enter dimension of first Vector:" << endl;
    cin >> dim;
    Vector<float> *vector1 = new Vector<float>(dim);
    vector1->EnterVector(vector1->GetDim());
    vector1->Print_Vector();
    cout << "Enter dimension of second Vector:" << endl;
    cin >> dim1;
    Vector<float> *vector2 = new Vector<float>(dim1);
    vector2->EnterVector(vector2->GetDim());
    vector2->Print_Vector();
    vector1->ScalarVectorMult(vector2);
    vector1->Sum_Vector(vector2);
    cout << "Result of Sum Vectors: " << endl;
    vector1->Print_Vector();
    vector1->ScalarMult();
    cout << "Result mult on scalar:\n";
    vector1->Print_Vector();
    vector1->Norm();
}

void complexVector(){
    int dim, dim1;
    cout << "Enter dimension of first Vector:" << endl;
    cin >> dim;
    Vector<complex<int>> *vector1 = new Vector<complex<int>>(dim);
    vector1->EnterVector(vector1->GetDim());
    vector1->Print_VectorComplex();
    cout << "Enter dimension of second Vector:" << endl;
    cin >> dim1;
    Vector<complex<int>> *vector2 = new Vector<complex<int>>(dim1);
    vector2->EnterVector(vector2->GetDim());
    vector2->Print_VectorComplex();
    vector1->ScalarVectorMult(vector2);
    vector1->Sum_Vector(vector2);
    cout << "Result of Sum Vectors: " << endl;
    vector1->Print_VectorComplex();
    vector1->ScalarMult();
    cout << "Result mult on scalar:\n";
    vector1->Print_VectorComplex();
    vector1->Norm();
}
#endif //LABA2_TESTS_H
