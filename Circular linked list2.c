#include <stdio.h>
#include <stdlib.h>

struct CNode {
    int data;
    struct CNode* next;
};

struct CNode* head = NULL;

struct CNode* createNode(int value) {
    struct CNode* newNode = (struct CNode*)malloc(sizeof(struct CNode));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}
void insertAtBeginning(int value) {
    struct CNode* newNode = createNode(value);
    if (head == NULL) {
        head = newNode;
        newNode->next = head; 
    } else {
        struct CNode* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        newNode->next = head;
        temp->next = newNode;
        head = newNode;
    }
    printf("%d inserted at the beginning.\n", value);
}
void insertAtEnd(int value) {
    struct CNode* newNode = createNode(value);
    if (head == NULL) {
        head = newNode;
        newNode->next = head;
    } else {
        struct CNode* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
    printf("%d inserted at the end.\n", value);
}
void deleteFromBeginning() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    
    if (head->next == head) { // Only one node
        printf("%d deleted from the beginning.\n", head->data);
        free(head);
        head = NULL;
    } else {
        struct CNode* temp = head;
        struct CNode* last = head;
        while (last->next != head) {
            last = last->next;
        }
        head = head->next;
        last->next = head;
        printf("%d deleted from the beginning.\n", temp->data);
        free(temp);
    }
}
void deleteFromEnd() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    
    if (head->next == head) { 
        printf("%d deleted from the end.\n", head->data);
        free(head);
        head = NULL;
    } else {
        struct CNode* temp = head;
        struct CNode* prev = NULL;
        while (temp->next != head) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = head;
        printf("%d deleted from the end.\n", temp->data);
        free(temp);
    }
}
void displayList() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    
    struct CNode* temp = head;
    printf("Circular Linked List: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(head)\n");
}

int main() {
    printf("=== Circular Linked List Operations ===\n");
    
    insertAtEnd(10);
    insertAtEnd(20);
    insertAtEnd(30);
    displayList();
    insertAtBeginning(5);
    displayList();
    deleteFromEnd();
    displayList();
    deleteFromBeginning();
    displayList();
    printf("\nFinal ");
    displayList();
    
    return 0;
}
