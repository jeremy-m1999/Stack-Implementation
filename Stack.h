#include <sstream>
#include <stdexcept> // for runtime_error
#include <iostream>
#include <string>

using namespace std;

class Stack {

private:

  static const size_t INIT_CAP{10};

  size_t size;
  size_t cap;
  int* values;  // array of ints that will hold the values pushed onto the stack

  void resize();

public:
  Stack();
  Stack(const Stack& other);
  Stack& operator=(const Stack& other);
  Stack(Stack&& other)noexcept;
  Stack& operator=(Stack&& other)noexcept;
  ~Stack();

  void push(int element);
  int pop();
  bool isEmpty();
  void print();

  // These are really for testing.  You wouldn't have them
  // in the API for a real Stack class
  size_t getSize();
  size_t getCap();
  int* getValues();

};
