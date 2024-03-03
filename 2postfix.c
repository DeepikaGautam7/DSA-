#include <stdio.h>
#include <string.h>
char opStack[20], postStack[20];
int opStacktop, postStacktop;
void PushinPostStack(char);
void PushinOpStack(char);
char PopOpStack();
int precedence(char);
int main()
{
    opStacktop = postStacktop = -1;
    char infixch[20];
    int i, j;
    printf("Enter the infix expression: ");
    scanf("%s", &infixch);
    printf("scan char\tpost stack\topstack");
    for (i = 0; i < strlen(infixch); i++)
    {
        printf("\n  %c\t\t", infixch[i]);
        if (infixch[i] == '(')
            PushinOpStack(infixch[i]);
        else if ((infixch[i] >= 'a' && infixch[i] <= 'z') || (infixch[i] >= 'A' && infixch[i] <= 'Z'))
            PushinPostStack(infixch[i]);
        else if (infixch[i] == '+' || infixch[i] == '-' || infixch[i] == '*' || infixch[i] == '/' || infixch[i] == '$' || infixch[i] == '^')
        {
            if (opStacktop != -1)
            {
                while (precedence(opStack[opStacktop]) >= precedence(infixch[i]))
                {
                    PushinPostStack(PopOpStack());
                }
                PushinOpStack(infixch[i]);
            }
            else
                PushinOpStack(infixch[i]);
        }
        else if (infixch[i] == ')')
        {
            while (opStack[opStacktop] != '(')
                PushinPostStack(PopOpStack());
            if (opStack[opStacktop] == '(')
                opStacktop--;
        }
        for (j = 0; j <= postStacktop; j++)
        {
            printf("%c", postStack[j]);
        }
        printf("\t\t");
        for (j = 0; j <= opStacktop; j++)
        {
            printf("%c", opStack[j]);
        }
    }
    while (opStacktop != -1)
    {
        PushinPostStack(PopOpStack());
    }
    printf("\n\nThe postfix expression is: ");
    for (j = 0; j <= postStacktop; j++)
    {
        printf("%c", postStack[j]);
    }
    return 0;
}
void PushinPostStack(char a)
{
    postStacktop++;
    postStack[postStacktop] = a;
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
int precedence(char ch)
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