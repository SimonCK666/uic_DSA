#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "list.h"

// Write all your functions here.

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
        currNode = currNode->next;
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


// Node* InsertNode(Node** phead, int index, double x) {
//     if(index < 0) return NULL;
//     int currIndex = 1;
//     Node* currNode = *phead;
//     while(currNode != NULL && index > currIndex) {
//         currNode = currNode->next;
//         currIndex++;
//     }
//     if(index > 0 && currNode == NULL) return NULL;
//     Node* newNode = (Node*)malloc(sizeof(Node));
//     newNode->data = x;
//     if(index == 0) {
//         newNode->next = *phead;
//         *phead = newNode;
//     }
//     else {
//         newNode->next = currNode->next;
//         currNode->next = newNode;
//     }
//     return newNode;
// }


int FindNode(Node* head, double x)
{
    Node* currNode;
    int i = 0;

    currNode = head;

    // for (i = 1; currNode != NULL; currNode = currNode->next, i++)
    // {
    //     /* judge the value of the index */
    //     if (currNode->data == x)
    //     {
    //         /* code */
    //         return i;
    //         break;
    //     } else
    //     {
    //         /* code */
    //         continue;
    //     }
        
    // }

    
    // currNode->next = NULL;

    // // do not exist
    // return 0;
    int tf = 0;
    while (currNode != NULL)
    {
        /* code */
        i++;
        if (currNode->data == x)
        {
            /* code */
            tf = 1;
            return i;
        } else
        {
            /* code */
            currNode = currNode->next;
        }
        
        
    }

    if (tf == 0)
    {
        /* code */
        return 0;
    }
    
    
    // while (currNode)
    // {
    //     /* code */
    //     if (currNode->data != x)
    //     {
    //         printf("Test: %f\t", currNode->data);
    //         currNode = currNode->next;
    //         i++;
    //     }
    //     else
    //     {
    //         /* code */
    //         break;
    //     }
        
        
    // }
    // printf("\n");

    // if (currNode == NULL)
    // {
    //     /* code */
    //     return 0;
    // }
    
    // // currNode->next = NULL;
    
    // return i;
    
}

int DeleteNode(Node** phead, double x)
{
    // Node* p = *phead;
    // Node* q;
    // int i = 1;
    // for ( i = 1; p != NULL; p = p->next, i++)
    // {
    //     /* locate the node */
    //     if (p->data == x)
    //     {
    //         /* delete the node */
    //         q->next = p->next;
    //         free(p);
    //         break;
    //     } else
    //     {
    //         /* the node does not exist */
    //         printf("The Deleted index does not EXIST!\n");
    //         return 0;
    //     }
        
        
    // }


    Node* currNode = *phead;
    int i;

    if (currNode->next == NULL)
    {
        /* code */
        if (currNode->data == x)
        {
            /* code */
            free(currNode);
            *phead = NULL;
            return 0;
        }
        
    }

    if (currNode->data == x)
    {
        /* code */
        Node *deleteNode = currNode;
        *phead = currNode->next;
        currNode = *phead;
        return 0;
    }

    for ( currNode = *phead, i = 0; currNode->next; currNode = currNode->next)
    {
        /* code */
        if (currNode->next->data == x)
        {
            /* code */
            Node* deleteNode = currNode->next;

            if (deleteNode == *phead)
            {
                /* code */
                *phead = deleteNode->next;
            }

            currNode->next = currNode->next->next;
            free(deleteNode);
            return i;
            
        }
        
    }

    return 0;
    
    
    

}

void DisplayList(Node* head)
{
    Node* p;
    // let p point to the first node
    // p = head->next;
    p = head;

    if (p == NULL)
    {
        /* print the empty line */
        printf("\n");
        printf("Empty Linked List!!\n");
    } else
    {
        for ( ; p != NULL; p = p->next)
        {
            /* step through the list */
            // printf("\nAddr %x: data: %lf, next: %x\n",p, p->data,p->next);
            printf("%lf\t", p->data);

        }
        
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



// Testing all the functions:
int main(void) 
{
    Node* head = NULL;

    // Output: true
    printf("%s\n", IsEmpty(head) ? "true" : "false");

    // Must output an empty line:
    DisplayList(head);

    // Must output "insert failed":
    Node* result = InsertNode(&head, 20, 7);
    printf("%s\n", result == NULL ? "insert failed" : "insert succeeded");

    // Output: 0.000000 1.000000 2.000000 3.000000 4.000000
    for(int i = 0; i < 5; i++) {
        InsertNode(&head, i, i);
    }
    DisplayList(head);

    // Output: false
    printf("%s\n", IsEmpty(head) ? "true" : "false");

    // Output: 4.000000 3.000000 2.000000 1.000000 0.000000 0.000000 1.000000 2.000000 3.000000 4.000000
    for(int i = 0; i < 5; i++) {
        InsertNode(&head, 0, i);
    }
    DisplayList(head);

    // Output: 0.000000 is at position 5
    //         2.000000 is at position 3
    //         4.000000 is at position 1
    //         6.000000 is not in the list

    for(int i = 0; i < 7; i += 2) {
        int idx = FindNode(head, i);
        if(idx > 0) {
            printf("%f is at position %d\n", (double)i, idx);
        } 
        if(idx == 0) {
            printf("%f is not in the list\n", (double)i);
        }
    }

    DisplayList(head);


    // Output: inserted 10.000000
    //         4.000000 3.000000 2.000000 10.000000 1.000000 0.000000 0.000000 1.000000 2.000000 3.000000 4.000000
    Node *in = InsertNode(&head, 3, 10);
    printf("inserted %f\n", in->data);
    DisplayList(head);

    // Output: 4.000000 3.000000 2.000000 10.000000 1.000000 0.000000 1.000000 2.000000 3.000000 4.000000
    //         3.000000 2.000000 10.000000 1.000000 0.000000 1.000000 2.000000 3.000000 4.000000
    //         3.000000 2.000000 10.000000 1.000000 0.000000 1.000000 2.000000 3.000000
    DeleteNode(&head, 0); // Delete in the middle of the list.
    DisplayList(head);
    DeleteNode(&head, 4); // Delete at the front of the list.
    DisplayList(head);
    DeleteNode(&head, 4); // Delete at the end of the list.
    DisplayList(head);

    DestroyList(head);

    return 0;
}