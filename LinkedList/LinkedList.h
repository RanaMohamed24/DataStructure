#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Node.h"
#include <iostream>
using namespace std;
template<typename T> 
class LinkedList{
    private:
    Node<T>*head;
    Node<T>*tail;
    public:
    LinkedList(){
        this->head=NULL;
        this->tail=NULL;

    }
    bool isEmpty(){
        return(head==NULL);
    }
    
    void insert(T data){
        Node<T>* newNode= new Node<T>(data);
        if(isEmpty()){
            head=newNode;
            tail=newNode;
            return;
        }
        newNode->prev=tail;
        tail->next=newNode;
        tail=newNode;
    }
    void display(){
        if(isEmpty()){
            cout<<"(empty list)"<<endl;
            return;
        }
        Node<T>* current = head;
    while(current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
        
    }
      private:
      Node<T>* getNode(T data){
        if(isEmpty()){
            return NULL;
        }
        Node<T>* current = head;
        while(current != NULL) {
             if(current->data == data){
                return current;
           }
            current = current->next;
       }
        return NULL;
      }
    public:
      void removeNode(T data){
        Node<T>* current = getNode(data);
        if( current == NULL){
            return ;
        }
        if(current == head){
            if(head == tail){
                head = NULL;
                tail = NULL;
                return;
            }else{
                head=current->next;
                head->prev = NULL;
            }
        }else if(current != tail){
            Node<T>* before =current->prev;
            Node<T>* after = current->next;
            before->next = after;
            after->prev = before;
        }else{
            tail=current->prev;
            tail->next = NULL;
        }
    
            
        delete current;

      
    }
    void InsertAfter(T data, T afterData){
        Node<T>* current = getNode(afterData);
        if( current == NULL){
            return ;
        }
        Node<T>* newNode= new Node<T>(data);
        if(current == tail){
            newNode->prev=tail;
            tail->next=newNode;
            tail=newNode;
            return;
        }
        Node<T>* after = current->next;
        newNode->next = after;
        newNode->prev = current;
        current->next = newNode;
        after->prev = newNode;
    } 
     void InsertBefore(T data, T beforeData){
        Node<T>* current = getNode(beforeData);
        if( current == NULL){
            return ;
        }
        Node<T>* newNode= new Node<T>(data);
        if(current == head){
            newNode->next=current;
            current->prev=newNode;
            head=newNode;
            return;
        }
        Node<T>* before = current->prev;
        newNode->prev = before;
        newNode->next = current;
        before->next = newNode;
        current->prev = newNode;
     }
      int GetCount(){
        int count =0;
        Node<T>* current = head;
        while(current != NULL) {
            count++;
            current = current->next;
        }
        return count;
      }
    
    T GetDataByIndex(int index) {
    if(index < 0 || index >= GetCount()) {
        throw out_of_range("Index out of range");
    }

    int currentIndex = 0;
    Node<T>* current = head;

    while(current != nullptr) {
        if(currentIndex == index) {
            return current->data;
        }
        current = current->next;   
        currentIndex++;           
    }

    
    throw out_of_range("Index out of range");
}
 void RemoveALL(T data){
    Node<T>* current = getNode(data);
    while(current != NULL) {
        Node<T>* toDelete = current;
        current = current->next;
        removeNode(toDelete->data);
        current = getNode(data);
    }

 }
~LinkedList() {
    Node<T>* current = head;
    while(current != nullptr) {
        Node<T>* next = current->next;
        delete current;
        current = next;
    }
}

        
    };

    
  


#endif