#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    int data;
    struct node* next;
};

struct node* newnode(int data)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

void traverselist(struct node* head) 
{
    struct node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

bool searchlist(struct node* head, int target) {
    while (head != NULL) {
        if (head->data == target) {
            return true;
        }
        head = head->next;
    }
    return false;
}

int findlength(struct node* head) {
    int length = 0;
    while (head != NULL) {
        length++;
        head = head->next;
    }
    return length;
}

struct node* insertatbegin(struct node* head, int value) {
    struct node* new_node = newnode(value);
    new_node->next = head;
    return new_node;
}

struct node* insertatend(struct node* head, int value) {
    struct node* new_node = newnode(value);
    if (head == NULL) {
        return new_node;
    }
    struct node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
    return head;
}

struct node* insertpos(struct node* head, int pos, int value) {
    struct node* new_node = newnode(value);
    if (pos < 1) {
        printf("Invalid operation.\n");
        return head;
    }
    if (pos == 1) {
        new_node->next = head;
        return new_node;
    }
    struct node* prev = head;
    int count = 1;
    while (count < pos - 1 && prev != NULL) {
        prev = prev->next;
        count++;
    }
    if (prev == NULL) {
        printf("Invalid operation.\n");
        return head;
    }
    new_node->next = prev->next;
    prev->next = new_node;
    return head;
}

struct node* removeofbeginnode(struct node* head) {
    if (head == NULL) {
        return NULL;
    }
    struct node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

struct node* removeofendnode(struct node* head) {
    if (head == NULL) {
        return NULL;
    }
    if (head->next == NULL) {
        free(head);
        return NULL;
    }
    struct node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    return head;
}

struct node* deletenode(struct node* head, int position) {
    if (head == NULL) {
        return head;
    }
    struct node* temp = head;
    struct node* prev = NULL;
    if (position == 1) {
        head = head->next;
        free(temp);
        return head;
    }
    for (int i = 1; temp != NULL && i < position; i++) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        return head;
    }
    prev->next = temp->next;
    free(temp);
    return head;
}

int main() {
    struct node* head = NULL;

    head = insertatbegin(head, 10);
    head = insertatbegin(head, 5);
    printf("After inserting at beginning: ");
    traverselist(head);

    head = insertatend(head, 20);
    head = insertatend(head, 25);
    printf("After inserting at end: ");
    traverselist(head);

    head = insertpos(head, 3, 15);
    printf("After inserting 15 at position 3: ");
    traverselist(head);

    printf("Length of the list: %d\n", findlength(head));

    int searchValue = 15;
    if (searchlist(head, searchValue)) {
        printf("%d found in the list.\n", searchValue);
    } else {
        printf("%d not found in the list.\n", searchValue);
    }

    head = removeofbeginnode(head);
    printf("After deleting from beginning: ");
    traverselist(head);

    head = removeofendnode(head);
    printf("After deleting from end: ");
    traverselist(head);

    head = deletenode(head, 2);
    printf("After deleting node at position 2: ");
    traverselist(head);

    return 0;
}
