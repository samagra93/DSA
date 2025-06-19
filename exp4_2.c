#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    char items[MAX_SIZE];
    int front;
    int rear;
} Queue;

void initializeQueue(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

int isEmpty(Queue *q) {
    return q->front == -1;
}

void enqueue(Queue *q, char value) {
    if (q->rear == MAX_SIZE - 1) {
        printf("Queue is full\n");
        return;
    }
    if (q->front == -1) {
        q->front = 0;
    }
    q->rear++;
    q->items[q->rear] = value;
}

char dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return '\0';
    }
    char item = q->items[q->front];
    q->front++;
    if (q->front > q->rear) {
        initializeQueue(q);
    }
    return item;
}

int isPalindromeArray(char str[]) {
    int length = strlen(str);
    for (int i = 0; i < length / 2; i++) {
        if (str[i] != str[length - i - 1]) {
            return 0; 
        }
    }
    return 1; 
}

int isPalindromeQueue(char str[]) {
    Queue q;
    initializeQueue(&q);
    int length = strlen(str);

    for (int i = 0; i < length; i++) {
        enqueue(&q, str[i]);
    }

    for (int i = length - 1; i >= 0; i--) {
        if (dequeue(&q) != str[i]) {
            return 0; 
        }
    }
    return 1; 
}

int main() {
    char str[MAX_SIZE];

    printf("Enter a string: ");
    fgets(str, MAX_SIZE, stdin);
    str[strcspn(str, "\n")] = '\0';

    if (isPalindromeArray(str)) {
        printf("Using Array: The string is a palindrome.\n");
    } else {
        printf("Using Array: The string is not a palindrome.\n");
    }

    if (isPalindromeQueue(str)) {
        printf("Using Queue: The string is a palindrome.\n");
    } else {
        printf("Using Queue: The string is not a palindrome.\n");
    }

    return 0;
}
