#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}
void insertAtBeginning(int value) {
    struct Node* newNode = createNode(value);
    newNode->next = head;
    head = newNode;
    printf("%d inserted at the beginning.\n", value);
}
void insertAtEnd(int value) {
    struct Node* newNode = createNode(value);
    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
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
    struct Node* newNode = createNode(value);
    struct Node* temp = head;
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Position out of bounds!\n");
        free(newNode);
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    printf("%d inserted at position %d.\n", value, position);
}
void deleteFromBeginning() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct Node* temp = head;
    head = head->next;
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
    struct Node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    printf("%d deleted from the end.\n", temp->next->data);
    free(temp->next);
    temp->next = NULL;
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
    struct Node* temp = head;
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL) {
        printf("Position out of bounds!\n");
        return;
    }
    struct Node* toDelete = temp->next;
    temp->next = temp->next->next;
    printf("%d deleted from position %d.\n", toDelete->data, position);
    free(toDelete);
}
void displayList() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
int main() {
    printf("=== Predefined Singly Linked List Operations ===\n");
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
