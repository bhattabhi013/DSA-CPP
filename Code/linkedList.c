#include <stdio.h>

#include <stdlib.h>

struct Node{

    int data;

    struct Node* next;

    struct Node* prev;

};

 struct Node* head = NULL;

 struct Node* currentNode;

    // head = (struct Node* ) malloc(sizeof(struct Node));

    //  currentNode = (struct Node* ) malloc(sizeof(struct Node));

void traversal(){

    struct Node* temp;

    temp = head;

    while(temp !=  NULL){

        printf("%d \n", temp->data);

        temp = temp->next;

    }

}

void addNode(int userData){

    struct Node* newNode;

    newNode = (struct Node* ) malloc(sizeof(struct Node));

    newNode->data = userData;

    newNode->next = NULL;

    newNode->prev = NULL;

    if(head == NULL){

        head = newNode;

        currentNode = head;

         traversal();

        return;

    }

    

    currentNode->next = newNode;

    newNode->prev = currentNode;

    currentNode = newNode;

    traversal();

    

    

}

int getInput(){

    int el;

    printf("\n Enter the operation: \n 1. Insertion \n 2. Deletion \n 3. Reversal \n 4. Traversal \n 5. End \n");

    scanf("%d", &el);

    return el;

}

void deleteNode(int userData){

    struct Node* nexNode = head->next;

    struct Node* temp = head;

    if(temp->data == userData){

        // deletes first node

        head = nexNode;

        free(temp);

        return;

    }

    if(currentNode->data == userData){

        // deletes last node

        temp = currentNode;

        currentNode = currentNode->prev;

        free(temp);

        return;

    }

   while(nexNode != NULL){

       if(temp->data == userData){

           struct Node* prevNode = temp->prev;

           prevNode->next = nexNode;

           nexNode->prev = prevNode;

           free(temp);

           return;

       }

       temp = temp->next;

       nexNode = nexNode->next;

   }

   traversal();

   printf("\n Element not found, enter valid Element");

    

}



void reversal(){

    struct Node* temp = currentNode;

    while(temp != NULL){

        printf("%d \n", temp->data);

        temp = temp->prev;

    }

}

int main()

{

    int data, choice;

    while(choice != 5){

        choice = getInput();

        switch(choice){

        case 1:

        printf("Enter element to enter: ");

        scanf("%d", &data);

        addNode(data);

        break;

        case 2:

        printf("Enter element to delete: ");

        scanf("%d", &data);

        deleteNode(data);

        break;

        case 3:

        reversal();

        break;

        case 4:

        traversal();

        break;

        default:

        break;

    } 

    }

      return 0;

}

