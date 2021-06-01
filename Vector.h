#ifndef LABA2_VECTOR_H
#define LABA2_VECTOR_H
#include <iostream>
#include <iomanip>
#include "ArraySequence.h"
#include <stdexcept>
#include <complex>
#pragma once
const string DIFFERENTV="Vectors have different dimensions! ";
template <class T> class Vector{
private:
    ArraySequence<T> vector;
    int dimension=0;
public:
    Vector(){
        ArraySequence<T> new_vector;
        vector=new_vector;
        dimension=0;
    }

    Vector(int dim){
        vector=new ArraySequence<T>(dim);
        for (int i=0; i<dim;i++){
            vector.Set(i,0);
        }
        dimension=dim;
    }

    Vector(T* elements, int dim){
        for (int i=0; i<dim; i++){
            vector.Set(i,elements[i]);
        }
        dimension=dim;
    }

    T Get(int index){
        return vector.Get(index);
    }

    int GetDim(){
        return dimension;
    }

    void Set( T elem,int index){
        return vector.Set(index, elem);
    }

    void Delete_Vector(){
        vector.DeleteArraySequence();
    }

    void Sum_Vector(Vector<T>* vector2){
        if (this->GetDim()!=vector2->GetDim()){
            cout << DIFFERENTV << "Enter the second vector with first vector's dimension: " << endl;
            vector2=new Vector<T>(this->GetDim());
            vector2->EnterVector(this->GetDim());
            vector2->Print_Vector();
        }
        for (int i=0; i<this->GetDim();i++){
            this->Set(this->Get(i)+vector2->Get(i),i);
        }
        //cout << "Result of Sum_Vector:"<<endl;
        //this->Print_Vector();
    }

    void ScalarMult(){
        T scalar;
        cout << "Enter scalar, which we mult on Vector: "<< endl;
        cin >> scalar;
        for (int i=0; i<this->GetDim();i++){
            this->Set(this->Get(i)*scalar,i);
        }
        //cout << "Result of scalarMult on "<<scalar<<":"<<endl;
        //this->Print_Vector();
    }

    void ScalarVectorMult(Vector<T>* vector2){
        if (this->GetDim()!=vector2->GetDim()){
            cout << DIFFERENTV << "Enter the second vector with first vector's dimension: " << endl;
            vector2=new Vector<T>(this->GetDim());
            vector2->EnterVector(this->GetDim());
            vector2->Print_Vector();
        }
        T temp=0;
        for (int i=0; i<this->GetDim();i++){
            temp+=this->Get(i)*vector2->Get(i);
        }
        cout <<"ScalarVectorMult is "<<temp<<endl;
    }

    void Norm(){//Norma=sum of abs values elements of coords
        T temp=0;
        for (int i=0; i<dimension; i++){
            temp+=abs(this->Get(i));
        }
        cout<<"Norma of vector is "<<temp<<endl;
    }

    void Print_Vector(){
        cout << "Vector: " << endl;
        cout <<"(";
        for (int i=0; i<dimension; i++){
                cout<< vector.Get(i);
                if (i!=dimension-1) cout<<"; ";
            }
        cout <<")"<< endl;
    }

    void Print_VectorComplex(){
        cout << "Vector: " << endl;
        cout <<"(";
        for (int i=0; i<dimension; i++){
            cout<< vector.Get(i).real();
            if(vector.Get(i).imag()>=0) cout <<"+";
            cout<<vector.Get(i).imag()<<"*i";
            if (i!=dimension-1) cout<<"; ";
        }
        cout <<")"<< endl;
    }

    void EnterVector(int dim){
        T elem;
        cout << "Enter elements: "<<endl;
        for (int i=0; i<dim; i++){
            cin >> elem;
            this->Set(elem,i);
        }
    }

};
#endif //LABA2_VECTOR_H
