#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    struct node *prev;
    int data;
    struct node *next;
} node;
node *head = NULL, *tail = NULL;
node *create(int);
void addFromHead(int);
void addFromTail(int);
void adFromKPos(int, int);
void deleteFromHead();
void deleteFromTail();
void deleteFromKPos(int);
int search(int);
int listSize();
void traverse();
int getData();
int getPos();
int main()
{
    int choice, data, pos;
    printf("\n Circular Doubly Linked List Operations:\n");
    printf("\n1. Insert a node at beginning");
    printf("\n2. Insert a node at end");
    printf("\n3. Insert a node at given pos");
    printf("\n4. Delete a node from beginning");
    printf("\n5. Delete a node from end");
    printf("\n6. Delete a node from given pos");
    printf("\n7. Traverse elements of list");
    printf("\n8. Search a node data");
    printf("\n9. Exit");
    while (choice != 9)
    {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nInserting a node from head");
            data = getData();
            addFromHead(data);
            break;
        case 2:
            printf("\nInserting a node from tail");
            data = getData();
            addFromTail(data);
            break;
        case 3:
            printf("\nInserting a node at the given pos");
            data = getData();
            pos = getPos();
            adFromKPos(pos, data);
            break;
        case 4:
            printf("\nDeleting a node from head\n");
            deleteFromHead();
            break;
        case 5:
            printf("\nDeleting a node from tail\n");
            deleteFromTail();
            break;
        case 6:
            printf("\nDelete a node from given pos\n");
            pos = getPos();
            deleteFromKPos(pos);
            break;
        case 7:
            printf("\nDisplaying the node's data of list \n");
            traverse();
            break;
        case 8:
            printf("\nSearching the node data");
            data = getData();
            if (search(data) == 0)
                printf("Node Not Found\n");

            break;
        case 9:
            printf("\nProgram's terminated\n\n");
            return 0;
        default:
            printf("\nInvalid Choice\n");
        }
    }
    return 0;
}
node *create(int data)
{
    node *nnode = (node *)malloc(sizeof(node));
    if (nnode == NULL)
    {
        printf("\nMemory can't be allocated\n");
        return NULL;
    }
    nnode->data = data;
    nnode->next = nnode->prev = NULL;
    return nnode;
}
void addFromHead(int data)
{
    node *nnode = create(data);
    if (nnode)
    {
        if (head == NULL)
        {
            nnode->next = nnode->prev = nnode;
            head = tail = nnode;
            printf("node created from head\n");
            return;
        }
        head->prev->next = nnode;
        nnode->prev = head->prev;
        nnode->next = head;
        head->prev = nnode;
        head = nnode;
        printf("node created from head\n");
    }
}

void addFromTail(int data)
{
    node *nnode = create(data);
    if (nnode)
    {
        if (head == NULL)
        {
            nnode->next = nnode;
            nnode->prev = nnode;
            head = tail = nnode;
            printf("node created from tail\n");
            return;
        }
        head->prev->next = nnode;
        nnode->prev = head->prev;
        nnode->next = head;
        head->prev = nnode;
        tail = nnode;
        printf("node created from tail\n");
    }
}

void adFromKPos(int pos, int data)
{
    if ((pos <= 0) || (head == NULL && pos > 1))
    {
        printf("Invalid pos\n");
    }
    else if (head != NULL && pos > listSize() + 1)
    {
        printf("Invalid pos\n");
    }
    else if (pos == 1)
    {
        addFromHead(data);
    }
    else if (pos == listSize() + 1)
    {
        addFromTail(data);
    }
    else
    {
        node *nnode = create(data);
        if (nnode)
        {
            node *temp = head;
            for (int i = 0; i < pos - 1; i++)
            {
                temp = temp->next;
            }
            nnode->next = temp;
            nnode->prev = temp->prev;
            temp->prev = nnode;
            temp->prev->next = nnode;
            printf("node created\n");
        }
    }
}

void deleteFromHead()
{
    if (head == NULL)
    {
        printf("List is Empty\n");
        return;
    }
    else if (head == tail)
    {
        free(head);
        head = tail = NULL;
        printf("node deleted\n");
        return;
    }
    node *temp = head;
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    head = temp->next;
    free(temp);
    temp = NULL;
    printf("node deleted from head\n");
}
void deleteFromTail()
{
    if (head == NULL)
    {
        printf("List is Empty\n");
        return;
    }
    else if (head == tail)
    {
        free(head);
        head = tail = NULL;
        printf("node deleted\n");
        return;
    }
    node *temp = tail;
    temp->prev->next = head;
    head->prev = temp->prev;
    free(temp);
    temp = NULL;
    printf("node deleted from tail\n");
}
void deleteFromKPos(int pos)
{
    if ((pos <= 0) || (pos > listSize()))
    {
        printf("Invalid pos \n");
    }
    else if (pos == 1)
    {
        deleteFromHead();
    }
    else if (pos == listSize())
    {
        deleteFromTail();
    }
    else
    {
        node *temp = head;
        for (int i = 0; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        temp->next->prev = temp->prev;
        temp->prev->next = temp->next;
        free(temp);
        temp = NULL;
        printf("node deleted\n");
    }
}
void traverse()
{
    if (head == NULL)
    {
        printf("List is empty!\n");
        return;
    }
    node *temp = head;
    do
    {
        printf("%d \n", temp->data);
        temp = temp->next;
    } while (temp != head);
}
int search(int x)
{
    if (head == NULL)
    {
        return 0;
    }
    node *temp = head;
    int count = 0;
    do
    {
        count++;
        if (temp->data == x)
        {
            printf("Element found at node %d. \n", count);
            return 1;
        }
        temp = temp->next;
    } while (temp != head);
    return 0;
}
int listSize()
{
    if (head == NULL)
    {
        return 0;
    }
    node *temp = head;
    int count = 0;
    do
    {
        count++;
        temp = temp->next;
    } while (temp != head);
    return count;
}
int getData()
{
    int data;
    printf("\nEnter Data: ");
    scanf("%d", &data);
    return data;
}
int getPos()
{
    int pos;
    printf("Enter position: ");
    scanf("%d", &pos);
    return pos;
}