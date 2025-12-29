#include <iostream>
#include "Queue.h"
using namespace std;

int main() {
    Queue<int> q;
    
    q.add(10);
    q.add(20);
    q.add(30);
    q.add(40);
    q.add(50);
    
    cout << "Queue: ";
    q.display();
    cout << "Size: " << q.getSize() << endl;
    
    cout << "\nPeek (front element): " << q.peek() << endl;
    

    cout << "remove: " << q.remove() << endl;
    cout << "remove: " << q.remove() << endl;
    
 
    q.display();
    cout << "Size: " << q.getSize() << endl;
    
  
    q.add(60);
    q.add(70);
    

    q.display();
    cout << "Size: " << q.getSize() << endl;
    
 
    Queue<double> dq;
    dq.add(3.14);
    dq.add(2.71);
    dq.add(1.41);
    
  
    dq.display();
    
    cout << "remove: " << dq.remove() << endl;
  
    dq.display();
    
 
    Queue<int> emptyQ;
    cout << "Is empty? " << (emptyQ.isEmpty() ? "Yes" : "No") << endl;
    
    try {
        emptyQ.remove();
    } catch(const runtime_error& e) {
        cout << "Error: " << e.what() << endl;
    }
    
    return 0;
}
