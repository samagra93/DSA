#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(int data) {
    struct Node* newNode = createNode(data);
    newNode->next = head;
    head = newNode;
}

void insertAtEnd(int data) {
    struct Node* newNode = createNode(data);

    if (head == NULL) {
        head = newNode;
        return;
    }

    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

void insertAtPosition(int pos, int data) {
    if (pos == 0) {
        insertAtBeginning(data);
        return;
    }

    struct Node* temp = head;
    for (int i = 0; i < pos - 1; i++) {
        if (temp == NULL) {
            return;
        }
        temp = temp->next;
    }

    if (temp == NULL) {
        return;
    }

    struct Node* newNode = createNode(data);
    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteAtBeginning() {
    if (head == NULL) {
        return;
    }

    struct Node* temp = head;
    head = head->next;
    free(temp);
}

void deleteAtEnd() {
    if (head == NULL) {
        return;
    }

    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }

    struct Node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    free(temp->next);
    temp->next = NULL;
}

void deleteAtPosition(int pos) {
    if (head == NULL) {
        return;
    }

    if (pos == 0) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return;
    }

    struct Node* temp = head;
    for (int i = 0; i < pos - 1; i++) {
        if (temp == NULL || temp->next == NULL) {
            return;
        }
        temp = temp->next;
    }

    struct Node* delNode = temp->next;
    if (delNode == NULL) {
        return;
    }

    temp->next = delNode->next;
    free(delNode);
}

void display() {
    struct Node* temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    printf("Inserting 10 at the end.\n");
    insertAtEnd(10);
    display();

    printf("Inserting 5 at the beginning.\n");
    insertAtBeginning(5);
    display();

    printf("Inserting 7 at position 1.\n");
    insertAtPosition(1, 7);
    display();

    printf("Deleting element at position 1.\n");
    deleteAtPosition(1);
    display();

    printf("Deleting element at the beginning.\n");
    deleteAtBeginning();
    display();

    printf("Deleting element at the end.\n");
    deleteAtEnd();
    display();

    printf("Trying to delete from an empty list.\n");
    deleteAtBeginning();
    display();

    return 0;
}
