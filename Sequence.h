
#ifndef LABA2_SEQUENCE_H
#define LABA2_SEQUENCE_H
#pragma once
template <class T> class Sequence{
    public:
        virtual T GetF()=0;
        virtual T GetL()=0;
        virtual T Get(int index)=0;
        virtual Sequence<T>* GetSubSequence(int FirstIndex, int LastIndex)=0;
        virtual int GetLength()=0;

        virtual void Append(T elem)=0;
        virtual void Prepend(T elem)=0;
        virtual void Set(int index, T elem)=0;
        virtual void Insert(int index,T elem)=0;
        virtual Sequence <T>* Concat(Sequence <T> *list)=0;

        virtual T operator[] (int index)=0;
    };

#endif //LABA2_SEQUENCE_H
