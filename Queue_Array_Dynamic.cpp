#include <iostream>

using namespace std;
int head = 0;
void traversal(int* arr, int arrSize){
    for(int i=0; i<arrSize; i++){
        cout << arr[i] << endl;
    }
}
void insert(int* arr, int arrSize){
    if(head >= arrSize){
         cout << "Queue is full";
         return;
    }
    int el;
    cout << "Enter element to input in Queue";
    cin >> el;
    arr[head] = el;
    head++;
}

void shiftArr(int* arr){
    for(int i=1 ; i<head; i++){
        arr[i-1] = arr[i];
    }
    head--;
    arr[head] = 0;
}
void deletion(int* arr){
    if(head == 0){
        cout << "Empty Queue";
        return;
    }
   cout << "Element deleted  : " << arr[0];
   shiftArr(arr);
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
   cout << "Enter size of Queue : ";
   cin >>  arrSize;
   int arr[arrSize];
   cout << "<-----Enter operation ----> \n 1. Insert \n 2. Delete \n 3. Traversal \n 4.Exit \n";
  takeInput(arr,arrSize);
    return 0;
}
