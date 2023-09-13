#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *link;
}*head = 0;

void initialiseLinkedList(int sz);
void displayCatalogue();
void display(struct Node *ll);
void rDisplay(struct Node *ll);
void delete(struct Node *ll, int tmp);

//some extra comment

int main() {
  // struct Node *head = 0;
  int sz;
  int op;
  int tmp;
  printf("Hello World!\nEnter the number of nodes you want inside the linked list: ");
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
    case 3:
      printf("Enter the position of the node that you want to delete: ");
      scanf("%d", &tmp);
      delete(head, tmp);
      display(head);
      break;
  }
  // display(head);
}

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
  printf("3: Delete Operation.\n");

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

void delete(struct Node *ll, int pos) {
  struct Node *p = ll, *q = 0;
  if (pos == 0) {
    ll = ll->link;
    free(p);
  }
  else {
    for (int i = 0; i < pos-1 && p; i++) {
      q = p;
      p = p->link;
    }
    if (p) {
      q->link = p->link;
      free(p);
    }
  }
}