#ifndef LABA2_SQUAREMATRIX_H
#define LABA2_SQUAREMATRIX_H
#include <iostream>
#include <iomanip>
#include "ArraySequence.h"
#include <stdexcept>
#pragma once
#endif //LABA2_SQUAREMATRIX_H
const string DIFFERENT="Matrixs have different dimensions! ";
template <class T> class SquareMatrix{
private:
    ArraySequence<ArraySequence<T>> matrix;
    int dimension=0;
public:
    SquareMatrix(){
        ArraySequence<ArraySequence<T>> New_Matrix;
        matrix=New_Matrix;
        dimension=0;
    }

    SquareMatrix(int dim){
        matrix = new ArraySequence<ArraySequence<T>>(dim);
        for (int i=0; i<dim; i++){
            ArraySequence<T> str_elem = new ArraySequence<T>(dim);
            //cout << str_elem.GetLength()<<endl;
            for (int j=0; j<dim; j++){
            str_elem.Set(j,0);
            }
            matrix.Set(i,str_elem);
        }
        dimension=dim;
    }
    SquareMatrix(T** elements, int dim){
        for (int i=0; i<dim; i++){
            ArraySequence<T> str_elem;
            for (int j=0; j<dim; j++){
                str_elem.Append(elements[i][j]);
            }
            matrix.Append(str_elem);
        }
        dimension=dim;
    }

    T Get (int row, int col){
        return matrix.Get(row).Get(col);
    }

    int GetDim(){
        return dimension;
    }

    void Set (T elem, int row, int col){
        ArraySequence<ArraySequence<T>>matr= new ArraySequence<ArraySequence<T>>(dimension);
        for (int i=0; i<dimension; i++){
            ArraySequence<T> str_matr=new ArraySequence<T>(dimension);
            //cout << str_matr.GetLength() << endl;
            for (int j=0; j<dimension; j++){
                if ((i==row)&&(j==col)){
                    str_matr.Set(j,elem);
                }else{
                    str_matr.Set(j,this->Get(i,j));
                }
            }
            matr.Set(i,str_matr);
        }
        matrix=matr;
    }

    void Delete_Matrix(){
        for (int i=0; i<dimension; i++){
            matrix.Get(i).DEleteArraySequence();
        }
        matrix.DeleteArraySequence();
    }

    void Sum_Matrix(SquareMatrix<T>* matrix2){
        if (this->GetDim()!=matrix2->GetDim()){
            cout << DIFFERENT << "Enter the second matrix with first matrix's dimension: " << endl;
            matrix2=new SquareMatrix<T>(this->GetDim());
            matrix2->EnterMatrix(this->GetDim());
            matrix2->Print_Matrix();
        }
        //SquareMatrix<T> New_Matrix= new SquareMatrix<T>(this->GetDim());
        for (int i=0; i<this->GetDim();i++){
            for (int j=0; j<this->GetDim();j++){
                this->Set(this->Get(i,j)+matrix2->Get(i,j),i,j);
            }
        }
        //cout << "Result of Sum_Martix:"<<endl;
        //this->Print_Matrix();
    }

    void ScalarMult(){
        T scalar;
        cout << "Enter scalar, which we mult on Matrix: "<< endl;
        cin >> scalar;
        for (int i=0; i<this->GetDim();i++){
            for (int j=0; j<this->GetDim();j++){
                this->Set(this->Get(i,j)*scalar,i,j);
            }
        }
        //cout << "Result of scalarMult on "<<scalar<<":"<<endl;
        //this->Print_Matrix();
    }

    SquareMatrix<T>* Mult_Matrix(SquareMatrix<T>* matrix2){
        if (this->GetDim()!=matrix2->GetDim()){
            cout << DIFFERENT << "Enter the second matrix with first matrix's dimension: " << endl;
            matrix2=new SquareMatrix<T>(this->GetDim());
            matrix2->EnterMatrix(this->GetDim());
            matrix2->Print_Matrix();
        }
        T temp=0;
        SquareMatrix<T>* new_matr = new SquareMatrix(this->GetDim());
        for (int i=0; i<this->GetDim();i++){
            for (int j=0; j<this->GetDim();j++){
                for (int k=0; k<this->GetDim();k++){
                    temp+=this->Get(i,k)*matrix2->Get(k,j);
                }
                new_matr->Set(temp,i,j);
                temp=0;
            }
        }
        return new_matr;
    }

    void ElemTransformRows(int row1,int row2,T scalar){
        if(row1<0 || row1>=this->GetDim()||row2<0 || row2>=this->GetDim()){
            throw out_of_range(NO_INDEX);
        }
        ArraySequence<ArraySequence<T>>matr=new ArraySequence<ArraySequence<T>>(this->GetDim());
        for (int i=0; i<this->GetDim();i++){
            ArraySequence<T> new_row=new ArraySequence<T>(this->GetDim());
            for (int j=0; j<this->GetDim();j++){
                if (i==row1) {
                    new_row.Set(j, this->Get(row1, j) + this->Get(row2, j) * scalar);
                } else {
                    new_row.Set(j,this->Get(i,j));
                }
            }
            matr.Set(i,new_row);
        }
        matrix=matr;
        //cout << "Result of ElemTransformRows, when "<<row1<<" row = "<<row1<<" row + "<<scalar<<" * "<<row2<<" row: "<<endl;
        //this->Print_Matrix();
    }

    void ElemTransformCols(int col1,int col2,T scalar){
        if(col1<0 || col1>=this->GetDim()||col2<0 || col2>=this->GetDim()){
            throw out_of_range(NO_INDEX);
        }
        ArraySequence<ArraySequence<T>>matr=new ArraySequence<ArraySequence<T>>(this->GetDim());
        for (int i=0; i<this->GetDim();i++){
            ArraySequence<T> new_row=new ArraySequence<T>(this->GetDim());
            for (int j=0; j<this->GetDim();j++){
                if (j==col1) {
                    new_row.Set(j, this->Get(i, col1) + this->Get(i, col2) * scalar);
                } else {
                    new_row.Set(j,this->Get(i,j));
                }
            }
            matr.Set(i,new_row);
        }
        matrix=matr;
        //cout << "Result of ElemTransformCols, when "<<col1<<" col = "<<col1<<" col + "<<scalar<<" * "<<col2<<" col: "<<endl;
        //this->Print_Matrix();
    }

    void Norm(){//Norma=sum of abs values elements of cols
        T temp=0;
        for(int i=0; i<dimension; i++){
            for(int j=0; j<dimension; j++){
                temp+=abs(this->Get(j,i));
            }
            cout<<"Norma of "<<i<<" col is "<<temp<<";"<<endl;
            temp=0;
        }
    }
    void Print_Matrix(){
        cout << "Square Matrix: " << endl;
        for (int i=0; i<dimension; i++){
            for (int j=0; j<dimension;j++){
                cout << setw(7) << fixed << setprecision(4) << this->Get(i,j);
            }
            cout << endl;
        }
    }

    void EnterMatrix(int dim){
        T elem;
        cout << "Enter elements in Matrix: "<<endl;
        for (int i=0; i<dim; i++){
            for (int j=0; j<dim; j++){
                cin >> elem;
                this->Set(elem,i,j);
            }
        }
    }
};
