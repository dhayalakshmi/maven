#include <stdio.h>
#include <stdlib.h>

struct CNode {
    int data;
    struct CNode* next;
};

struct CNode* head = NULL;

// Function to create a new node
struct CNode* createNode(int value) {
    struct CNode* newNode = (struct CNode*)malloc(sizeof(struct CNode));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Insert at the beginning
void insertAtBeginning(int value) {
    struct CNode* newNode = createNode(value);
    if (head == NULL) {
        head = newNode;
        newNode->next = head; // Points to itself (circular)
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

// Insert at the end
void insertAtEnd(int value) {
    struct CNode* newNode = createNode(value);
    if (head == NULL) {
        head = newNode;
        newNode->next = head; // Points to itself (circular)
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

// Delete from the beginning
void deleteFromBeginning() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct CNode* temp = head;
    if (head->next == head) { // Only one node
        printf("%d deleted from the beginning.\n", head->data);
        free(head);
        head = NULL;
    } else {
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

// Delete from the end
void deleteFromEnd() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct CNode* temp = head;
    struct CNode* prev = NULL;
    if (head->next == head) { // Only one node
        printf("%d deleted from the end.\n", head->data);
        free(head);
        head = NULL;
    } else {
        while (temp->next != head) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = head;
        printf("%d deleted from the end.\n", temp->data);
        free(temp);
    }
}

// Display the circular linked list
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
    printf("(back to head)\n");
}

// Main function (Menu-driven)
int main() {
    int choice, value;
    while (1) {
        printf("\nCircular Linked List Operations:\n");
        printf("1. Insert at Beginning\n2. Insert at End\n");
        printf("3. Delete from Beginning\n4. Delete from End\n");
        printf("5. Display List\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertAtBeginning(value);
                break;
            case 2:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertAtEnd(value);
                break;
            case 3:
                deleteFromBeginning();
                break;
            case 4:
                deleteFromEnd();
                break;
            case 5:
                displayList();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}

