#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *link;
}*head = 0;

void initialiseLinkedList(int sz) {
  int tmp;
  struct Node *p, *q = 0;
  head = (struct Node *)malloc(sizeof(struct Node));
  printf("Enter value of node %d: ", 1);
  scanf("%d", &tmp);
  head->data = tmp;
  head->link = 0;
  p = head;
  for (int i = 1; i < sz; i++) {
    q = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter value of node %d: ", i+1);
    scanf("%d", &tmp);
    q->data = tmp;
    q->link = 0;
    p->link = q;
    p = q;
  }
}

void display(struct Node *ll) {
  printf("Printing the linked list nodes: ");
  while (ll != 0) {
    printf("%d ", ll->data);
    ll = ll->link;
  }
  printf("\n");
}

int main() {
  // struct Node *head = 0;
  int sz;
  printf("Enter the number of nodes you want inside the linked list: ");
  scanf("%d", &sz);
  initialiseLinkedList(sz);
  display(head);
}