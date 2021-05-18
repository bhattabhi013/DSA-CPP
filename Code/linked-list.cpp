#include <iostream>
using namespace std;

class Node{
    public :
    int data;
    Node *next;
};

void insertionAtStart(Node* ptr, Node* add){
    add->next = ptr;
}
void insertAfter(Node* ptr, Node* add, Node* element){
    while(ptr->next != NULL){
        ptr = ptr->next;
        if(ptr == element){
           add->next =  ptr->next;
           ptr->next = add;
           cout << "Element added after" << ptr;
           return;
        }
    }
}
void insertionInLinkedListAtEnd(Node* ptr, Node* add){
    while(ptr != NULL){
        ptr = ptr->next;
        if(ptr->next== NULL){
            ptr->next = add;
            cout << "added successfully";
            return;
        }
        };
}
void insertBefore(Node* ptr, Node* add, Node* element){
    while(ptr->next != NULL){
        if(ptr->next == element){
            add->next = ptr->next;
            ptr->next = add;
            cout << "Element added before" << ptr;
           return;
        }
        ptr = ptr->next;
    }
}
void linkedListTraversal(Node* ptr)
{
    while(ptr != NULL){
        cout << "Data at node" << ptr->data << endl;
        ptr = ptr->next;
    };
}
int main(){
    
    Node* head = new Node();
    Node* second = new Node();
    Node* third = new Node();
    Node* last = new Node();
    
    // data allocation and link with second
    head -> data = 7;
    head -> next = second;
    
    // data allocation and link with third
    second -> data = 17;
    second -> next = third;

    // data allocation and link with third
    third -> data = 27;
    third -> next = last;

    // data allocation and end
    last -> data = 37;
    last -> next = NULL;

    // to add a node in the last
    Node* addLast = new Node();
    addLast->data = 47;
    addLast->next = NULL;

    // to add a node at starting
    Node* addStart = new Node();
    addStart->data = 0;
    addStart->next = NULL;

    // to add after a specific node
    Node *addParticular = new Node();
    addParticular->data = 20;
    addParticular->next = NULL;

    // to add after a specific node
    Node *addParticularBefore = new Node();
    addParticularBefore->data = 10;
    addParticularBefore->next = NULL;


    linkedListTraversal(head); // traversal
    insertionInLinkedListAtEnd(head, addLast); // at end
    linkedListTraversal(head);
    insertionAtStart(head, addStart); // at start
    linkedListTraversal(addStart);
    insertAfter(addStart, addParticular, second); // insert after specific node
    linkedListTraversal(addStart);
    insertBefore(addStart, addParticularBefore, second); // insert before specific node
    linkedListTraversal(addStart);
    return 0;
}