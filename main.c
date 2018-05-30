#include <stdio.h>
#include <ctype.h>

#define SIZE 64

char stack[SIZE];
int top = -1;

void push(char x);
char pop();
int priority(char x);

int main()
{
    char userExpression[SIZE];
    char *e, x;

    printf("Enter an expression: ");
    scanf("%s", userExpression);

    e = userExpression;

    while(*e != '\0')
    {
        if(isalnum(*e))
        {
            printf("%c", *e);
        }
        else if(*e == '(')
        {
            push(*e);
        }
        else if(*e == ')')
        {
            while((x = pop()) != '(')
            {
                printf("%c", x);
            }
        }
        else
        {
            while(priority(stack[top]) >= priority(*e))
            {
                printf("%c",pop());
            }

            push(*e);
        }
        e++;
    }

    while(top != -1)
    {
        printf("%c", pop());
    }
}

void push(char x)
{
    stack[++top] = x;
}

char pop()
{
    if(top == -1)
    {
        return -1;
    }
    else
    {
        return stack[top--];
    }
}

int priority(char x)
{
    if(x == '(')
    {
        return 0;
    }
    else if(x == '+' || x == '-')
    {
        return 1;
    }
    else if(x == '*' || x == '/')
    {
        return 2;
    }
}