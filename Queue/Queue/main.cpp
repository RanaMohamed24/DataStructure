#include <iostream>
using namespace std;
#include "Deque.h"

int main(){
  
    Deque q(5);
    
    q.enterData(10);
    q.enterData(20);
    q.enterData(30);
    q.enterData(40);
    q.enterData(50);
    q.enterData(60);
    q.display(); // 10 20 30 40 50
    
    cout << "Data is " << q.remove() << endl; // 10
    cout << "Data is " << q.remove() << endl; // 20
    q.display(); // 30 40 50
    
    q.enterData(70); // rear = 0
    q.enterData(80); // rear = 1
    q.display(); // 30 40 50 70 80
    
    cout << "Data is " << q.remove() << endl; // 30
    cout << "Data is " << q.remove() << endl; // 40
    cout << "Data is " << q.remove() << endl; // 50
    cout << "Data is " << q.remove() << endl; // 70
    cout << "Data is " << q.remove() << endl; // 80
    cout << "Data is " << q.remove() << endl; // Empty -1
    q.display(); // Empty
    
    q.enterData(90);
    q.enterData(100);
    q.enterData(1000);
    q.display(); // 90 100 1000
    
 
    Deque dq(5);
    


    dq.insertRear(10);
    dq.insertRear(20);
    dq.insertRear(30);
    dq.display(); // 10 20 30
    
    
  
    dq.insertFront(5);
    dq.display(); // 5 10 20 30
    
  
    dq.insertFront(1);
    dq.display(); // 1 5 10 20 30
  
    cout << "\nDeleting from rear: " << dq.deleteRear() << endl; // 30
    dq.display(); // 1 5 10 20

    cout << "\nDeleting from front: " << dq.deleteFront() << endl; // 1
    dq.display(); // 5 10 20
    
 

    dq.insertFront(3);
    dq.insertFront(2);
    dq.display(); // 2 3 5 10 20
    
    cout << "\nDeleting from rear: " << dq.deleteRear() << endl; // 20
    cout << "Deleting from rear: " << dq.deleteRear() << endl; // 10
    dq.display(); // 2 3 5
    
  
   
    dq.insertRear(100);
 
    dq.insertFront(-5);
    dq.display(); // -5 2 3 5 100
    
    cout << "\nFront element: " << dq.getFront() << endl; // -5
    cout << "Rear element: " << dq.getRear() << endl; // 100
    
 
    
    return 0;
}
