#include <stdio.h>
#include <stdlib.h>

struct DNode {
    int data;
    struct DNode* prev;
    struct DNode* next;
};

struct DNode* head = NULL;

struct DNode* createNode(int value) {
    struct DNode* newNode = (struct DNode*)malloc(sizeof(struct DNode));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}
void insertAtBeginning(int value) {
    struct DNode* newNode = createNode(value);
    if (head == NULL) {
        head = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    printf("%d inserted at the beginning.\n", value);
}
void insertAtEnd(int value) {
    struct DNode* newNode = createNode(value);
    if (head == NULL) {
        head = newNode;
    } else {
        struct DNode* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
    printf("%d inserted at the end.\n", value);
}
void insertAtPosition(int value, int position) {
    if (position < 1) {
        printf("Invalid position!\n");
        return;
    }
    if (position == 1) {
        insertAtBeginning(value);
        return;
    }
    struct DNode* newNode = createNode(value);
    struct DNode* temp = head;
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Position out of bounds!\n");
        free(newNode);
        return;
    }
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
    printf("%d inserted at position %d.\n", value, position);
}
void deleteFromBeginning() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct DNode* temp = head;
    head = head->next;
    if (head != NULL) {
        head->prev = NULL;
    }
    printf("%d deleted from the beginning.\n", temp->data);
    free(temp);
}
void deleteFromEnd() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    if (head->next == NULL) {
        printf("%d deleted from the end.\n", head->data);
        free(head);
        head = NULL;
        return;
    }
    struct DNode* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->prev->next = NULL;
    printf("%d deleted from the end.\n", temp->data);
    free(temp);
}
void deleteFromPosition(int position) {
    if (position < 1) {
        printf("Invalid position!\n");
        return;
    }
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    if (position == 1) {
        deleteFromBeginning();
        return;
    }
    struct DNode* temp = head;
    for (int i = 1; i < position && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Position out of bounds!\n");
        return;
    }
    temp->prev->next = temp->next;
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    printf("%d deleted from position %d.\n", temp->data, position);
    free(temp);
}
void displayList() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct DNode* temp = head;
    printf("Doubly Linked List (Forward): ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
int main() {
 printf("=== Predefined Doubly Linked List Operations ===\n");
    insertAtEnd(10);
    insertAtEnd(20);
    insertAtEnd(30);
    displayList();
    insertAtBeginning(5);
    displayList();
    insertAtPosition(15, 3);
    displayList();
    deleteFromEnd();
    displayList();
    deleteFromBeginning();
    displayList();
    deleteFromPosition(2);
    displayList();
    
    return 0;
}
