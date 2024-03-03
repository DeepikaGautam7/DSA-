#include <stdio.h>
int stack[100], choice, n, top, x, i;
int isFull();
int isEmpty();
void push();
void pop();
void traverse();
void search();
int main()
{
    top = -1;
    printf("Enter the size of stack:");
    scanf("%d", &n);
    printf("\nStack operations using array");
    printf("\n1.PUSH\n2.POP\n3.TRAVERSE\n4.SEARCH\n5.EXIT\n");
    do
    {
        printf("\nEnter the Choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            traverse();
            break;
        case 4:
            search();
            break;
        case 5:
            printf("\nEXIT!!!");
            break;
        default:
            printf("Enter a Valid Choice(1/2/3/4/5)\n");
        }
    } while (choice != 5);
    return 0;
}
int isEmpty()
{
    if (top == -1)
        return 1;
    return 0;
}
int isFull()
{
    if (top >= n - 1)
        return 1;
    return 0;
}
void push()
{
    if (isFull())
    {
        printf("stack is over flow.\n");
    }
    else
    {
        printf("Enter a value to be pushed:");
        scanf("%d", &x);
        top++;
        stack[top] = x;
    }
}
void pop()
{
    if (isEmpty())
    {
        printf("stack is under flow.\n");
    }
    else
    {
        printf("The popped elements is %d\n", stack[top]);
        top--;
    }
}
void traverse()
{
    if (!isEmpty())
    {
        printf("The elements in stack \n");
        for (i = top; i >= 0; i--)
            printf("%d\n", stack[i]);
    }
    else
    {
        printf("The stack is empty\n");
    }
}
void search()
{
    if (isEmpty())
    {
        printf("stack is under flow\n");
    }
    else
    {
        int el;
        printf("Enter a value to be searched:");
        scanf("%d", &el);
        for (i = top; i >= 0; i--)
        {
            if (el == stack[i])
            {
                printf("%d is in index %d.\n", el, i);
                return;
            }
        }
        printf("%d Not found in stack!\n", el);
    }
}
