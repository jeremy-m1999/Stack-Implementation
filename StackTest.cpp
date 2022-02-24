#include "Stack.h"

//Tests the various functionalities of the Stack class
int main() {
  //Stack objects
  Stack stack1;
  Stack stack2;
  Stack stack3;
  Stack stack4;
  Stack stack5;
  Stack stack6;
  Stack* stack7;


  cout << endl;
  cout << endl;
  cout << "///////////////////////////////" << endl;
  cout << "Testing" << endl;
  cout << "///////////////////////////////" << endl;
  cout << endl;
  cout << endl;


  cout << "Size of stack1 (Empty): " << stack1.getSize() << endl;
  //cout << "Attempting to pop stack1: " << stack1.pop() << endl;

  stack1.push(1);
  stack1.push(2);
  stack1.push(3);
  stack1.push(4);
  stack1.push(5);
  stack1.push(6);
  stack1.push(7);
  stack1.push(8);
  stack1.push(9);
  stack1.push(10);


  cout << "Size of stack1 after pushing values 1,2,3,4,5,6,7,8,9,10: " << stack1.getSize() << endl;
  cout << "Cap of stack1: " << stack1.getCap() << endl;

  stack1.push(12);

  cout << "Size of stack1 after pushing 1 more value: " << stack1.getSize() << endl;
  cout << "Cap of stack1 after pushing 1 more value: " << stack1.getCap() << endl;

  //stack 1 Values
  stack1.print();

  cout << endl;
  cout << endl;
  cout << "///////////////////////////////" << endl;
  cout << "Copy Constructor Testing" << endl;
  cout << "///////////////////////////////" << endl;
  cout << endl;
  cout << endl;

  //Copy assignment operator testing
  stack2 = stack1;
  cout << "stack2 = stack1" << endl;
  cout << "Stack 2: " << endl;
  stack2.print();
  cout << "Size of stack2: " << stack2.getSize() << endl;
  cout << "Cap of stack2: " << stack2.getCap() << endl;
  cout << "Popping stack2: " << stack2.pop() << endl;
  cout << "Size of stack2 after popping: " << stack2.getSize() << endl;
  cout << "Cap of stack2 after popping: " << stack2.getCap() << endl;
  cout << "Stack 1: " << endl;
  stack1.print();
  cout << "Size of stack1: " << stack1.getSize() << endl;
  cout << "Cap of stack1: " << stack1.getCap() << endl;
  cout << "Address of stack2: " << stack2.getValues() << endl;
  cout << "Address of stack1: " << stack1.getValues() << endl;
  cout << endl;
  cout << endl;

  //Push, pop and isEmpty methods
  cout << "Is stack3 empty? " << stack3.isEmpty() << endl; //1
  cout << "Pushing 3 into stack3" << endl;
  stack3.push(3);
  cout << "Is stack3 empty? " << stack3.isEmpty() << endl; //0
  cout << "Popping stack3: " << stack3.pop() << endl;;
  cout << "Is stack3 empty? " << stack3.isEmpty() << endl; //1
  cout << "Pushing 3 into stack3 3 times" << endl;
  stack3.push(3);
  stack3.push(3);
  stack3.push(3);
  cout << "Size of stack3: " << stack3.getSize() << endl;
  cout << "Cap of stack3: " << stack3.getCap() << endl;
  cout << endl;
  cout << endl;

  //Copy constructor testing
  stack4 = Stack(stack1);
  cout << "stack4 = Stack(stack1)" << endl;
  cout << "Stack 4: " << endl;
  stack4.print();
  cout << "Size of stack4: " << stack4.getSize() << endl;
  cout <<"Cap of stack4: " << stack4.getCap() << endl;
  cout << "Popping stack 4: " << stack4.pop() << endl;
  cout << "Stack 4: " << endl;
  stack4.print();
  cout << "Stack 1: " << endl;
  stack1.print();
  cout << "Size of stack1: " << stack1.getSize() << endl;
  cout << "Cap of stack1: " << stack1.getCap() << endl;
  cout << "Address of stack4: " << stack4.getValues() << endl;
  cout << "Address of stack1: " << stack1.getValues() << endl;
  cout << endl;
  cout << endl;


  cout << "///////////////////////////////" << endl;
  cout << "Move Constructor Testing" << endl;
  cout << "///////////////////////////////" << endl;
  cout << endl;
  cout << endl;

  //Move constructor testing
  stack5 = Stack(move(stack1));
  cout << "stack5 = Stack(move(stack1))" << endl;
  cout << "Stack 5: " << endl;
  stack5.print();
  cout << "Size of stack5: " << stack5.getSize() << endl;
  cout << "Cap of stack5: " << stack5.getCap() << endl;
  cout << "Popping stack 5: " << stack5.pop() << endl;
  cout << "Stack 5: " << endl;
  stack5.print();
  cout << "Stack 1: " << endl;
  stack1.print();
  cout << "Size of stack1: " << stack1.getSize() << endl;
  cout << "Cap of stack1: " << stack1.getCap() << endl;
  cout << "Address of stack5: " << stack5.getValues() << endl;
  cout << "Address of stack1: " << stack1.getValues() << endl;
  cout << endl;
  cout << endl;

  //Move assignment operator testing
  stack6 = move(stack2);
  cout << "stack6 = move(stack2)" << endl;
  cout << "Stack 6: " << endl;
  stack6.print();
  cout << "Popping stack 6: " << stack6.pop() << endl;
  cout << "Stack 6: " << endl;
  stack6.print();
  cout << "Size of stack6: " << stack6.getSize() << endl;
  cout << "Size of stack6: " << stack6.getCap() << endl;
  cout << "Stack 2: " << endl;
  stack2.print();
  cout << "Size of stack2: " << stack2.getSize() << endl;
  cout << "Cap of stack2: " << stack2.getCap() << endl;
  cout << "Address of stack6: " << stack6.getValues() << endl;
  cout << "Address of stack2: " << stack2.getValues() << endl;
  cout << endl;
  cout << endl;

  cout << "///////////////////////////////" << endl;
  cout << "Pointer Testing" << endl;
  cout << "///////////////////////////////" << endl;
  cout << endl;
  cout << endl;

  //Pointer testing
  stack7 = &stack3;
  cout << "stack7 = &stack3" << endl;
  cout << "Stack 7: " << endl;
  stack7 -> print();
  cout << "Size of stack7: " << stack7 -> getSize() << endl;
  cout << "Cap of stack 7: " << stack7 -> getCap() << endl;
  cout << "Popping stack 7: " << stack7 -> pop() << endl;
  stack7 -> print();
  cout << "Size of stack7: " << stack7 -> getSize() << endl;
  cout << "Cap of stack 7: " << stack7 -> getCap() << endl;
  cout << "Stack 3: " << endl;
  stack3.print();
  cout << "Size of stack3: " << stack3.getSize() << endl;
  cout << "Cap of stack3: " << stack3.getCap() << endl;
  cout << "Address of stack7: " << stack7 -> getValues() << endl;
  cout << "Address of stack3: " << stack3.getValues() << endl;
  cout << endl;
  cout << endl;



}
