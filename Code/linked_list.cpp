#include <iostream>
using namespace std;

class Node{
    public :
    int data;
    Node *next;
};

Node* insertionAtStart(Node* ptr, Node* add){
    add->next = ptr;
    return add;
}
void insertAfter(Node* ptr, Node* add, Node* element){

     add->next =  element->next;
     element->next = add;
      cout << "Element added after" << ptr->data;
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
void insertAtIndex(Node* ptr, Node* element,int index){
    int i = 0;
    while(i != index-1){
        ptr = ptr->next;
        i++;
    }
    element->next = ptr->next;
    ptr->next = element;

}
Node* deletionFirstNode(Node* ptr){
  Node* head = ptr->next;
  free(ptr);
  cout << "after deletion \n"; 
  return head;
}
void deleteAtIndex(Node* ptr, int index){
    cout << "Enter index";
    cin >> index;
    int i = 0;
    while(i != index-2){
        ptr = ptr->next;
        i++; 
    };
    Node* El = ptr;
    ptr = ptr->next;
    El->next = ptr->next;
    free(ptr);  
}
void deletingLastNode(Node* ptr){
    Node* temp = ptr;
    ptr = ptr->next;
    while(ptr->next != NULL){
        temp = ptr;
        ptr = ptr->next;
    }
    temp->next = NULL;
    free(ptr);
}
void deletingValueInList(Node* ptr, int value){
    cout << "Enter data value";
    cin >> value;
    Node* temp = ptr->next;
    while(temp->next != NULL && temp->data != value){
        ptr = ptr->next;
        temp = temp->next;
    }
    if(temp->data == value){
        ptr->next = temp->next;
        free(temp);
        return;
    }
    cout << "Not found in list \n";

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

    // to add between a index
    Node* addBetween = new Node();
    addBetween->data = 30;
    addBetween->next = NULL;

    // linkedListTraversal(head); // traversal
    // insertionInLinkedListAtEnd(head, addLast); // at end
    // // linkedListTraversal(head);
    // head = insertionAtStart(head, addStart); // at start
    // linkedListTraversal(head);
    // insertAfter(head, addParticular, second); // insert after specific node
    // linkedListTraversal(head);
    // insertBefore(head, addParticularBefore, second); // insert before specific node
    // linkedListTraversal(head);
    // insertAtIndex(head, addBetween, 6);  // insert between two elements
    // linkedListTraversal(head);
    // head = deletionFirstNode(head); // deletion first element
    // linkedListTraversal(head);
    // deleteAtIndex(head, 2); // delete at specific index
    // linkedListTraversal(head);
    // deletingLastNode(head); // delete last node
    // linkedListTraversal(head);
    deletingValueInList(head, 17); // delete a specific data from list
    linkedListTraversal(head);
    return 0;
}
