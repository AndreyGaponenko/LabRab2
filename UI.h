#ifndef LABA2_UI_H
#define LABA2_UI_H
#include <iostream>
#include "SquareMatrix.h"
#include "Vector.h"
const char *MENU0[]={"0.SquareMatrix","1.Vector","2.Exit"};
const int MENU_SIZE0=3;
const char *MENU1[]={"0.Integer", "1.Float","2.Complex(int)","3.Exit"};
const int MENU_SIZE1 = 4;
const char *MENU2[]={"0.Sum of vectors", "1.Mult on scalar","2.Norma of vector","3.Scalar vectors multiple","4.Exit"};
const int MENU_SIZE2=5;
const char *MENU3[]={"0.Sum of matrixs","1.Mult on scalar","2.Norms of matrix","3.Multiple of matrixs","4.Elementary transform rows","5.Elementary transform cols","6.Exit"};
const int MENU_SIZE3=7;
int interface (const char *menu[], int f){
    string error="";
    int choice;
    do {
        cout<<error<<endl;
        error="You're wrong. Try again!";
        for (int i=0; i<f; ++i){
            cout<<menu[i]<<endl;
        }
        cout<<"Make your choice: "<<endl;
        cin >> choice;
        while (getchar() != '\n') {}
    } while (choice < 0 || choice >= f);
    return choice;
}

SquareMatrix<int>* MatrixInt(){
    cout <<"enter a dimension of int matrix: ";
    int dim1;
    cin >> dim1;
    SquareMatrix<int>* squareMatrix1 = new SquareMatrix<int>(dim1);
    squareMatrix1->EnterMatrix(squareMatrix1->GetDim());
    squareMatrix1->Print_Matrix();
    return squareMatrix1;
}

SquareMatrix<float>* MatrixFloat(){
    cout <<"enter a dimension of float matrix: ";
    int dim1;
    cin >> dim1;
    SquareMatrix<float>* squareMatrix1 = new SquareMatrix<float>(dim1);
    squareMatrix1->EnterMatrix(squareMatrix1->GetDim());
    squareMatrix1->Print_Matrix();
    return squareMatrix1;
}

SquareMatrix<complex<int>>* MatrixComp(){
    cout <<"enter a dimension of complex int matrix: ";
    int dim1;
    cin >> dim1;
    SquareMatrix<complex<int>>* squareMatrix1 = new SquareMatrix<complex<int>>(dim1);
    squareMatrix1->EnterMatrix(squareMatrix1->GetDim());
    squareMatrix1->Print_MatrixComplex();
    return squareMatrix1;
}

Vector<int>* VectorInt(){
    cout <<"enter a dimension of int vector: ";
    int dim1;
    cin >> dim1;
    Vector<int>* vector1 = new Vector<int>(dim1);
    vector1->EnterVector(vector1->GetDim());
    vector1->Print_Vector();
    return vector1;
}

Vector<float>* VectorFloat(){
    cout <<"enter a dimension of float vector: ";
    int dim1;
    cin >> dim1;
    Vector<float>* vector1 = new Vector<float>(dim1);
    vector1->EnterVector(vector1->GetDim());
    vector1->Print_Vector();
    return vector1;
}

Vector<complex<int>>* VectorComp(){
    cout <<"enter a dimension of complex vector: ";
    int dim1;
    cin >> dim1;
    Vector<complex<int>>* vector1 = new Vector<complex<int>>(dim1);
    vector1->EnterVector(vector1->GetDim());
    vector1->Print_VectorComplex();
    return vector1;
}

