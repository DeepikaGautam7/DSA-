#include <stdio.h>
#include <stdlib.h>
#define SIZE 5
int p_queue[SIZE], front, rear;
int isFull();
int isEmpty();
void enqueue(int);
void dequeue(int);
void create();
void check(int);
void traverse();
int main()
{
    int n, sel;
    printf("\n1. Enqueue an element ");
    printf("\n2. Dequeue an element ");
    printf("\n3. Traverse queue elements");
    printf("\n4. Exit");
    create();
    while (1)
    {
        printf("\nEnter your choice : ");
        scanf("%d", &sel);
        switch (sel)
        {
        case 1:
            printf("\nEnter value to be inserted : ");
            scanf("%d", &n);
            enqueue(n);
            break;
        case 2:
            printf("\nEnter value to delete : ");
            scanf("%d", &n);
            dequeue(n);
            break;
        case 3:
            traverse();
            break;
        case 4:
            exit(0);
        default:
            printf("\nChoice is incorrect, Enter a correct choice");
        }
    }
    return 0;
}

/* Function to create an empty priority queue */
void create()
{
    front = 0;
    rear = -1;
}
int isFull()
{
    if (rear == SIZE - 1)
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
/* Function to insert value into priority queue */
void enqueue(int data)
{
    if (isFull())
    {
        printf("\nQueue overflow no more elements can be inserted");
        return;
    }
    if (isEmpty())
    {
        rear++;
        p_queue[rear] = data;
        return;
    }
    else
        check(data);
    rear++;
}

/* Function to check priority and place element */
void check(int data)
{
    int i, j;

    for (i = 0; i <= rear; i++)
    {
        if (data <= p_queue[i])
        {
            for (j = rear + 1; j > i; j--)
            {
                p_queue[j] = p_queue[j - 1];
            }
            p_queue[i] = data;
            return;
        }
    }
    p_queue[i] = data;
}

/* Function to delete an element from queue */
void dequeue(int data)
{
    int i;

    if (isEmpty())
    {
        printf("\nQueue is empty no elements to delete");
        return;
    }

    for (i = 0; i <= rear; i++)
    {
        if (data == p_queue[i])
        {
            for (int j = i; j < rear; j++)
            {
                p_queue[j] = p_queue[j + 1];
            }
            rear--;
            return;
        }
    }
    printf("\n%d not found in queue to delete", data);
}

/* Function to display queue elements */
void traverse()
{
    if (isEmpty())
    {
        printf("\nQueue is empty");
        return;
    }

    for (int i = front; i <= rear; i++)
    {
        printf(" %d ", p_queue[i]);
    }

    front = 0;
}