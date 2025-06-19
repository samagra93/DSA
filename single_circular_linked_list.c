#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node* next;
};

struct Node* newNode(int data) {
  struct Node* node = (struct Node*)malloc(sizeof(struct Node));
  node->data = data;
  node->next = NULL;
  return node;
}

struct Node* addToEmpty(struct Node* head, int data) {
  struct Node* node = newNode(data);
  node->next = node;
  return node;
}

struct Node* addFront(struct Node* head, int data) {
  if (head == NULL) {
    return addToEmpty(head, data);
  }

  struct Node* node = newNode(data);
  struct Node* temp = head;

  while (temp->next != head) {
    temp = temp->next;
  }

  temp->next = node;
  node->next = head;
  head = node;

  return head;
}

struct Node* addEnd(struct Node* head, int data) {
  if (head == NULL) {
    return addToEmpty(head, data);
  }

  struct Node* node = newNode(data);
  struct Node* temp = head;

  while (temp->next != head) {
    temp = temp->next;
  }

  temp->next = node;
  node->next = head;

  return head;
}

struct Node* addAfter(struct Node* head, int data, int item) {
  if (head == NULL) {
    return NULL;
  }

  struct Node* temp = head;
  int found = 0;

  while (1) {
    if (temp->data == item) {
      struct Node* node = newNode(data);
      node->next = temp->next;
      temp->next = node;
      found = 1;
      break;
    }
    temp = temp->next;
    if (temp == head) {
      break;
    }
  }

  if (!found) {
    printf("Item %d not found\n", item);
  }

  return head;
}

struct Node* deleteFirst(struct Node* head) {
  if (head == NULL) {
    return NULL;
  }

  if (head->next == head) {
    free(head);
    return NULL;
  }

  struct Node* temp = head;
  struct Node* last = head;

  while (last->next != head) {
    last = last->next;
  }

  last->next = head->next;
  head = head->next;
  free(temp);

  return head;
}

struct Node* deleteEnd(struct Node* head) {
  if (head == NULL) {
    return NULL;
  }

  if (head->next == head) {
    free(head);
    return NULL;
  }

  struct Node* prev = NULL;
  struct Node* curr = head;

  while (curr->next != head) {
    prev = curr;
    curr = curr->next;
  }

  prev->next = head;
  free(curr);

  return head;
}

struct Node* deleteAfter(struct Node* head, int item) {
  if (head == NULL) {
    return NULL;
  }

  struct Node* temp = head;
  int found = 0;

  while (1) {
    if (temp->data == item) {
      struct Node* del = temp->next;

      if (del == head) {
        head = head->next;
      }

      if (del == temp) {
        free(del);
        return NULL;
      }

      temp->next = del->next;
      free(del);
      found = 1;
      break;
    }
    temp = temp->next;
    if (temp == head) {
      break;
    }
  }

  if (!found) {
    printf("Item %d not found\n", item);
  }

  return head;
}

void traverse(struct Node* head) {
  if (head == NULL) {
    printf("List is empty\n");
    return;
  }

  struct Node* temp = head;

  while (1) {
    printf("%d ", temp->data);
    temp = temp->next;
    if (temp == head) {
      break;
    }
  }

  printf("\n");
}

int main() {
  struct Node* head = NULL;

  printf("Creating list...\n");

  printf("Adding 6 to empty list\n");
  head = addToEmpty(head, 6);
  traverse(head);

  printf("Adding 8 to end\n");
  head = addEnd(head, 8);
  traverse(head);

  printf("Adding 2 to front\n");
  head = addFront(head, 2);
  traverse(head);

  printf("Adding 10 after 2\n");
  head = addAfter(head, 10, 2);
  traverse(head);

  printf("Adding 20 after 8\n");
  head = addAfter(head, 20, 8);
  traverse(head);

  printf("Trying to add 99 after a non-existent item 100\n");
  head = addAfter(head, 99, 100);
  traverse(head);

  printf("Deleting first node\n");
  head = deleteFirst(head);
  traverse(head);

  printf("Deleting last node\n");
  head = deleteEnd(head);
  traverse(head);

  printf("Deleting node after 6\n");
  head = deleteAfter(head, 6);
  traverse(head);

  printf("Trying to delete node after non-existent item 100\n");
  head = deleteAfter(head, 100);
  traverse(head);

  printf("Deleting all remaining nodes...\n");
  while (head != NULL) {
    head = deleteFirst(head);
    traverse(head);
  }

  printf("Final list is empty.\n");

  return 0;
}

