#include "slist.h"

/*

Class Library File

*/




 
  

// Destructor

void List::add(Node* val) {
  Node* curr = head;
  while(curr->next != nullptr) {
    curr = curr->next;
    
  }
  curr->next = val;
  
  
  
}		
void List::clear() {
  head = nullptr;
}

bool List::equals(List* list) {
  Node* curr = head;
  Node* compare = list->head;
  bool equal = true;
  while(curr->next != nullptr) {
    if(curr!=compare) {
      equal = false;
      return false;
    }
    curr = curr->next;
    compare = compare->next;
  }
  return true;
}
Node* List::get(int idx) {
  Node* curr = head;
  int counter = idx;
  while(counter != 0) {
    curr = curr->next;
    counter--;
  }
  return curr;
}
void List::insert(int idx, Node* val) {
  Node* curr = get(idx-1);
  Node* temp = curr->next;
  curr->next = val;
  val->next = temp;
  
  
}
void List::exchg(int idx1, int idx2) {
  Node* one = get(idx1);
  Node* two = get(idx2);
  Info temp = two->info;
  two->info = one->info;
  one->info = temp;

}
void List::swap(int idx1, int idx2) {
  Node* one = get(idx1);
  Node* two = get(idx2);
  Node* onePrev = get(idx1-1);
  Node* twoPrev = get(idx2 - 1);
  
  
  one->next = two->next;
  twoPrev->next = one;
  two->next = one->next;
  onePrev->next = two;

  
  
}
bool List::isEmpty() {
  if(head != nullptr) {
    return true;
  }
  return false;
}
void List::remove(int idx) {
  Node* curr = get(idx-1);
  Node* temp = curr->next;
  curr->next = temp->next;
  delete temp;
  
}
void List::set(int idx, Node* val) {
  Node* curr = get(idx-1);
  Node* temp = curr->next;
  curr->next = val;
  val->next = temp->next;
}
int List::ListSize() {
  int counter = 0;
  Node* curr = head;
  while(curr != nullptr) {
    curr = curr->next;
    counter++;
  }
  return counter;
}

//Adds a new value to the end of this list.

// clear()					//Removes all elements from this list.

// equals(list)				//Returns true if the two lists contain the same elements in the same order.

//get(index)				//Returns the element at the specified index in this list.

//insert(index, value)		//Inserts the element into this list before the specified index.

//exchg(index1, index2)		//Switches the payload data of specified indexex.

//swap(index1,index2)		//Swaps node located at index1 with node at index2

// isEmpty()				//Returns true if this list contains no elements.

// remove(index)			//Removes the element at the specified index from this list.

// set(index, value)		//Replaces the element at the specified index in this list with a new value.

// size()					//Returns the number of elements in this list.



// DO NOT IMPLEMENT subList(start, length)	//Returns a new list containing elements from a sub-range of this list.

// DO NOT IMPLEMENT toString()				//Converts the list to a printable string representation.
