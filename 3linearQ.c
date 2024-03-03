#include <stdio.h>
#include <stdlib.h>
#define maxsize 5
int isEmpty();
int isFull();
void enqueue();
void dequeue();
void traverse();
int front = 0, rear = -1;
int queue[maxsize];
void main()
{
    int choice;
    printf("Linear Queue Operations\n");
    printf("1.Enqueue\n2.Dequeue \n3.Display \n4.Exit\n");
    while (choice != 4)
    {
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice)
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
    if (rear < front)
        return 1;
    else
        return 0;
}
void enqueue()
{
    int item;
    if (isFull())
    {
        printf("Queue is full!\n");
        return;
    }
    // if (front == -1 && rear == -1)
    // {
    //     front = 0;
    //     rear = 0;
    // }
    // else
    // {
    printf("Enter the element: ");
    scanf("%d", &item);
    rear++;
    // }
    queue[rear] = item;
    printf("Value %d enqueued!\n", item);
}
void dequeue()
{
    int item;
    if (isEmpty())
    {
        printf("Queue is empty!\n");
        return;
    }
    else
    {
        item = queue[front];
        if (front == rear)
        {
            front = 0;
            rear = -1;
        }
        else
        {
            front++;
        }
        printf("Value %d dequeued!\n", item);
    }
}
void traverse()
{
    int i;
    if (isEmpty())
    {
        printf("Empty queue");
    }
    else
    {
        printf("Displaying the elements of linear queue:\n");
        for (i = front; i <= rear; i++)
        {
            printf("%d\n", queue[i]);
            printf("%d\n", i);
        }
    }
}
