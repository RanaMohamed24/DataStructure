#include <iostream>
#include "LinkedList.h"
using namespace std;

int main() {
    LinkedList<double> list;

 
    list.insert(3.5);
    list.insert(30);
    list.insert(20);
    list.insert(30);
   
   
    

    list.display(); // Output: 3.5 20 30

  
    list.InsertBefore(10.0, 20); 
    
    list.InsertAfter(15.0, 10);  
   
    list.InsertBefore(25.0, 30);
    list.InsertBefore(30.0, 25);
    list.display(); // Output: 3.5 10 15 20 25 30

   
    list.removeNode(10);
    list.RemoveALL(30);
    list.display(); // Output: 3.5 15 20 25 30

   
    cout << "Count: " << list.GetCount() << endl; // 5

   cout << "Element at index 0: " << list.GetDataByIndex(0) << endl;
    cout << "Element at index 1: " << list.GetDataByIndex(1) << endl; // 15
  
  
    cout << "Element at index 5: " << list.GetDataByIndex(5) << endl;
  
      

    return 0;
}
