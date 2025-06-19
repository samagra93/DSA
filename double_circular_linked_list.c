#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = newNode->prev = NULL;
    return newNode;
}
    
struct Node* insertAtBeginning(struct Node* head, int value) {
    struct Node *newNode = createNode(value);
    if (head == NULL) {
        newNode->next = newNode;
        newNode->prev = newNode;
        return newNode;
    }
    struct Node *last = head->prev;
    newNode->next = head;
    newNode->prev = last;
    last->next = newNode;
    head->prev = newNode;
    return newNode;
}

struct Node* insertAtEnd(struct Node* head, int value) {
    struct Node *newNode = createNode(value);
    if (head == NULL) {
        newNode->next = newNode;
        newNode->prev = newNode;
        return newNode;
    }
    struct Node *last = head->prev;
    newNode->next = head;
    newNode->prev = last;
    last->next = newNode;
    head->prev = newNode;
    return head;
}

struct Node* deleteNode(struct Node* head, int value) {
    if (head == NULL) return NULL;
    struct Node *curr = head;
    do {
        if (curr->data == value) {
            if (curr->next == curr) {
                free(curr);
                return NULL; 
            }
            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;
            if (curr == head) head = curr->next;
            free(curr);
            return head;
        }
        curr = curr->next;
    } while (curr != head);
    return head;
}

struct Node* deleteFromBeginning(struct Node* head) {
    if (head == NULL) return NULL;
    struct Node *temp = head;
    if (head->next == head) {
        free(temp);
        return NULL;
    }
    struct Node *last = head->prev;
    head = head->next;
    head->prev = last;
    last->next = head;
    free(temp);
    return head;
}

struct Node* deleteFromEnd(struct Node* head) {
    if (head == NULL) return NULL;
    struct Node *last = head->prev;
    if (head->next == head) {
        free(last);
        return NULL;
    }
    struct Node *secondLast = last->prev;
    secondLast->next = head;
    head->prev = secondLast;
    free(last);
    return head;
}

void displayForward(struct Node* head) {
    if (head == NULL) return;
    struct Node *temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

void displayBackward(struct Node* head) {
    if (head == NULL) return;
    struct Node *temp = head->prev;
    do {
        printf("%d ", temp->data);
        temp = temp->prev;
    } while (temp != head->prev);
    printf("\n");
}

int search(struct Node* head, int value) {
    if (head == NULL) return 0;
    struct Node *temp = head;
    do {
        if (temp->data == value) return 1;
        temp = temp->next;
    } while (temp != head);
    return 0;
}

int main() {
    struct Node* head = NULL;
    head = insertAtEnd(head, 10);
    head = insertAtEnd(head, 20);
    head = insertAtEnd(head, 30);
    head = insertAtBeginning(head, 5);
    displayForward(head);
    displayBackward(head);
    head = deleteNode(head, 20);
    displayForward(head);
    head = deleteFromBeginning(head);
    displayForward(head);
    head = deleteFromEnd(head);
    displayForward(head);
    printf("Search 10: %s\n", search(head, 10) ? "Found" : "Not Found");
    printf("Search 40: %s\n", search(head, 40) ? "Found" : "Not Found");
    return 0;
}
