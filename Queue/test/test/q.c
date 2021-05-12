//队列的C语言实现（循环数组结构） 
#include <stdio.h>
#include <stdlib.h>
 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
 
typedef int ElementType;
 
//队列结构 
typedef struct _QUEUE_ARRAY_{
	int front;
	int rear;
	int maxSize;
	int capacity;
	ElementType *array;	
}QUEUE_ARRAY; 
 
//创建队列并初始化 
void Create( QUEUE_ARRAY *queue ,int max){
	queue->array=(ElementType*)malloc(sizeof(ElementType)*max);
	if(queue->array==NULL){
		printf("内存出错！");
		exit(-1);
	}
	else{
		queue->front=0;
		queue->rear=0;
		queue->maxSize=max;
		queue->capacity=0;
		// return queue;
	}	
}
 
//入队 
void Enqueue(QUEUE_ARRAY *queue,ElementType data){
	if(queue->capacity==queue->maxSize){
		printf("队列已满！\n");
		exit(-1);
	}
	else{
		if(queue->capacity==0){
			queue->array[queue->rear]=data;
		}
		else{
			queue->rear=(++queue->rear)%queue->maxSize;
			queue->array[queue->rear]=data;
		}
		queue->capacity++;
	}
} 
 
//出队 
void Dequeue(QUEUE_ARRAY *queue,ElementType *data){
	if(queue->capacity==0){
		printf("队列为空！\n");
		exit(-1);
	}
	else{
		*data=queue->array[queue->front];
		queue->front=(++queue->front)%queue->maxSize;
		queue->capacity--;
	}
}
 
//打印队列 
void Printf(QUEUE_ARRAY *queue){
	if(queue->capacity == 0){
		printf("队列为空！\n");
		exit(0);
	}
	else{
		printf("the capacity of queue is : %d \n",queue->capacity);
		do{
			printf(" %d ",queue->array[queue->front]);
			queue->front++;
		} while(--queue->capacity);
        printf("\n");
	}
}
 
int main()  
{  
    QUEUE_ARRAY queue;  
    Create(&queue, 5);  
    // out_queue(&queue);  
    int value;
    for (int x = 0; x < 5; x++)
    {
        /* code */
        Enqueue(&queue, x);
    }
    
    Printf(&queue);

    Dequeue(&queue, &value);
    Printf(&queue);

    Enqueue(&queue, 7);  
    Printf(&queue);  
}  