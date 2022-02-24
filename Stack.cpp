#include "Stack.h"

/*
This program implements the stack data structure in C++ with a pop and push method.
The program also allows the user to see if the stack is empty. There are many ways
to move or copy a stack to another stack using pointers, rvalues, and references.
*/


//Constuctor for Stack
Stack:: Stack() : size{0}, cap{INIT_CAP} {
  values = new int[cap];
}

//Copy Constructor
Stack:: Stack(const Stack& other) {
  size = other.size;
  cap = other.cap;
  values = new int[other.cap];
  //Copies the elements over from the Stack other with appropriate capacity
  for (size_t p = 0; p < other.size; p++) {
    values[p] = other.values[p];
  }
}

// Copy assignment operator
Stack& Stack :: operator=(const Stack& other) {
  if (this == &other) {
    return *this;
  }
  size = other.size;
  cap = other.cap;

  //Copies the elements over from the Stack other with appropriate capacity
  int* newValues = new int[other.cap];
  for (size_t i = 0; i < other.size; i++) {
    newValues[i] = other.values[i];
  }

  delete[] values;
  values = newValues;

  return *this;
}

// Move constructor
Stack:: Stack(Stack&& other)noexcept : size{other.size}, cap{other.cap}, values{new int[other.cap]}{
  for (size_t l = 0; l < other.size; l++) {
    values[l] = other.values[l];
  }
  //Cannibalize the rvalue;
  other.size = 0;
  other.cap = 0;
  other.values = nullptr;
}

// Move assignment operator
Stack& Stack :: operator=(Stack&& other)noexcept {
  if (this == &other) {
    return *this;
  }
  delete[] values;

  //Make a copy of other values
  values = other.values;
  size = other.size;
  cap = other.cap;

  //Canibalizes the rvalues;
  other.values = nullptr;
  other.size = 0;
  other.cap = 0;

  return *this;
}

//Destructor
Stack:: ~Stack() {
  delete[] values;
}

//Changes the capacity of the Stack by double
void Stack:: resize() {
  cap = cap * 2;
  //Creates a new int* that has all of the same elements in the same indices, but with a larger array.
  int* newValues = new int[cap];
  for (size_t y = 0; y < size; y++) {
    newValues[y] = values[y];
  }
  delete[] values;
  values = newValues;
}

//Pushes an element into the stack (LIFO)
void Stack:: push(int element) {
  //To ensure that the stack has enough capacity to store the element
  if (size >= cap) {
    resize();
  }

  values[size] = element;

  //Increases size
  size = size + 1;
}

//Pops the last element inserted into the array and returns its number
int Stack:: pop() {
  //Exception for if there is no elements in the stack
  if (isEmpty()) {
    stringstream ss;
    ss << "Attempt to pop() off an empty stack!";
    throw runtime_error(ss.str().c_str());
  }

  int poppedValue = values[size - 1];
  //Creates a new int* that removes an element at the top of the stack
  int* newValues = new int[cap];

  for (size_t q = 0; q < size - 1; q++) {
    newValues[q] = values[q];
  }


  delete[] values;
  values = newValues;

  //Reduces size
  size = size - 1;

  return poppedValue;
}

//Checks to see if there are no elements
bool Stack:: isEmpty() {
  return size == 0;
}

//Prints all contents of the stack
void Stack:: print() {
  cout << "Values of Stack: " << endl;
  for (size_t e = 0; e < size; e++) {
    cout << values[size - 1 - e] << endl;
  }
}

//Returns size of Stack
size_t Stack:: getSize() {
  return size;
}

//Returns cap of Stack
size_t Stack:: getCap() {
  return cap;
}

//Returns address of values of Stack
int* Stack:: getValues() {
  return values;
}
