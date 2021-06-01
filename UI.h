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
/*void UI() {
    int choice0,choice1,choice2;
    do {
        cout << "Choose a type of collection:"<<endl;
        choice0 = interface(MENU0, MENU_SIZE0);
        switch (choice0) {
            case 0:
                cout <<"We are working with Square matrixs."<<endl;
                do {
                    cout << "Choose a type of elements in matrix:"<<endl;
                    choice1 = interface(MENU1, MENU_SIZE1);
                    switch (choice1) {
                        case 0:
                            cout <<"We are working with integer numbers."<<endl;
                            cout <<"enter a dimension of int first matrix: ";
                            int dim1;
                            cin >> dim1;
                            SquareMatrix<int>* squareMatrix1 = new SquareMatrix<int>(dim1);
                            squareMatrix1->EnterMatrix(squareMatrix1->GetDim());
                            squareMatrix1->Print_Matrix();
                            cout <<"enter a dimension of int second matrix: ";
                            int dim2;
                            cin >> dim2;
                            SquareMatrix<int>* squareMatrix2 = new SquareMatrix<int>(dim2);
                            squareMatrix2->EnterMatrix(squareMatrix1->GetDim());
                            squareMatrix2->Print_Matrix();
                            do{
                                cout << "Choose operation with int matrix: "<<endl;
                                choice2 = interface(MENU3, MENU_SIZE3);
                                switch(choice2){
                                    case 0:
                                        cout << "Choose operation with matrix: "<<endl;
                                        break;
                                    case 1:
                                        cout << "Choose operation with matrix: "<<endl;
                                        break;
                                    case 2:
                                        cout << "Choose operation with matrix: "<<endl;
                                        break;
                                    case 3:
                                        cout << "Choose operation with matrix: "<<endl;
                                        break;
                                    case 4:
                                        cout << "Choose operation with matrix: "<<endl;
                                        break;
                                    case 5:
                                        cout << "Choose operation with matrix: "<<endl;
                                        break;
                                    case 6:
                                        cout << "End of working."<<endl;
                                        break;
                                }
                            }while (choice2!=6);
                            break;
                        case 1:
                            cout <<"We are working with float numbers."<<endl;
                            cout <<"enter a dimension of float first matrix: ";
                            int dim3;
                            cin >> dim3;
                            SquareMatrix<float>* squareMatrix3 = new SquareMatrix<float>(dim3);
                            squareMatrix3->EnterMatrix(squareMatrix1->GetDim());
                            squareMatrix3->Print_Matrix();
                            cout <<"enter a dimension of float second matrix: ";
                            int dim4;
                            cin >> dim4;
                            SquareMatrix<float>* squareMatrix4 = new SquareMatrix<float>(dim4);
                            squareMatrix4->EnterMatrix(squareMatrix1->GetDim());
                            squareMatrix4->Print_Matrix();
                            do{
                                cout << "Choose operation with float matrix: "<<endl;
                                choice2 = interface(MENU3, MENU_SIZE3);
                                switch(choice2){
                                    case 0:
                                        cout << "Choose operation with matrix: "<<endl;
                                        break;
                                    case 1:
                                        cout << "Choose operation with matrix: "<<endl;
                                        break;
                                    case 2:
                                        cout << "Choose operation with matrix: "<<endl;
                                        break;
                                    case 3:
                                        cout << "Choose operation with matrix: "<<endl;
                                        break;
                                    case 4:
                                        cout << "Choose operation with matrix: "<<endl;
                                        break;
                                    case 5:
                                        cout << "Choose operation with matrix: "<<endl;
                                        break;
                                    case 6:
                                        cout << "End of working."<<endl;
                                        break;
                                }
                            }while (choice2!=6);
                            break;
                        case 2:
                            cout <<"We are working with complex(int) numbers."<<endl;
                            cout <<"enter a dimension of comlex(int) first matrix: ";
                            int dim5;
                            cin >> dim5;
                            SquareMatrix<complex<int>>* squareMatrix5 = new SquareMatrix<complex<int>>(dim5);
                            squareMatrix5->EnterMatrix(squareMatrix1->GetDim());
                            squareMatrix5->Print_Matrix();
                            cout <<"enter a dimension of complex(int) second matrix: ";
                            int dim6;
                            cin >> dim6;
                            SquareMatrix<complex<int>>* squareMatrix6 = new SquareMatrix<complex<int>>(dim6);
                            squareMatrix6->EnterMatrix(squareMatrix1->GetDim());
                            squareMatrix6->Print_Matrix();
                            do{
                                cout << "Choose operation with complex(int) matrix: "<<endl;
                                choice2 = interface(MENU3, MENU_SIZE3);
                                switch(choice2){
                                    case 0:
                                        cout << "Choose operation with matrix: "<<endl;
                                        break;
                                    case 1:
                                        cout << "Choose operation with matrix: "<<endl;
                                        break;
                                    case 2:
                                        cout << "Choose operation with matrix: "<<endl;
                                        break;
                                    case 3:
                                        cout << "Choose operation with matrix: "<<endl;
                                        break;
                                    case 4:
                                        cout << "Choose operation with matrix: "<<endl;
                                        break;
                                    case 5:
                                        cout << "Choose operation with matrix: "<<endl;
                                        break;
                                    case 6:
                                        cout << "End of working."<<endl;
                                        break;
                                }
                            }while (choice2!=6);
                            break;
                        case 3:
                            cout<<"End of working."<<endl;
                            break;
                    }
                } while (choice1 != 3);
                break;
            case 1:
                cout <<"We are working with vectors."<<endl;
                do {
                    cout << "Choose a type of elements in vector:"<<endl;
                    choice1 = interface(MENU1, MENU_SIZE1);
                    switch (choice1) {
                        case 0:
                            cout <<"We are working with integer numbers."<<endl;
                            break;
                        case 1:
                            cout <<"We are working with float numbers."<<endl;
                            break;
                        case 2:
                            cout <<"We are working with complex(int) numbers."<<endl;
                            break;
                        case 3:
                            cout<<"End of working."<<endl;
                            break;
                    }
                } while (choice1 != 3);
                break;
            case 2:
                cout<<"Thank you! Bye!"<<endl;
                break;
        }
    }while ((choice0 != 2)||(choice1 != 3));
}*/
void MatrixInt(){
    cout <<"enter a dimension of int first matrix: ";
    int dim1;
    cin >> dim1;
    SquareMatrix<int>* squareMatrix1 = new SquareMatrix<int>(dim1);
    squareMatrix1->EnterMatrix(squareMatrix1->GetDim());
    squareMatrix1->Print_Matrix();
}
void UI(){
    int choice0,choice1,choice2;
    do{
        cout << "Choose a type of collection:"<<endl;
        choice0=interface(MENU0,MENU_SIZE0);
        switch(choice0){
            case 0:
                cout <<"We are working with Square matrixs."<<endl;
                do {
                    cout << "Choose a type of elements in matrix:" << endl;
                    choice1 = interface(MENU1, MENU_SIZE1);
                    switch (choice1) {
                        case 0:
                            cout << "We are working with integer numbers." << endl;
                            cout << "enter a dimension of int first matrix: ";
                            int dim1;
                            cin >> dim1;
                            //squareMatrix1 = new SquareMatrix<int>(dim1);
                            //squareMatrix1->EnterMatrix(squareMatrix1->GetDim());
                            //squareMatrix1->Print_Matrix();
                            cout << "enter a dimension of int second matrix: ";
                            do {
                                cout << "Choose operation with int matrix: " << endl;
                                choice2 = interface(MENU3, MENU_SIZE3);
                                switch (choice2) {
                                    case 0:
                                        cout << "Choose 0 operation with matrix: " << endl;
                                        break;
                                    case 1:
                                        cout << "Choose 1 operation with matrix: " << endl;
                                        break;
                                    case 2:
                                        cout << "Choose 2 operation with matrix: " << endl;
                                        break;
                                    case 3:
                                        cout << "Choose 3 operation with matrix: " << endl;
                                        break;
                                    case 4:
                                        cout << "Choose 4 operation with matrix: " << endl;
                                        break;
                                    case 5:
                                        cout << "Choose 5 operation with matrix: " << endl;
                                        break;
                                    case 6:
                                        cout << "End of working." << endl;
                                        break;
                                }
                            } while (choice2 != 6);
                            break;
                        case 1:
                            cout << "We are working with float numbers." << endl;
                            break;
                        case 2:
                            cout << "We are working with complex numbers." << endl;
                            break;
                        case 3:
                            cout << "Exit." << endl;
                            break;
                    }
                }while(choice1!=3);
                break;
            case 1:
                cout <<"We are working with vector."<<endl;
                break;
            case 2:
                cout<<"Goodbye!"<<endl;
                break;
        }
    }while (choice0!=2);
}
#endif //LABA2_UI_H
