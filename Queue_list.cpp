#include <iostream>

using namespace std;

class Node{
    public:
    Node(int val){
        data = val;
        next = NULL;
    }
    int data;
    Node* next;
};
void pushQueue(Node* head){
   Node* temp = head;
   int val = 0;
   cout << "Enter element to push into Queue" <<endl;
   cin >> val;
   Node* newNode  = new Node(val);
   if(!newNode){
       cout << "Full Queue" << endl;
       return;
   }
   while(temp->next){
       temp = temp->next;
   }
   temp->next =  newNode;
}

void dequeue(Node* head){
    Node* temp = head;
    if(!temp->next){
        cout << "Empty Queue" <<endl;
        return;
    }
    cout << "Element popped:  " << temp->next->data <<endl;
    temp->next = temp->next->next;
}

void queueTraversal(Node* head){
    Node* temp = head->next;
    cout << "queueTraversal" <<endl;
    while(temp){
        cout << temp->data <<endl;
        temp = temp->next;
    }
}

void takeInput(Node* head){
    int input = 0;
    while(input != 4){
        cout<< "\n Enter Input \n";
        cin>> input;
        switch(input){
        case 1: 
        pushQueue(head);
        break;
        case 2:
        dequeue(head);
        break;
        case 3:
        queueTraversal(head);
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
    Node* head = new Node(0);
    cout << "<-----Enter operation ----> \n 1. Insert \n 2. Delete \n 3. Traversal \n 4.Exit \n";
    takeInput(head);
    return 0;
}