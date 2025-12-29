#include <iostream>
#include "LinkedList.h"
using namespace std;

int main() {
    LinkedList<int> list;

 
    list.insert(5);
    list.insert(2);
    list.insert(9);
    list.insert(1);
    list.insert(7);
    cout << "Before Sorting: ";
    list.display();

    list.bubbleSort();
    cout << "After Bubble Sort: ";
    list.display();

    list.selectionSort();
    cout << "After Selection Sort: ";
    list.display();

    list.insertionSort();
    cout << "After Insertion Sort: ";
    list.display();


     Node<int>* found = list.linearSearch(9);
    if (found)
        cout << "Found value: " << found->data << endl;
        
Node<int>* result = list.binarySearch(30);

    if (result != nullptr) {
        cout << "Found: " << result->data << endl;
    } else {
        cout << "Not found!" << endl;
    }


    return 0;
}
