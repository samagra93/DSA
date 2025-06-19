#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void push(int data) {
    struct Node* newNode = createNode(data);
    newNode->next = top;
    top = newNode;
    printf("Pushed %d to stack.\n", data);
}

void pop() {
    if (top == NULL) {
        printf("Stack Underflow. Cannot pop.\n");
        return;
    }
    struct Node* temp = top;
    printf("Popped %d from stack.\n", temp->data);
    top = top->next;
    free(temp);
}

void display() {
    if (top == NULL) {
        printf("Stack is empty.\n");
        return;
    }

    struct Node* temp = top;
    printf("Stack (top to bottom): ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    push(10);
    push(20);
    push(30);
    display();

    pop();
    display();

    pop();
    pop();
    pop(); 

    return 0;
}
