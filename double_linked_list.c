#include <stdio.h>
#include <stdlib.h>

struct node {
    int element;
    struct node* linkNext;
    struct node* linkPrev;
};

struct node* createNode(int element) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->element = element;
    newNode->linkNext = NULL;
    newNode->linkPrev = NULL;
    return newNode;
}

struct node* insertAtStart(struct node* first, int element) {
    struct node* newNode = createNode(element);
    if (first != NULL) {
        newNode->linkNext = first;
        first->linkPrev = newNode;
    }
    return newNode;
}

struct node* insertAtEnd(struct node* first, int element) {
    struct node* newNode = createNode(element);
    if (first == NULL) {
        return newNode;
    }
    struct node* temp = first;
    while (temp->linkNext != NULL) {
        temp = temp->linkNext;
    }
    temp->linkNext = newNode;
    newNode->linkPrev = temp;
    return first;
}

struct node* insertAtIndex(struct node* first, int element, int index) {
    if (index < 1) {
        return first;
    }
    if (index == 1) {
        return insertAtStart(first, element);
    }
    struct node* newNode = createNode(element);
    struct node* temp = first;
    for (int i = 1; temp != NULL && i < index - 1; i++) {
        temp = temp->linkNext;
    }
    if (temp == NULL) {
        return first;
    }
    newNode->linkNext = temp->linkNext;
    newNode->linkPrev = temp;
    if (temp->linkNext != NULL) {
        temp->linkNext->linkPrev = newNode;
    }
    temp->linkNext = newNode;
    return first;
}

struct node* removeAtStart(struct node* first) {
    if (first == NULL) {
        return NULL;
    }
    struct node* temp = first->linkNext;
    free(first);
    if (temp != NULL) {
        temp->linkPrev = NULL;
    }
    return temp;
}

struct node* removeAtEnd(struct node* first) {
    if (first == NULL) {
        return NULL;
    }
    if (first->linkNext == NULL) {
        free(first);
        return NULL;
    }
    struct node* temp = first;
    while (temp->linkNext != NULL) {
        temp = temp->linkNext;
    }
    temp->linkPrev->linkNext = NULL;
    free(temp);
    return first;
}

struct node* removeAtIndex(struct node* first, int index) {
    if (first == NULL || index < 1) {
        return first;
    }
    if (index == 1) {
        return removeAtStart(first);
    }
    struct node* temp = first;
    for (int i = 1; temp != NULL && i < index; i++) {
        temp = temp->linkNext;
    }
    if (temp == NULL) {
        return first;
    }
    if (temp->linkNext != NULL) {
        temp->linkNext->linkPrev = temp->linkPrev;
    }
    if (temp->linkPrev != NULL) {
        temp->linkPrev->linkNext = temp->linkNext;
    }
    free(temp);
    return first;
}

void printForward(struct node* first) {
    struct node* temp = first;
    printf("Forward: ");
    while (temp != NULL) {
        printf("%d ", temp->element);
        temp = temp->linkNext;
    }
    printf("\n");
}

void printReverse(struct node* first) {
    if (first == NULL) {
        return;
    }
    struct node* temp = first;
    while (temp->linkNext != NULL) {
        temp = temp->linkNext;
    }
    printf("Reverse: ");
    while (temp != NULL) {
        printf("%d ", temp->element);
        temp = temp->linkPrev;
    }
    printf("\n");
}

int main() {
    struct node* first = NULL;
    first = insertAtEnd(first, 10);
    first = insertAtEnd(first, 20);
    first = insertAtStart(first, 5);
    first = insertAtIndex(first, 15, 2);
    
    printf("After Insertions:\n");
    printForward(first);
    printReverse(first);
    
    first = removeAtStart(first);
    first = removeAtEnd(first);
    first = removeAtIndex(first, 2);
    
    printf("After Deletions:\n");
    printForward(first);
    
    return 0;
}
