#include <iostream>
using namespace std;

class Node{
    public :
    int data;
    Node *next;
};

void listTraversal(Node* ptr){
    Node* head = ptr;
    do{
        cout << "Data" << ptr->data << "\n";
        ptr = ptr->next; 
    }
    while(ptr != head);
}
Node* insertAtFirst(Node* ptr, Node* element){
    Node* head = ptr;
    ptr = ptr->next;
    while(ptr->next != head){
        ptr = ptr->next;
    }
    ptr->next = element;
    element->next = head;
    cout << "Insertion at first Node \n";
    return element;
}
void insertAfterLinkedList(Node* ptr, Node* element){
    element->next = ptr->next;
    ptr->next = element;
    cout << "Insertion after Node \n";
}
void insertAtEnd(Node* ptr, Node* element){
    Node* head = ptr;
    ptr = ptr->next;
    while(ptr->next != head){
        ptr = ptr->next;
    }
    element->next = ptr->next;
    ptr->next = element;
    cout << "Insertion at end \n";
}
void insertAtIndex(Node* ptr, Node* element,int index){
    int i = 0;
    while (i != index-2)
    {
        ptr = ptr->next;
        i++;
    }
    element->next = ptr->next;
    ptr->next = element;
    cout << "Index insertion done \n";    
}
Node* deleteFirstNode(Node* ptr){
    Node* head = ptr;
    ptr = ptr->next;
    while(ptr->next != head){
        ptr = ptr->next;
    }
    ptr->next = head->next;
    free(head);
    cout << "Deleted first node \n";
    return ptr->next;
}
void deletingLastNode(Node* ptr){
    Node* head = ptr;
    Node* p = ptr->next;
    while(p->next != head){
        p = p->next;
        ptr = ptr->next;
    }
    ptr->next = p->next;
    free(p);
    cout << "Deleted last node \n";
}
void deletingAtIndex(Node* ptr, int index){
    int i = 0;
    Node* head = ptr->next;
    while(i != index-2){
        head = head->next;
        ptr = ptr->next;
        i++;
    }
    ptr->next = head->next;
    free(head);
    cout << "Deleted at Index \n" << index << "\n";        
}
void deleteValueInList(Node* ptr, int value){
    cout << "Enter value for deletion \n";
    cin >> value;
    Node* head = ptr;
    Node* temp = ptr;
    ptr = ptr->next;
    while(ptr->data != value && ptr != temp){
        head= head->next;
        ptr = ptr->next;
    }
    if(ptr->data == value){
    head->next = ptr->next;
    free(ptr);
    cout << "Value deleted \n" << value << "\n";
    return;
    }

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
    last -> next = head;

    // element to add at head
    Node* newHead =  new Node();
    newHead -> data = 0;
    newHead -> next = NULL;

    // element to add at after a specific node
    Node* nodeAfter =  new Node();
    nodeAfter -> data = 20;
    nodeAfter -> next = NULL;

    // element to add at after a specific node
    Node* lastNode =  new Node();
    lastNode -> data = 40;
    lastNode -> next = NULL;

    Node* elementIndex = new Node();
    elementIndex -> data = 10;
    elementIndex -> next = NULL;

    listTraversal(head);
    head = insertAtFirst(head, newHead);  // insert at first node
    listTraversal(head);
    insertAfterLinkedList(second, nodeAfter);  // insert after a specific node
    listTraversal(head);
    insertAtEnd(head, lastNode);  // insert at last node
    listTraversal(head);
    insertAtIndex(head, elementIndex, 3);  //insert at specific index
    listTraversal(head);
    head = deleteFirstNode(head);  // deletes first node
    listTraversal(head);
    deletingLastNode(head);  // deletes last node
    listTraversal(head);
    deletingAtIndex(head, 4); // deletes at specific index
    listTraversal(head); 
    deleteValueInList(head, 17); // deletes a value
    listTraversal(head);
    return 0;
}
