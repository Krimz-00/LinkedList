#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
  int data;
  struct Node *link;
}*head = 0;

void initialiseLinkedList(int sz);
void printCatalogue();
void print(struct Node *ll);
void rPrint(struct Node *ll);
void countNodes(struct Node *ll);
int rCountNodes(struct Node *ll);
void sumNodes(struct Node *ll);
int rSumNodes(struct Node *ll);
void max(struct Node *ll);
void min(struct Node *ll);
void search(struct Node *ll, int x);
void insert(int pos, int x);
void insertLast(struct Node *ll, int x);
bool checkSort(struct Node *ll);
void insertSort(struct Node *ll, int x);
void delete(struct Node *ll, int tmp);


int main() {
  // struct Node *head = 0;
  int sz;
  int op;
  int tmp;
  int pos;
  int x;
  printf("Enter the number of nodes you want inside the linked list: ");
  scanf("%d", &sz);
  initialiseLinkedList(sz);
  printf("Browse the list of opeations below.\n");
  printCatalogue();
  printf("Enter the number of operation you desire from the above list: ");
  scanf("%d", &op);
  switch (op) {
    case 0:
      printCatalogue();
      break;
    case 1:
      print(head);
      break;
    case 2:
      rPrint(head);
      break;
    // case 3:
    //   printf("Enter the position of the node that you want to delete: ");
    //   scanf("%d", &tmp);
    //   delete(head, tmp);
    //   print(head);
    //   break;
    case 3:
      countNodes(head);
      break;
    case 4:
      printf("The number of nodes recursively is: %d\n", rCountNodes(head));
      break;
    case 5:
      sumNodes(head);
      break;
    case 6:
      printf("The sum of nodes recursively is: %d\n", rSumNodes(head));
      break;
    case 7:
      max(head);
      print(head);
      break;
    case 8:
      min(head);
      sumNodes(head);
      break;
    case 9:
      printf("Enter the number you are looking for: ");
      scanf("%d", &tmp);
      search(head, tmp);
      print(head);
      break;
    case 10:
      printf("Enter the position you want to add the node to (starting from 0): ");
      scanf("%d", &pos);
      printf("Enter the number you want to add to the linked list: ");
      scanf("%d", &x);
      insert(pos, x);
      // print(head);
    
  }
  // print(head);
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

void printCatalogue() {
  printf("~~List of Operations~~\n");
  printf("0: print Catalogue Operation.\n");
  printf("1: Iterative print Operation.\n");
  printf("2: Recursive print Operation.\n");
  printf("3: Count Nodes Operation.\n");
  printf("4: Recursive Count Nodes Operation.\n");
  printf("5: Sum Nodes Operation.\n");
  printf("6: Recursive Sum Nodes Operation.\n");
  printf("7: Find Max Operation.\n");
  printf("8: Find Min Operation.\n");
  printf("9: Search Operation.\n");
  printf("10: Insert Operation.\n");


  // printf("3: Delete Operation.\n");

}

void print(struct Node *ll) {
  printf("Printing the linked list nodes: ");
  while (ll != 0) {
    printf("%d ", ll->data);
    ll = ll->link;
  }
  printf("\n");
}

void rPrint(struct Node *ll) {
  static int once = 1, anotherOnce = 1;
  if (once == 1) {
    printf("Printing the linked list nodes (recursively): ");
    once = 2;
  }
  if (ll != 0) {
    printf("%d ", ll->data);
    rPrint(ll->link);
  }
  if (anotherOnce == 1) {
    printf("\n");
    anotherOnce = 2;
  }
}

void countNodes(struct Node *ll) {
  int count = 0;
  struct Node *p = ll;
  while (p != 0) {
    count++;
    p = p->link;
  }
  printf("The number of nodes present in the linked list is: %d\n", count);
}

int rCountNodes(struct Node *ll) {
  if (ll == 0)
    return 0;
  else
    return rCountNodes(ll->link) + 1;
}

void sumNodes(struct Node *ll) {
  struct Node *p = ll;
  int sum = 0;
  while (p != 0) {
    sum += p->data;
    p = p->link;
  }
  printf("The sum of the nodes is: %d\n", sum);
}

int rSumNodes(struct Node *ll) {
  if (ll == 0)
    return 0;
  else
    return rSumNodes(ll->link) + ll->data;
}

void max(struct Node *p) {
  int mx = p->data;
  while (p != 0) {
    if (mx < p->data)
      mx = p->data;
    p = p->link;
  }
  printf("The maximum number from the linked list is: %d\n", mx);
}

void min(struct Node *p) {
  int mn = p->data;
  while (p != 0) {
    if (p->data < mn)
      mn = p->data;
    p = p->link;
  }
  printf("The minimum number from the linked list is: %d\n", mn);
}

void search(struct Node *p, int x) {
  while (p != 0) {
    if (p->data == x) {
      printf("Found!\n");
      return;
    }
    p = p->link;
  }
  printf("The number is not found anywhere!\n");
}

void insert(int pos, int x) {
  if (pos < 0 || pos > rCountNodes(head)) {
    printf("Position is out-of-bounds! try a different position.\n");
    return;
  }
  struct Node *p = head, *node = 0, *q = 0;
  node = (struct Node *)malloc(sizeof(struct Node));
  node->data = x;
  node->link = 0;
  if (pos == 0) {
    node->link = head;
    head = node;
  }
  else {
    for (int i = 1; i < pos+1 && p; i++) {
      q = p;
      p = p->link;
    }
    node->link = p;
    q->link = node;
  }
}

void delete(struct Node *ll, int pos) {
  struct Node *p = head, *q = 0;
  if (pos == 1) {
    head = head->link;
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
