#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL, *t, *p;

void create(int v) {
    if (head == NULL) {
        p = (struct node*)malloc(sizeof(struct node));
        p->data = v;
        head = p;
        p->next = head;
    }
}

void insertf(int v) { // insert at front
    p = (struct node*)malloc(sizeof(struct node));
    p->data = v;
    if (head == NULL) {
        head = p;
        p->next = head;
    } else {
        t = head;
        while (t->next != head) {
            t = t->next;
        }
        p->next = head;
        head = p;
        t->next = head;
    }
}

void insert_at(int pos, int v) {
    if (pos == 0) {
        insertf(v);
    } else {
        t = head;
        for (int i = 0; i < pos - 1 && t->next != head; i++) {
            t = t->next;
        }
        p = (struct node*)malloc(sizeof(struct node));
        p->data = v;
        p->next = t->next;
        t->next = p;
    }
}

void display() {
    if (head == NULL) {
        printf("List is empty\n");
    } else {
        t = head;
        do {
            printf("%d ", t->data);
            t = t->next;
        } while (t != head);
        printf("\n");
    }
}

int main() {
    create(10);
    insertf(5);
    insert_at(1, 20);
    insert_at(2, 30);
    display();
    return 0;
}
