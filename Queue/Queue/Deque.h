#ifndef DEQUE_H
#define DEQUE_H

#include <iostream>
using namespace std;

class Deque{
    private:
        int* items;
        int rear;     
        int front;     
        int capacity;
        
    public:
        Deque(int capacity){
            rear = -1;
            front = -1;
            this->capacity = capacity;
            items = new int[capacity];
        }
        
        ~Deque(){
            delete[] items;
        }
        
     
        bool isFull(){
            return (front == 0 && rear == capacity - 1) || (front == rear + 1);
        }
        
      
        bool isEmpty(){
            return front == -1;
        }
        
       
        void insertRear(int item){
          
            if(isFull()){
                cout << "Deque is Full!" << endl;
                return;
            }
            
            
            if(rear == -1 && front == -1){
                rear = 0;
                front = 0;
            }
            else if(rear == capacity - 1){ 
                rear = 0;
            }
            else{
                rear++;
            }
            
          
            items[rear] = item;
        }
        
      
        void insertFront(int item){
          
            if(isFull()){
                cout << "Deque is Full!" << endl;
                return;
            }
            
         
            if(front == -1 && rear == -1){
                front = 0;
                rear = 0;
            }
            else if(front == 0){ 
                front = capacity - 1;
            }
            else{
                front--;
            }
            
           
            items[front] = item;
        }
        
     
        int deleteFront(){
           
            if(isEmpty()){
                cout << "Empty Deque!" << endl;
                return -1;
            }
            
           
            int temp = items[front];
            
          
            items[front] = -10;
            
         
            if(front == rear){
                front = -1;
                rear = -1;
            }
            else if(front == capacity - 1){ 
                front = 0;
            }
            else{
                front++;
            }
            
          
            return temp;
        }
        
      
        int deleteRear(){
           
            if(isEmpty()){
                cout << "Empty Deque!" << endl;
                return -1;
            }
            int temp = items[rear];
            items[rear] = -10;
            if(front == rear){ 
                front = -1;
                rear = -1;
            }
            else if(rear == 0){ 
                rear = capacity - 1;
            }
            else{
                rear--;
            }
            return temp;
        }
        
   
        void display(){
            cout << "\n========================================\n";
            
         
            if(isEmpty()){
                cout << "Empty Deque";
                cout << "\n========================================\n";
                return;
            }
            int i = front;
            while(i != rear){
                cout << items[i] << "\t";
                i = (i + 1) % capacity;
            }
            cout << items[rear];
            
            cout << "\n========================================\n";
        }
        
        void enterData(int item){
            insertRear(item);
        }
        
        int remove(){
            return deleteFront();
        }
        int getFront(){
            if(isEmpty()){
                cout << "Empty Deque!" << endl;
                return -1;
            }
            return items[front];
        }

        int getRear(){
            if(isEmpty()){
                cout << "Empty Deque!" << endl;
                return -1;
            }
            return items[rear];
        }
};

#endif