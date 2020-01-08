//
//  main.cpp
//  Linked List
//
//  Created by Archangel on 07/01/20.
//  Copyright © 2020 Kaleb Juliu. All rights reserved.
//

#include <iostream>

class Node{
public:
    int data;
    Node* next;
};
void printList(Node* head){            //Printing Node
    
    Node* temporary = head;            //Create a "temporary" Node and set it to the head
    while(temporary != NULL){          //While the temporary doesn't equal to NULL meaning that as long as the temporary                                                            doesn't point to a NULL
        printf("%d ", temporary->data);//Print the value
        temporary = temporary->next;   //Move "temporary" to point to the next Node
    }                                  //"temporary" is now equal to the next Node
    printf("\n");
}

void insertNode(Node*head, int data, int n){
    Node* temp1 = new Node();          //Create a "temp1" node in the heap
    temp1->data = data;                //Set the data of the "temp1" Node
    temp1->next = NULL;                //Point it to NULL
                                        
    if(n == 1){                        //If inserted at the first node
        temp1->next = head;
        head = temp1;
        return;
    }
    Node* temp2 = head;                //If not create a "temp2" Node and point it to the head
    for(int i = 0; i < n-2; i++){      //Set "temp2" so it is pointing to whatever n-2 is pointing
        temp2 = temp2->next;
    }
    temp1->next = temp2->next;         //Now "temp1" is pointing to the same Node as "temp2"
    temp2->next = temp1;               //Set n-2th element so it points to the new element
    
}

void deleteNode(Node* head, int n){
    Node* temp3 = head;                //Set "temp3" so it is pointing to the head
    if(n == 1){                        //If deleting at first Node
        head  = temp3->next;
        delete temp3;
        return;
    }
    for(int i = 0; i < n-2; i++){      //If not set "temp3" so it is pointing to the n-1 Node
        temp3 = temp3->next;
    }
    Node* temp4 = temp3->next;         //Create "temp4" Node that is pointing to the n-th Node (currently temp3 and temp4 are side by side)
    temp3->next = temp4->next;         //Set the pointer of "temp3" so it is pointing n+1 Node
    delete temp4;                      //Delete the Node that "temp4" is pointing
    
}

Node* createNode(int value){    //Insering Node at the beggining of the list
                                
    Node* result = new Node();  //Allocate memory in the heap for a node
    result->data = value;       //Set the data of the "result" node
    result->next = NULL;        //Point it to NULL
    
    return result;              //Return the Node
}


int main(int argc, const char * argv[]) {
    Node* head = NULL;          //Create a head Node and point it to NULL
    Node* temp;                 //Allocate a memory in the heap for Node "temp"
    
    int linked_list_size;
    std::cout << "Insert Linked List size:";
    std::cin >> linked_list_size;
    
    for(int i = 0; i < linked_list_size; i++){
        int x;
        printf("Insert a number: ");
        scanf("%d", &x);
        
        temp = createNode(x);   //Store the return Node to the "temp" Node
        temp->next = head;      //Point the "temp" to the current head
        head = temp;            //Set the "temp" as the head node
    
        printList(head);
    }
    insertNode(head, 13, 4);
    printList(head);
    // Removing a node by pointing the head node to the next node
    //head = head->next;
    deleteNode(head, 4);
    printList(head);
    return 0;
}
