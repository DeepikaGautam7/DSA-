#include<stdio.h>   
#include<stdlib.h>  
#define maxsize 5  
void enqueue();  
void dequeue();  
void traverse();  
int front = -1, rear = -1;  
int queue[maxsize];  
void main ()  
{  
    int choice;   
    while(choice != 4)   
    {     
        printf("\n1.Enqueue\t2.Dequeue \t3.Display \t4.Exit\n");
		printf("Enter choice::");    
        scanf("%d",&choice);  
        switch(choice)  
        {  
            case 1:  
            enqueue();  
            break;  
            case 2:  
            dequeue();  
            break;  
            case 3:  
            traverse();  
            break;  
            case 4:  
            exit(0);  
            break;  
            default:   
            printf("\nEnter valid choice??\n");  
        }  
    }  
}  
int isFull()
{
    if (rear == maxsize - 1)
        return 1;
    else
        return 0;
}
int isEmpty()
{
    if (rear == -1)
        return 1;
    else
        return 0;
}
void enqueue()  
{  
    int item;  
    printf("\nEnter the element: ");  
    scanf("%d",&item);      
    if(isFull())  
    {  
        printf("\nOVERFLOW\n");  
        return;  
    }  
    // making empty queue
    if(front == -1 && rear == -1)  
    {  
        front = 0;  
        rear = 0;  
    }  
    else   
    {  
        rear = rear+1;  
    }  
    queue[rear] = item;  
    printf("\nValue inserted ");  
      
}  
void dequeue()  
{  
    int item;   
    if (front == -1 || front > rear)  
    {  
        printf("\nUNDERFLOW\n");  
        return;  
              
    }  
    else  
    {  
        item = queue[front];  
        if(front == rear)  
        {  
            front = -1;  
            rear = -1 ;  
        }  
        else   
        {  
            front++;  
        }  
        printf("\nvalue deleted ");  
    }  
} 
void traverse()  
{  
    int i;  
    if(isEmpty())  
    {  
        printf("\nEmpty queue\n");  
    }  
    else  
    {   printf("\nprinting values .....\n");  
        for(i=front;i<=rear;i++)  
        {  
            printf("\n%d\n",queue[i]);  
        }     
    }  
}  
