#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *prev;
    Node *next;
};

void listTraversal(Node* ptr){
    Node* temp = new Node();
    cout << "Ascending traversal \n" ;
    while(ptr != NULL){
        cout << ptr->data << "\n";
        temp = ptr->prev;
        ptr = ptr->next;
    }
    // ptr = temp->next;
    // cout << "Descending traversal \n";
    // while(ptr != NULL){
    //     cout << ptr->data << "\n";
    //     ptr = ptr->prev;
    // }

}
Node* insertAtStart(Node* ptr, Node* element){
    ptr->prev = element;
    element->next = ptr;
    element->prev = NULL;
    cout << "Inserted at starting";
    return element;
}
void insertAtLast(Node* ptr, Node* element){
    while(ptr->next != NULL){
        ptr = ptr->next;
    };
    ptr->next = element;
    element->prev = ptr;
    cout << "Inserted at End";
}
void insertAtIndex(Node* ptr, Node* element, int index){
    int i = 0;
    while(i != index-2){
        ptr = ptr->next;
        i++;
    }
    Node* nextnode = ptr->next;
    element->next = ptr->next;
    ptr->next = element;
    element->prev = ptr;
    nextnode->prev = element;
    cout << "Inserted at index \n" << index;
}
Node* deletehead(Node* ptr){
    Node* head =  ptr;
    ptr = ptr->next;
    ptr->prev = NULL;
    free(head);
    cout << "Deleted head \n";
    return ptr;
}
void deleteLast(Node* ptr){
    while(ptr->next != NULL){
        ptr = ptr->next;
    }
    Node* prevNode = ptr->prev;
    prevNode->next = NULL;
    free(ptr);
    cout << "Deleted last Node \n";
}
void deleteAtIndex(Node* ptr, int index){
    int i = 0;
    while( i != index-2){
        ptr = ptr->next;
        i++;
    }
    Node* temp = ptr;
    ptr = ptr->next;
    Node* nextNode = ptr->next;
    temp->next = nextNode;
    nextNode->prev = temp;
    free(ptr);
    cout << "Deleted from Index  " << index << '\n';
}
void deleteValueFromList(Node* ptr, int data){
    while(ptr->next != NULL && ptr->data != data){
        ptr = ptr->next;
    }
    if(ptr->data == data){
        Node* temp = ptr->prev;
        Node* nextNode = ptr->next;
        temp->next = ptr->next;
        nextNode->prev = temp;
        free(ptr);   
    }
    cout << "Deleted data \n" << data << "\n";
}

int main(){
    Node* head = new Node();
    Node* second = new Node();
    Node* third = new Node();
    Node* last = new Node();
    
    // data allocation and link with second
    head -> data = 7;
    head -> next = second;
    head -> prev = NULL;
    
    // data allocation and link with third
    second -> data = 17;
    second -> next = third;
    second -> prev = head;

    // data allocation and link with third
    third -> data = 27;
    third -> next = last;
    third -> prev = second;
    
    // data allocation and end
    last -> data = 37;
    last -> next = NULL;
    last -> prev = third;

    // node to insert at start
    Node* newHead = new Node();
    newHead->data = 0;
    newHead->next = NULL;
    newHead->prev = NULL;

    // node to insert at last
    Node* lastNode = new Node();
    lastNode->data = 47;
    lastNode->prev = NULL;
    lastNode->next = NULL;

    // node to insert after an index
    Node* indexElement = new Node();
    indexElement->data = 10;
    indexElement->prev = NULL;
    indexElement->next = NULL;

    listTraversal(head);
    head = insertAtStart(head, newHead); // inserts node at starting and makes new head
    listTraversal(head);
    insertAtLast(head, lastNode);   // insets node at last 
    listTraversal(head);
    insertAtIndex(head, indexElement, 3); // inserts at specific index
    listTraversal(head);
    head = deletehead(head); // deletes head from the list
    listTraversal(head);
    deleteLast(head); // deletes last element from the list
    listTraversal(head);
    deleteAtIndex(head, 3);  // delets from a specific index
    listTraversal(head);
    deleteValueFromList(head, 10); // deletes a data value from list
    listTraversal(head);

    return 0;
}
