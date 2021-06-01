#ifndef LABA2_DYNAMICARRAY_H
#define LABA2_DYNAMICARRAY_H
#include <string>
#include <sstream>
#pragma once
#endif //LABA2_DYNAMICARRAY_H
using namespace std;
const string NO_INDEX="Such index doesn't exist!";
const string NO_SIZE="The size can't be less than 0!";

template <typename T>
class DynArray{
private:
    T* data = nullptr;
    int length;
    int size;
public:
    DynArray(){
        length=0;
        size=0;
    };
    DynArray(int size){
        if (size<0){
            throw length_error(NO_SIZE);
        }
        data = new T[size];
        this->length=size;
        this->size=size;
    };
    DynArray(T* elements, int count){
        if (count<0){
            throw length_error(NO_SIZE);
        };
        data = new T[count];
        length=count;
        size=count;
        for (int i=0; i<count; i++){
            data[i]=elements[i];
        };
    };
    DynArray(DynArray<T> &dynarr){
        length=dynarr.length;
        size=dynarr.size;
        for (int i=0; i<size; i++){
            data[i]=dynarr.data[i];
        };
    };
    DynArray(DynArray<T>* dynarr){
        length=dynarr->length;
        size=dynarr->size;
        data=dynarr->data;
    }

    void DeleteDynArray(){
        delete [] data;
        length=0;
        size=0;
    };

    string InterpString(int value){
        ostringstream os;
        os << value;
        return os.str();
    }

    T Get(int index){
        if ((index<0)||(index>=length)){
            string message = NO_INDEX + " You want to get " + InterpString(index)+" element, but there are only "+InterpString(length);
            throw out_of_range(message);
        }
        return data[index];
    }

    int GetLength(){
        return length;
    }

    int GetSize(){
        return size;
    }

    void Set(int index, T value){
        if ((index<0)||(index>=length)){
            string message = NO_INDEX + " You want to get " + InterpString(index)+" element, but there are only "+InterpString(length);
            throw out_of_range(message);
        }
        data[index]=value;
    }

    void Resize(int NewSize){
        if (NewSize<0){
            throw out_of_range(NO_INDEX);
        }
        if (NewSize==0){
            delete [] data;
            length=0;
            size=0;
            return;
        }
        if (NewSize==size) {
            return;
        }
        if (NewSize<size){
            T* data2 = new T[NewSize];
            for (int i=0; i<NewSize; i++){
                data2[i]=data[i];
            }
            delete[] data;
            data=data2;
            if (length>NewSize)
                length=NewSize;
            size=NewSize;
            return;
        }else if(NewSize>size){
            T* data2 = new T[NewSize];
            for (int i=0; i<NewSize; i++){
                data2[i]=data[i];
            }
            delete[] data;
            data=data2;
            length=NewSize;
            size=NewSize;
            return;
        }
    }
    void ReLength(int NewLength){
        if (NewLength>size || NewLength<0 || NewLength<length){
            throw out_of_range(NO_INDEX);
        }
        length=NewLength;
    }

    T operator[] (int index){
        if (index<0 || index >= this->size){
            throw out_of_range(NO_INDEX);
        }
        return this->Get(index);
    }
};
