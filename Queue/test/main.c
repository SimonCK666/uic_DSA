#include<stdio.h>
#include"q.h" 
int main()  
{  
    QUEUE queue;  
    creat(&queue, 5);  
    //out_queue(&queue);  
    int value;
    for (int x = 0; x < 5; x++)
    {
        /* code */
        in_queue(&queue, x);
    }
    
    print(queue);

    // in_queue(&queue, 2);  
    // print(queue);  
    // in_queue(&queue, 4);  
    // print(queue);  
    // in_queue(&queue, 5);  
    // print(queue);  
    // in_queue(&queue, 6);  
    // print(queue);  
    // in_queue(&queue, 1);  
    // print(queue);  
    // out_queue(&queue);  
    // print(queue);  
    // in_queue(&queue, 9);  
    // print(queue);  
    //out_queue(&queue);  
    //print(queue);  

    out_queue(&queue, &value);
    print(queue);

    in_queue(&queue, 7);  
    print(queue);  
}  