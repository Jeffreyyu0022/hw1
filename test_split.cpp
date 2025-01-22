/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ -g -Wall split.cpp split_test.cpp -o split_test
*/

#include <iostream>
#include "split.h"
using namespace std;


/* Add a prototype for a helper function here if you need */
Node* createNode(int value);
void printList(Node* head);


Node* createNode(int value) {
    return new Node{value, nullptr};
}

void printList(Node* head) {
    while (head != nullptr) {
        cout << head->value << " ";
        head = head->next;
    }
    cout << std::endl;
}

int main(int argc, char* argv[])
{
  Node* numbers = createNode(1);
  numbers->next = createNode(2);
  numbers->next->next = createNode(3);
  numbers->next->next->next = createNode(4);
  numbers->next->next->next->next = createNode(21012);

  cout << "Original list: ";
  printList(numbers);
  Node* odds = nullptr;
  Node* evens = nullptr;
  split(numbers, odds, evens);

  // Print the split lists
  cout << "Odd values list: ";
  printList(odds);

  cout << "Even values list: ";
  printList(evens);

	while(numbers != nullptr){
		Node* temp = numbers;
		numbers = numbers->next;
		delete temp;
	}

  return 0;
}
