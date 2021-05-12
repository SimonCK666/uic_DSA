// Linked List

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Linked List Implementation

typedef struct node {
    double data;
    struct node* next;
} Node;

// Pointer to the first node

Node* head;

// Implementation

bool IsEmpty(Node* head);
Node* InsertNode(Node** phead, int index, double x);
int FindNode(Node* head, double x);
int DeleteNode(Node** phead, double x);
void DisplayList(Node* head);
void DestroyList(Node* head);

bool IsEmpty(Node* head)
{
    if (head == NULL)
    {
        /* judge the Linked List is empty */
        printf("The Linked List is Empty!!\n");
        return true;
    } else
    {
        /* code */
        printf("The Listked List is not Empty!\n");
        return false;
    }
    
    
}

Node* InsertNode(Node** phead, int index, double x)
{
    if (index < 0)
    {
        /* if the index is not exist */
        return NULL;
    }

    int currIndex = 1;
    Node* currNode = *phead;
    while (currNode != NULL && index > currIndex)
    {
        /* locate the index */
        currIndex = currNode->next;
        currIndex++;
    }
    if (index > 0 && currNode == NULL)
    {
        /* it does not exist */
        return NULL;
    }
    
    // Create a new Node
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = x;

    if (index == 0)
    {
        /* insert at the first place */
        newNode->next = *phead;
        *phead = newNode;
    }else
    {
        /* not at head */
        newNode->next = currNode->next;
        currNode->next = newNode;
    }

    return newNode;
    
    
}

int FindNode(Node* head, double x)
{
    Node* currNode;
    int i;

    currNode->next = head;

    for (i = 1; currNode != NULL; currNode = currNode->next, i++)
    {
        /* judge the value of the index */
        if (currNode->data == x)
        {
            /* code */
            return 0;
            break;
        } else
        {
            /* code */
            continue;
        }
        
        
    }


    currNode->next = NULL;
    // get the position
    return i;
    
    
}

int DeleteNode(Node** phead, double x)
{
    Node* p = *phead;
    Node* q;
    int i;
    for ( i = 1; p != NULL; p = p->next, i++)
    {
        /* locate the node */
        if (p->data == x)
        {
            /* delete the node */
            q->next = p->next;
            free(p);
            break;
        } else
        {
            /* the node does not exist */
            printf("The Deleted index does not EXIST!\n");
            return 0;
        }
        
        
    }
    
    // return the position
    return i;
}

void DisplayList(Node* head)
{
    Node* p;
    // let p point to the first node
    p = head->next;

    for ( ; p != NULL; p = p->next)
    {
        /* step through the list */
        printf("%f\t", p->data);
    }

    printf("\n");
    
}

void DestroyList(Node* head)
{
    Node* p, *q;
    // let p point to the first node
    p = head->next;

    while (p != NULL)
    {
        /* obtain its next node */
        q = p->next;
        // delete p
        free(p);
        p = q;
    }
    
    // head pointer to NULL
    head = NULL;
}

int main(int argc, char const *argv[])
{


    return 0;
}
