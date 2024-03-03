#include <stdio.h>
#include <stdlib.h>
#define maxsize 5
int isEmpty();
int isFull();
void enqueue();
void dequeue();
void traverse();
int front = -1, rear = -1;
int queue[maxsize];
void main()
{
    int choice;
    printf("Circular Queue Operations\n");
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
    return (front == (rear + 1) % maxsize);
}
int isEmpty()
{
    return (rear == -1);
}
void enqueue()
{
    int item;
    if (isFull())
    {
        printf("Queue is full!\n");
        return;
    }
    else if (isEmpty())
    {
        front = rear = 0;
    }
    else
    {
        rear = (rear + 1) % maxsize;
    }
    printf("Enter the element: ");
    scanf("%d", &item);
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
    else if (front == rear && rear != -1)
    {
        front = rear = -1;
        printf("Queue is empty!\n");
        return;
    }
    else
    {
        item = queue[front];
        printf("%d\n", front);
        printf("Value %d dequeued!\n", item);
        front = (front + 1) % maxsize;
    }
}
void traverse()
{
    int i = front;
    if (isEmpty())
    {
        printf("Empty queue!\n");
    }
    else
    {
        printf("Displaying the elements of circular queue:\n");
        if (rear >= front)
        {
            for (i = front; i <= rear; i++)
            {
                printf("%d ", queue[i]);
            }
        }
        else
        {
            for (i = front; i < maxsize; i++)
            {
                printf("%d ", queue[i]);
            }
            for (i = 0; i <= rear; i++)
            {
                printf("%d ", queue[i]);
            }
        }
    }
}
