// methods

#include <stdio.h>

typedef struct node
{
    /* data */
    double data;
    struct node *next;
}Node, LinkList;

// a pointer to the first node
Node *head;

int IsEmpty(Node *head);
Node* InsertNode(Node** phead, int index, double x);
int FindNode(Node *head, double x);
int DeleteNode(Node** phead, double x);
void DisplayList(Node* head);
void DestroyList(Node* head);

