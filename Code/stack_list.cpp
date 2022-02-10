#include <iostream>

using namespace std;

class Node {
    public:
    Node(int x){
       data = x; 
       next = NULL;
    }
    int data;
    Node* next;
    // Node* prev;
};

void pushIntoStack(Node* head){
    Node* temp = head;
    int val;
    cout << "Enter element to enter" <<endl;
    cin>> val;
    Node* newNode = new Node(val);
    if(!newNode){
        cout << "\n Stack Overflow";
        return;
    }
    while(temp->next){
        temp = temp->next;
    }
    temp->next = newNode;
};

void popFromStack(Node* head){
    Node* temp = head;
    while(temp->next->next){
        temp = temp->next;
    }
    temp->next = NULL;
}

void stackTraversal(Node* head){
    cout << "Stack Traversal" << endl;
    Node* temp = head->next;
    while(temp){
        cout << temp->data << endl;
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
        pushIntoStack(head);
        break;
        case 2:
        popFromStack(head);
        break;
        case 3:
        stackTraversal(head);
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
