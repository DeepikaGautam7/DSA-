#include <stdio.h>
void towers(int, char, char, char);
int main()
{
    int n;
    printf("Enter the number of disks : ");
    scanf("%d", &n);
    printf("The sequence of moves involved in the Tower of Hanoi are :\n");
    towers(n, 'S', 'A', 'D');
    return 0;
}
void towers(int n, char S, char A, char D)
{
    // Base Condition if no of disks are
    if (n < 0)
        printf("Invalid entry!");
    else if (n == 1)
        printf("Move disk 1 from %c to %c\n", S, D);
    // Recursively calling function twice
    else
    {
        towers(n - 1, S, D, A);
        printf("Move disk %d from %c to %c\n", n, S, D);
        towers(n - 1, A, S, D);
    }
}