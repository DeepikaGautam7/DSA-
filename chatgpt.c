#include <stdio.h>
#include <stdlib.h>
#define mSize 5
int cqueue[mSize];
int front = -1, rear = -1;
void enqueue()
{
    if ((front == 0 && rear == mSize - 1) || (rear == front - 1))
    {
        printf("Queue is full\n");
        return;
    }
    int value;
    printf("Enter the element: ");
    scanf("%d", &value);
    if (front == -1)
    {
        front = rear = 0;
    }
    else
    {
        rear = (rear + 1) % mSize;
    }
    cqueue[rear] = value;
    printf("%d enqueued to cqueue\n", value);
}

void dequeue()
{
    if (front == -1)
    {
        printf("Queue is empty\n");
        return;
    }
    int value = cqueue[front];
    if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front = (front + 1) % mSize;
    }
    printf("%d dequeued to cqueue\n", value);
    printf("font =  %d \n", front);
}

void traverse()
{
    if (front == -1)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Elements in circular cqueue are: ");
    printf("rear =  %d \n", rear);
    printf("font =  %d \n", front);
    if (rear >= front)
    {
        for (int i = front; i <= rear; i++)
        {
            printf("%d ", cqueue[i]);
        }
    }
    else
    {
        printf("lah hai\n");
        for (int i = front; i < mSize; i++)
        {
            printf("%d ", cqueue[i]);
        }
        for (int i = 0; i <= rear; i++)
        {
            printf("%d ", cqueue[i]);
        }
    }
    printf("\n");
}

int main()
{
    int choice;
    printf("Circular cQueue Operations\n");
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
