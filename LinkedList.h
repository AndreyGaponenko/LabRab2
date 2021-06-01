#ifndef LABA2_LINKEDLIST_H
#define LABA2_LINKEDLIST_H
#include <stdexcept>
#include <sstream>
#include <string>
#pragma once
#endif //LABA2_LINKEDLIST_H
using namespace std;
const string NO_INDEX="Such index doesn't exist!";
const string NO_SIZE="The size can't be less than 0!";

template <typename T> class Item{
public:
    T value;
    Item<T>* next;

    Item(){
        value=0;
        next=nullptr;
    }

    Item(T value){
        this->value=value;
        next=nullptr;
    }

    Item(T value, Item<T>* next){
        this->value=value;
        this->next=next;
    }
};

template <typename T> class LinkedList{
private:
    Item<T>* head;
    int size;
    int cap;
public:
    Linkedlist(){
        head=nullptr;
        size=0;
        cap=0;
    }

    LinkedList(int size){
        this->size=size;
        this->cap=size;
        this->head=nullptr;
    }

    LinkedList(T* elements, int count){
        if (count<0){
            throw length_error(NO_SIZE);
        }
        for (int i=0; i<count; i++){
            this->Append(ele,elements[i]);
        }
    }

    LinkedList(LinkedList<T>& list){
        for (int i=0; i<list.GetLength();i++){
            this->Append(list.Get(i));
        }
    }

    LinkedList(LinkedList<T>* list){
        head=list->head;
        size=list->size;
        cap=list->cap;
    }

    void DeleteLinkedList(){
        Item<T>* buffer = new Item<T>();
        //head=nullptr;
        while(head!=nullptr){
            buffer=head;
            delete buffer;
            head=head->next;
        }
        size=0;
        cap=0;
    }

    T GetF(){
        if (head==nulltr){
            throw out_of_range(NO_INDEX);
        }
        return (head->value);
    }

    T GetL(){
        if (head==nullptr){
            throw out_of_range (NO_INDEX);
        }
        return Get(size-1);
    }

    T Get(int index){
        if (index<0 || index>=size){
            throw out_of_range(NO_INDEX);
        }
        Item<T>* buffer = head;
        for (int i=0; i<index; i++){
            buffer=head->next;
        }
        return buffer->value;
    }

    LinkedList<T>* GetSubList(int first, int last){
        if (first<0 || first>=this->size || last<0 || last>=this->size){
            throw out_of_range(NO_INDEX);
        }
        LinkedList<T>* NewList = new LinkedList();
        for (int i=first; i<=last; i++){
            NewList->Append(this->Get(i));
        }
        NewList->size=last-first+1;
        return NewList;
    }

    int GetLength(){
        return this->size;
    }

    void Append(T value){
        Item<T>* NewItem= new Item<T>;
        NewItem->value=value;
        NewItem->next=nullptr;
        if (head==nullptr){
            head=NewItem;
            size=1;
            сap=1;
            return;
        }
        if (head!=nullptr){
            Item<T>* buffer;
            buffer=head;
            while(buffer->next!=nullptr){
                buffer=buffer->next;
            }
            size++;
            buffer->next=NewItem;
        }
    }

    void Prepend(T value){
        Item<T>* NewItem=new Item<T>(T value);
        NewItem->next=head;
        head->NewItem;
        size++;
    }

    void Insert(int Index, T value){
        if (index<0 || index>=this->size){
            throw out_of_range(NO_INDEX);
        }
        Item<T>* buffer = head;
        for (int i=0; i<Index; i++){
            buffer=buffer->next;
        }
        Item<T>* NewItem = new Item<T>*(value, buffer);
        buffer->next=NewItem;
    }

    void Set(int index, T value){
        if (index<0 || index>=this->size){
            throw out_of_range(NO_INDEX);
        }
        Item<T>* buffer = head;
        for (int i=0; i<index; i++){
            buffer=buffer->next;
        }
        buffer->value=value;
    }

    LinkedList<T>* Concat(LinkedList<T>* list){
        Linkedlist<T>* NewList = new LinkedList<T>();
        NewList->head=this->head;
        Item<T>* buffer=this->head;
        for (int i=0; i<this->GetLength()-1; i++){
            buffer=buffer->next;
        }
        NewList->size=this->size+list->size;
        buffer->next=list->head;
        return NewList;
    }

    Item<T>* operator[] (int index){
        if (index<0 || index>=this->GetLength()){
            throw out_of_range(NO_INDEX);
        }
        Item<T>* buffer = head;
        for (int i=0; i<index; i++){
            buffer=buffer->next;
        }
        return buffer;
    }


};