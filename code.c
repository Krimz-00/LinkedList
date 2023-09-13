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

void displayCatalogue() {
  printf("~~List of Operations~~\n");
  printf("0: Display Catalogue Operation.\n");
  printf("1: Iterative Display Operation.\n");
  printf("2: Recursive Display Operation.\n");

}

void display(struct Node *ll) {
  printf("Printing the linked list nodes: ");
  while (ll != 0) {
    printf("%d ", ll->data);
    ll = ll->link;
  }
  printf("\n");
}

void rDisplay(struct Node *ll) {
  static int once = 1, anotherOnce = 1;
  if (once == 1) {
    printf("Printing the linked list nodes (recursively): ");
    once = 2;
  }
  if (ll != 0) {
    printf("%d ", ll->data);
    rDisplay(ll->link);
  }
  if (anotherOnce == 1) {
    printf("\n");
    anotherOnce = 2;
  }
}

int main() {
  // struct Node *head = 0;
  int sz;
  int op;
  printf("Enter the number of nodes you want inside the linked list: ");
  scanf("%d", &sz);
  initialiseLinkedList(sz);
  printf("Browse the list of opeations below.\n");
  displayCatalogue();
  printf("Enter the number of operation you desire from the above list: ");
  scanf("%d", &op);
  switch (op) {
    case 0:
      displayCatalogue();
      break;
    case 1:
      display(head);
      break;
    case 2:
      rDisplay(head);
      break;
  }
  // display(head);
}