#include <iostream>
using namespace std;

int binarySearch(int arr[], int size, int element){
    bool indexFound = false;
    int low = 0;
    int max = size;
       for (int i = 0; i < size ; i++)
    {
        cout << "at position" << i << arr[i] << endl;
    }
    while(!indexFound){
    int mean = (low+max%2==0)? low+max/2 : (low+max+1)/2;
     
    cout<< arr[mean];
    if(arr[mean]==element){
        indexFound = true;
        return mean;
    } 
    else if(arr[mean]<element){
        low= mean+1;
    }else{
        max = mean-1;
    }
    }

    return -1;
}

int linearSearch(int arr[], int size, int element)
{
    // linear search
    cout << "arr received at linearsearch" << arr;
    for(int i = 0; i < size ; i++){
        if(element == arr[i]){
            return i;
        }
    }
return -1;  
}
int main(){
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    int size = sizeof(arr)/sizeof(int);
    int index = linearSearch(arr, size, 6);
    if(index != -1){
        cout << "Element found at linear search"<< endl <<  index;
    }
    int indexBinary =  binarySearch(arr, size, 8);
     if(indexBinary != -1){
        cout << "Element found at binary search"<< endl << indexBinary;
    }
    return 0;
}
