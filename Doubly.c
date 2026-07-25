#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the doubly linked list
struct DNode {
    int data;
    struct DNode* prev;
    struct DNode* next;
};

struct DNode* head = NULL;

// Function to insert a node at the beginning
void insertAtBeginning(int value) {
    struct DNode* newNode = (struct DNode*)malloc(sizeof(struct DNode));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = head;
    if (head != NULL) {
        head->prev = newNode;
    }
    head = newNode;
    printf("Inserted %d at the beginning.\n", value);
}

// Function to insert a node at the end
void insertAtEnd(int value) {
    struct DNode* newNode = (struct DNode*)malloc(sizeof(struct DNode));
    newNode->data = value;
    newNode->next = NULL;
    if (head == NULL) {
        newNode->prev = NULL;
        head = newNode;
        return;
    }
    struct DNode* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
    printf("Inserted %d at the end.\n", value);
}

// Function to delete a node from the beginning
void deleteFromBeginning() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct DNode* temp = head;
    head = head->next;
    if (head != NULL) {
        head->prev = NULL;
    }
    printf("Deleted %d from the beginning.\n", temp->data);
    free(temp);
}

// Function to delete a node from the end
void deleteFromEnd() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct DNode* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    if (temp->prev != NULL) {
        temp->prev->next = NULL;
    } else {
        head = NULL;
    }
    printf("Deleted %d from the end.\n", temp->data);
    free(temp);
}

// Function to display the doubly linked list
void displayList() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct DNode* temp = head;
    printf("Doubly Linked List: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    insertAtBeginning(10);
    insertAtEnd(20);
    insertAtEnd(30);
    displayList();
    deleteFromBeginning();
    displayList();
    deleteFromEnd();
    displayList();
    return 0;
}
