#include <stdio.h>

#define SIZE 100

int arr[SIZE];
int n = 0; // current number of elements

void display() {
    printf("Array elements: ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void insertAtEnd(int value) {
    if (n < SIZE)
        arr[n++] = value;
    else
        printf("Array is full\n");
}

void insertAtStart(int value) {
    if (n >= SIZE) {
        printf("Array is full\n");
        return;
    }
    for (int i = n; i > 0; i--)
        arr[i] = arr[i - 1];
    arr[0] = value;
    n++;
}

void insertAtPosition(int pos, int value) {
    if (pos < 0 || pos > n || n >= SIZE) {
        printf("Invalid position or array full.\n");
        return;
    }
    for (int i = n; i > pos; i--)
        arr[i] = arr[i - 1];
    arr[pos] = value;
    n++;
}

void deleteAtEnd() {
    if (n == 0)
        printf("Array is empty.\n");
    else
        n--;
}

void deleteAtStart() {
    if (n == 0) {
        printf("Array is empty.\n");
        return;
    }
    for (int i = 0; i < n - 1; i++)
        arr[i] = arr[i + 1];
    n--;
}

void deleteAtPosition(int pos) {
    if (pos < 0 || pos >= n) {
        printf("Invalid position.\n");
        return;
    }
    for (int i = pos; i < n - 1; i++)
        arr[i] = arr[i + 1];
    n--;
}

void search(int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            printf("Element %d found at position %d\n", key, i);
            return;
        }
    }
    printf("Element %d not found\n", key);
}

int main() {
    // Sample operations
    insertAtEnd(10);
    insertAtEnd(20);
    insertAtEnd(30);
    display();
    
    insertAtStart(5);
    display();
    
    insertAtPosition(2, 15); // insert 15 at index 2
    display();
    
    deleteAtEnd();
    display();
    
    deleteAtStart();
    display();
    
    deleteAtPosition(1); // delete element at index 1
    display();
    
    search(15);
    search(100);

    return 0;
}
