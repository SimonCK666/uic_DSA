// Linked List Implementation

#include <stdio.h>

typedef struct node
{
    /* data */
    double data;
    struct node *next;
}Node, LinkList;

// a pointer to the first node
Node *head;
