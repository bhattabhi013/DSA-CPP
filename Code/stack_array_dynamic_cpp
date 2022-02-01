#include <iostream>

using namespace std;
int head = 0;
void traversal(int* arr, int arrSize){
    for(int i=0; i<arrSize; i++){
        cout << arr[i] << endl;
    }
}
void insert(int* arr, int arrSize){
       if(head==0){
        cout << "Empty Stack";
        // return;
    }
    if(head >= arrSize){
         cout << "Stack is full";
         return;
    }
    int el;
    cout << "Enter element to input in stack";
    cin >> el;
    arr[head] = el;
    head++;
}

void deletion(int* arr){
    if(head == 0){
        cout << "Empty Stack";
        return;
    }
   cout << "Element deleted  : " << arr[head-1];
   arr[head-1] =0;
   head--;
}
void takeInput(int* arr, int arrSize){
    int input = 0;
    while(input != 4){
        cout<< "\n Enter Input \n";
        cin>> input;
        switch(input){
        case 1: 
        insert(arr, arrSize);
        break;
        case 2:
        deletion(arr);
        break;
        case 3:
        traversal(arr, arrSize);
        break;
        case 4:
        break;
        default:
        break;
        
    }
}
}
int main()
{
    int arrSize;
   cout << "Enter size of stack : ";
   cin >>  arrSize;
   int arr[arrSize];
   cout << "<-----Enter operation ----> \n 1. Insert \n 2. Delete \n 3. Traversal \n 4.Exit \n";
  takeInput(arr,arrSize);
    return 0;
}
