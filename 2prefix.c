#include <stdio.h>
#include <string.h>
int opStacktop, preStacktop;
char opStack[20], preStack[20];
void PushinPreStack(char a)
{
    preStacktop++;
    preStack[preStacktop] = a;
}
void PushinOpStack(char a)
{
    opStacktop++;
    opStack[opStacktop] = a;
}
char PopOpStack()
{
    char x = opStack[opStacktop];
    opStacktop--;
    return x;
}
int preced(char ch)
{
    if (ch == '^' || ch == '$')
        return 4;
    else if (ch == '/' || ch == '*')
        return 3;
    else if (ch == '+' || ch == '-')
        return 2;
    else
        return 1;
}
int main()
{
    opStacktop = preStacktop = -1;
    char infixch[20];
    int i, j;
    printf("Enter the infix expression: ");
    scanf("%s", &infixch);
    printf("scan char\tprestack\topstack");
    for (i = strlen(infixch); i >= 0; i--)
    {
        printf("\n  %c\t\t", infixch[i]);
        if (infixch[i] == ')')
            PushinOpStack(infixch[i]);
        else if ((infixch[i] >= 'a' && infixch[i] <= 'z') || (infixch[i] >= 'A' && infixch[i] <= 'Z'))
            PushinPreStack(infixch[i]);
        else if (infixch[i] == '+' || infixch[i] == '-' || infixch[i] == '*' || infixch[i] == '/' || infixch[i] == '$' || infixch[i] == '^')
        {
            if (opStacktop != -1)
            {
                while (preced(opStack[opStacktop]) > preced(infixch[i]))
                {
                    PushinPreStack(PopOpStack());
                }
                PushinOpStack(infixch[i]);
            }
            else
                PushinOpStack(infixch[i]);
        }
        else if (infixch[i] == '(')
        {
            while (opStack[opStacktop] != ')')
            {
                PushinPreStack(PopOpStack());
            }
            if (opStack[opStacktop] == ')')
                opStacktop--;
        }
        for (j = 0; j <= preStacktop; j++)
        {
            printf("%c", preStack[j]);
        }
        printf("\t\t");
        for (j = 0; j <= opStacktop; j++)
        {
            printf("%c", opStack[j]);
        }
    }
    while (opStacktop != -1)
    {
        PushinPreStack(PopOpStack());
    }
    printf("\n\nThe prefix expression is: ");
    for (j = preStacktop; j >= 0; j--)
    {
        printf("%c", preStack[j]);
    }
}
