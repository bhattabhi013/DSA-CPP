#include <iostream>
using namespace std;

void display(int arr[], int used_Size)
{
    // traversal
    for (int i = 0; i < used_Size; i++)
    {
        cout << "at position" << i << arr[i] << endl;
    }
    cout << used_Size;
}
int insertion(int arr[], int used_size, int insertElement, int capacity, int index)
{
    // insertion
    if (used_size >= capacity)
    {
        cout << "Capacity full, overload error";
        return -1;
    }
    for (int i = used_size - 1; i >= index; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[index] = insertElement;
    return 1;
}

int deletion(int arr[], int deleteElement, int index, int used_size)
{
    if(sizeof(arr)<=0){
    return -1;
    }
    for(int i=index;i<used_size-1;i++){
        arr[i] = arr[i+1];
    }
    
    return 1;
}
int main()
{
    int used_Size = 4;
    int element = 45;
    int index = 3;
    int arr[100] = {1, 2, 3, 4};
    display(arr, used_Size);
    if (insertion(arr, used_Size, element, sizeof(arr), index) == 1)
    {
        used_Size++;
    };
    display(arr, used_Size);
    if(deletion(arr, element, index, used_Size)==1){
        used_Size--;
    };
    display(arr, used_Size);
    return 0;
}