void UI(){
    int choice0,choice1,choice2;
    do{
        cout << "Choose a type of collection:"<<endl;
        choice0=interface(MENU0,MENU_SIZE0);
        switch(choice0){
            case 0: {
                cout << "We are working with Square matrixs." << endl;
                do {
                    cout << "Choose a type of elements in matrix:" << endl;
                    choice1 = interface(MENU1, MENU_SIZE1);
                    switch (choice1) {
                        case 0: {
                            cout << "We are working with integer numbers." << endl;
                            SquareMatrix<int> *squareMatrix1 = MatrixInt();
                            cout << "Second int matrix:\n";
                            SquareMatrix<int> *squareMatrix4 = MatrixInt();
                            do {
                                cout << "Choose operation with int matrix: " << endl;
                                choice2 = interface(MENU3, MENU_SIZE3);
                                switch (choice2) {
                                    case 0:
                                        squareMatrix1->Sum_Matrix(squareMatrix4);
                                        cout << "Result sum of matrix: " << endl;
                                        squareMatrix1->Print_Matrix();
                                        break;
                                    case 1:
                                        squareMatrix1->ScalarMult();
                                        cout << "Result of mult matrix on scalar: " << endl;
                                        squareMatrix1->Print_Matrix();
                                        break;
                                    case 2:
                                        cout << "Norma of matrix: " << endl;
                                        squareMatrix1->Norm();
                                        break;
                                    case 3:
                                        squareMatrix1=squareMatrix1->Mult_Matrix(squareMatrix4);
                                        cout << "Result of mult matrix: " << endl;
                                        squareMatrix1->Print_Matrix();
                                        break;
                                    case 4:
                                        int row1,row2;
                                        cout << "Enter a first row: " << endl;
                                        cin >> row1;
                                        cout << "Enter a second row: " << endl;
                                        cin >> row2;
                                        int scalar;
                                        cout << "Enter a scalar: " << endl;
                                        cin >> scalar;
                                        squareMatrix1->ElemTransformRows(row1,row2,scalar);
                                        cout << "Result of elem transform rows: " << endl;
                                        squareMatrix1->Print_Matrix();
                                        break;
                                    case 5:
                                        int col1,col2;
                                        cout << "Enter a first col: " << endl;
                                        cin >> col1;
                                        cout << "Enter a second col: " << endl;
                                        cin >> col2;
                                        cout << "Enter a scalar: " << endl;
                                        cin >> scalar;
                                        squareMatrix1->ElemTransformCols(col1,col2,scalar);
                                        cout << "Result of elem transform cols: " << endl;
                                        squareMatrix1->Print_Matrix();
                                        break;
                                    case 6:
                                        cout << "End of working with int matrixs." << endl;
                                        break;
                                }
                            } while (choice2 != 6);
                            break;
                        }
                        case 1: {
                            cout << "We are working with float numbers." << endl;
                            SquareMatrix<float> *squareMatrix2 = MatrixFloat();
                            cout << "Second float matrix:\n";
                            SquareMatrix<float> *squareMatrix5 = MatrixFloat();
                            do {
                                cout << "Choose operation with float matrix: " << endl;
                                choice2 = interface(MENU3, MENU_SIZE3);
                                switch (choice2) {
                                    case 0:
                                        squareMatrix2->Sum_Matrix(squareMatrix5);
                                        cout << "Result sum of matrix: " << endl;
                                        squareMatrix2->Print_Matrix();
                                        break;
                                    case 1:
                                        squareMatrix2->ScalarMult();
                                        cout << "Result of mult matrix on scalar: " << endl;
                                        squareMatrix2->Print_Matrix();
                                        break;
                                    case 2:
                                        cout << "Norma of matrix: " << endl;
                                        squareMatrix2->Norm();
                                        break;
                                    case 3:
                                        squareMatrix2=squareMatrix2->Mult_Matrix(squareMatrix5);
                                        cout << "Result of mult matrix: " << endl;
                                        squareMatrix2->Print_Matrix();
                                        break;
                                    case 4:
                                        int row1,row2;
                                        cout << "Enter a first row: " << endl;
                                        cin >> row1;
                                        cout << "Enter a second row: " << endl;
                                        cin >> row2;
                                        int scalar;
                                        cout << "Enter a scalar: " << endl;
                                        float scalar2;
                                        cin >> scalar2;
                                        squareMatrix2->ElemTransformRows(row1,row2,scalar2);
                                        cout << "Result of elem transform rows: " << endl;
                                        squareMatrix2->Print_Matrix();
                                        break;
                                    case 5:
                                        int col1,col2;
                                        cout << "Enter a first col: " << endl;
                                        cin >> col1;
                                        cout << "Enter a second col: " << endl;
                                        cin >> col2;
                                        cout << "Enter a scalar: " << endl;
                                        cin >> scalar2;
                                        squareMatrix2->ElemTransformCols(col1,col2,scalar2);
                                        cout << "Result of elem transform cols: " << endl;
                                        squareMatrix2->Print_Matrix();
                                        break;
                                    case 6:
                                        cout << "End of working with float matrixs." << endl;
                                        break;
                                }
                            } while (choice2 != 6);
                            break;
                        }
                        case 2: {
                            cout << "We are working with complex numbers." << endl;
                            SquareMatrix<complex<int>> *squareMatrix3 = MatrixComp();
                            cout << "Second complex(int) matrix:\n";
                            SquareMatrix<complex<int>> *squareMatrix6 = MatrixComp();
                            do {
                                cout << "Choose operation with complex matrix: " << endl;
                                choice2 = interface(MENU3, MENU_SIZE3);
                                switch (choice2) {
                                    case 0:
                                        squareMatrix3->Sum_Matrix(squareMatrix6);
                                        cout << "Result sum of matrix: " << endl;
                                        squareMatrix3->Print_MatrixComplex();
                                        break;
                                    case 1:
                                        squareMatrix3->ScalarMult();
                                        cout << "Result of mult matrix on scalar: " << endl;
                                        squareMatrix3->Print_MatrixComplex();
                                        break;
                                    case 2:
                                        cout << "Norma of matrix: " << endl;
                                        squareMatrix3->Norm();
                                        break;
                                    case 3:
                                        squareMatrix3=squareMatrix3->Mult_Matrix(squareMatrix6);
                                        cout << "Result of mult matrix: " << endl;
                                        squareMatrix3->Print_MatrixComplex();
                                        break;
                                    case 4:
                                        int row1,row2;
                                        cout << "Enter a first row: " << endl;
                                        cin >> row1;
                                        cout << "Enter a second row: " << endl;
                                        cin >> row2;
                                        cout << "Enter a scalar: " << endl;
                                        float scalar3;
                                        cin >> scalar3;
                                        squareMatrix3->ElemTransformRows(row1,row2,scalar3);
                                        cout << "Result of elem transform rows: " << endl;
                                        squareMatrix3->Print_MatrixComplex();
                                        break;
                                    case 5:
                                        int col1,col2;
                                        cout << "Enter a first col: " << endl;
                                        cin >> col1;
                                        cout << "Enter a second col: " << endl;
                                        cin >> col2;
                                        cout << "Enter a scalar: " << endl;
                                        cin >> scalar3;
                                        squareMatrix3->ElemTransformCols(col1,col2,scalar3);
                                        cout << "Result of elem transform cols: " << endl;
                                        squareMatrix3->Print_MatrixComplex();
                                        break;
                                    case 6:
                                        cout << "End of working with complex matrixs." << endl;
                                        break;
                                }
                            } while (choice2 != 6);
                            break;
                        }
                        case 3:
                            cout << "Thank you for work!" << endl;
                            break;
                    }
                } while (choice1 != 3);
                break;
            }
            case 1: {
                cout << "We are working with vector." << endl;
                do{
                    cout << "Choose a type of elements in matrix:" << endl;
                    choice1 = interface(MENU1, MENU_SIZE1);
                    switch (choice1) {
                        case 0:{
                            cout << "We are working with integer numbers." << endl;
                            Vector<int> *vector1 = VectorInt();
                            cout << "Second int vector:\n";
                            Vector<int> *vector4 = VectorInt();
                            do {
                                cout << "Choose operation with int vector: " << endl;
                                choice2 = interface(MENU2, MENU_SIZE2);
                                switch (choice2) {
                                    case 0:
                                        vector1->Sum_Vector(vector4);
                                        cout << "Result sum of vectors: " << endl;
                                        vector1->Print_Vector();
                                        break;
                                    case 1:
                                        vector1->ScalarMult();
                                        cout << "Result mult vector on scalar: " << endl;
                                        vector1->Print_Vector();
                                        break;
                                    case 2:
                                        vector1->Norm();
                                        break;
                                    case 3:
                                        vector1->ScalarVectorMult(vector4);
                                        break;
                                    case 4:
                                        cout << "Thank you for work!" << endl;
                                        break;
                                }
                            } while (choice2 != 4);
                            break;
                        }
                        case 1: {
                            cout << "We are working with float numbers." << endl;
                            Vector<float> *vector2 = VectorFloat();
                            cout << "Second float vector:\n";
                            Vector<float> *vector5 = VectorFloat();
                            do {
                                cout << "Choose operation with float vector: " << endl;
                                choice2 = interface(MENU2, MENU_SIZE2);
                                switch (choice2) {
                                    case 0:
                                        vector2->Sum_Vector(vector5);
                                        cout << "Result sum of vectors: " << endl;
                                        vector2->Print_Vector();
                                        break;
                                    case 1:
                                        vector2->ScalarMult();
                                        cout << "Result mult vector on scalar: " << endl;
                                        vector2->Print_Vector();
                                        break;
                                    case 2:
                                        vector2->Norm();
                                        break;
                                    case 3:
                                        vector2->ScalarVectorMult(vector5);
                                        break;
                                    case 4:
                                        cout << "Thank you for work!" << endl;
                                        break;
                                }
                            } while (choice2 != 4);
                            break;
                        }
                        case 2: {
                            cout << "We are working with complex int numbers." << endl;
                            Vector<complex<int>> *vector3 = VectorComp();
                            cout << "Second complex(int) vector:\n";
                            Vector<complex<int>> *vector6 = VectorComp();
                            do {
                                cout << "Choose operation with complex vector: " << endl;
                                choice2 = interface(MENU2, MENU_SIZE2);
                                switch (choice2) {
                                    case 0:
                                        vector3->Sum_Vector(vector6);
                                        cout << "Result sum of vectors: " << endl;
                                        vector3->Print_VectorComplex();
                                        break;
                                    case 1:
                                        vector3->ScalarMult();
                                        cout << "Result mult vector on scalar: " << endl;
                                        vector3->Print_VectorComplex();
                                        break;
                                    case 2:
                                        vector3->Norm();
                                        break;
                                    case 3:
                                        vector3->ScalarVectorMult(vector6);
                                        break;
                                    case 4:
                                        cout << "Thank you for work!" << endl;
                                        break;
                                }
                            } while (choice2 != 4);
                            break;
                        }
                        case 3:
                            cout << "Thank you for work!" << endl;
                            break;
                    }
                }while(choice1!=3);
                break;
            }
            case 2:
                cout << "Goodbye!" << endl;
                break;
        }
    }while (choice0!=2);
}
#endif //LABA2_UI_H
