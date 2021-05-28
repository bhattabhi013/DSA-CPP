#include <iostream>
using namespace std;

  int maxSize = 5;
  int arr[5];
  int top = -1;

  bool isEmpty()
  {
    if(top == -1){
      return true;
    }
    return false;
  }
  void push(int element)
  {
    if(top < maxSize-1){
      ++top;
      arr[top] = element;
      return;
    } 
    cout << "Overflow \n";
  }
  int pop()
  {
    if(isEmpty()){
      cout << "Empty Stack \n";
      return 0;
    }
    int popElement = arr[top];
    arr[top] = 0;
    --top;
    return popElement;
  }
  int peek(int index)
  {
    // start from bottom of stack
    // if(index < maxSize){
    // return arr[index];
    // }
    
    //start from top of stack
    // if (index <= maxSize)
    // {
    //   int newIndex = maxSize - index;
    //   return arr[newIndex];
    // }

    // on runtime position
    if(index <= maxSize){
      int newInd = top - index + 1 ;
      return arr[newInd];
    }
    
    cout << "Index not available \n";
  }
  void stackTraversal()
  {
    int i =0;
    cout << "Traversal started \n";
    while(i < maxSize)
    {
      cout << i << "  " << arr[i] << "\n";
      i++;
    }
  }




int main(){

  int operation;
  int element ;
  // s.push(10);
  // s.push(11);
  // s.push(12);
  // cout << "popped" << s.pop();
  // cout << "element at " << s.peek(2) << "\n";
  // s.stackTraversal();
  // cout << s.isEmpty();

  cout << "Chooose operation \n 1. push \n 2. pop \n 3. peek \n 4. stack traversal \n 5. end operation \n ";
  cin >> operation;
  switch (operation)
  {
  case 1:
  cout << "Element to push \n";
  cin >> element;
  push(element);
    break;
  case 2:
  int popedVal;
  popedVal = pop();
  cout << "Element popped out  " << popedVal << '\n';
  break;
  case 3:
  int index;
  cout << "Select index to peek , Please type a number between 1 to 5\n";
  cin >> index;
  element = peek(index);
  cout << "Element at index " << index << "\n" << element << "\n";
  break;
  case 4:
  stackTraversal();
  case 5:
  return 0;
  default:
    break;
  }
  main();
  return 0;
}
