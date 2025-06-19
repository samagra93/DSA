#include <stdio.h>
#define MAX 100

int stack[MAX];
int top = -1;

void push(int value) {
    if (top == MAX - 1) {
        printf("Stack Overflow. Cannot push %d\n", value);
        return;
    }
    top++;
    stack[top] = value;
    printf("Pushed %d to stack.\n", value);
}

void pop() {
    if (top == -1) {
        printf("Stack Underflow. Cannot pop.\n");
        return;
    }
    printf("Popped %d from stack.\n", stack[top]);
    top--;
}

void display() {
    if (top == -1) {
        printf("Stack is empty.\n");
        return;
    }

    printf("Stack (top to bottom): ");
    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
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
