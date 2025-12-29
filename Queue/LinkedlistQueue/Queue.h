#ifndef QUEUE_H
#define QUEUE_H
#include "Node.h"
#include <stdexcept>
#include <iostream>
using namespace std;

template<typename T> 
class Queue{
    private:
    Node<T>* front;  
    Node<T>* rear;  
    int size;
    
    public:
    Queue(){
        this->front = NULL;
        this->rear = NULL;
        this->size = 0;
    }
    
    bool isEmpty(){
        return (front == NULL);
    }
    
    
    void add(T data){
        Node<T>* newNode = new Node<T>(data);
        
        if(isEmpty()){
            front = newNode;
            rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        size++;
    }
    
    
    T remove(){
        if(isEmpty()){
            throw runtime_error("Queue is empty! Cannot dequeue.");
        }
        
        Node<T>* temp = front;
        T data = front->data;
        
        front = front->next;
        
        
        if(front == NULL){
            rear = NULL;
        }
        
        delete temp;
        size--;
        return data;
    }
    
    
    T peek(){
        if(isEmpty()){
            throw runtime_error("Queue is empty! Cannot peek.");
        }
        return front->data;
    }
  
    int getSize(){
        return size;
    }
  
    void display(){
        if(isEmpty()){
            cout << "(empty queue)" << endl;
            return;
        }
        
        Node<T>* current = front;
        cout << "Front -> ";
        while(current != NULL) {
            cout << current->data;
            if(current->next != NULL){
                cout << " -> ";
            }
            current = current->next;
        }
        cout << " <- Rear" << endl;
    }
    
   
    void clear(){
        while(!isEmpty()){
            remove();
        }
    }
    ~Queue() {
        Node<T>* current = front;
        while(current != NULL) {
            Node<T>* next = current->next;
            delete current;
            current = next;
        }
    }
};

#endif