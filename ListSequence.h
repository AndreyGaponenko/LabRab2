#ifndef LABA2_LISTSEQUENCE_H
#define LABA2_LISTSEQUENCE_H
#include "Sequence.h"
#include "LinkedList.h"
#pragma once
template <typename T> class ListSequence: public Sequence{
private:
    LinkedList<T>* listSequence;
public:
    ListSequence(){
        listSequence = new LinkedList<T>();
    }
    ListSequence(int size){
        listSequence = new LinkedList<T>(size);
    }
    ListSequence(T* elements, int count){
        listSequence= new LinkedList<T>(elements, count);
    }
    ListSequence(LinkedList<T>& list){
        listSequence = LinkedList<T>(list);
    }
    ListSequence(LinkedList<T>* list){
        listSequence=list;
    }
    ListSequence(ListSequence<T>* list){
        listSequence=list->listSequence;
    }

    void DeleteListSequence(){
        listSequence->DeleteLinkedList();
    }

    T GetF override(){
        return listSequence->GetF();
    }
    T GetL override(){
        return listSequence->GetL();
    }
    T Get override(int index){
        return listSequence->Get(index);
    }

    ListSequence<T>* GetSubSequence override(int FirstIndex, int LastIndex){
            ListSequence<T>* NewList;
            NewList->GetSubSequence(FirstIndex,LastIndex);
            auto* listSequence = new ListSequence<T>(NewList);
            return listSequence;
    }

    int GetLength override(){
        return listSequence->GetLength();
    }

    void Append override(T elem){
        listSequence->Append(elem);
    }
    void Prepend override(T elem){
        listSequence->Prepend(elem);
    }
    void Set override(int index, T elem){
        listSequence->Set(index,elem);
    }
    void Insert override(int index, T elem){
        listSequence->Insert(index, elem);
    }

    ListSequence<T>* Concat(Sequence<T>* list) override{
        auto* NewLinkedList = new ListSequence<T>(listSequence);
        for(int i=0; i<list->GetLength();i++){
            NewLinkedList=listSequence->Append(list->Get(i));
        }
        return NewLinkedList;
    }

    T operator[] (int index){
        return listSequence->Get(index);
    }
};
#endif //LABA2_LISTSEQUENCE_H
