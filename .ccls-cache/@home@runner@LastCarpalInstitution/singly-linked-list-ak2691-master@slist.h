/*

Header file for single linked list class library

*/
#include <string>
#include <iostream>


class Info {
  public:
    char code[10];
    double lat = 0;
    double lon = 0;

};

struct Node {
  Info info;
  Node* next = nullptr;
  
};



class List {
public:
  Node* head;
  Node* tail;
  int size;
  List() {
    head = nullptr;
    tail = nullptr;
  }
  void add(Node* node);				//Adds a new value to the end of this l
  void clear();					//Removes all elements from this list.
  bool equals(List* l);
  Node* get(int idx);
  void insert(int idx, Node* val);
  void exchg(int idx1, int idx2);
  void swap(int idx1, int idx2);
  bool isEmpty();
  //mapall
  void remove(int idx);
  void set(int idx, Node* val);
  int ListSize();
  


};
  

  //Returns true if the two lists contain the same elements in the same order.

//get(index)				//Returns the element at the specified index in this list.

//insert(index, value)		//Inserts the element into this list before the specified index.

//exchg(index1, index2)		//Switches the payload data of specified indexex.

//swap(index1,index2)		//Swaps node located at index1 with node at index2

// isEmpty()				//Returns true if this list contains no elements.

// mapAll(fn)				//Calls the specified function on each element of the linkedlist in ascending index order.

// remove(index)			//Removes the element at the specified index from this list.

// set(index, value)		//Replaces the element at the specified index in this list with a new value.

// size()					//Returns the number of elements in this list.

// subList(start, length)	//Returns a new list containing elements from a sub-range of this list.

// toString()				//Converts the list to a printable string representation.
