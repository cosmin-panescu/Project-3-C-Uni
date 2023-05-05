// Scrieti un program care citeste de la tastatura un sir de caractere si il afiseaza in ordine inversa folosind o stiva.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 101

typedef struct Stack
{
    char data[MAX_SIZE];
    int top;
} Stack;

void push(Stack *stack, char c)
{
    if (stack->top < MAX_SIZE - 1)
    {
        stack->top++;
        stack->data[stack->top] = c;
    }
    else
    {
        printf("Nu se poate impinge elementul pe stiva: stiva este plina.\n");
    }
}

char pop(Stack *stack)
{
    if (stack->top >= 0)
    {
        char c = stack->data[stack->top];
        stack->top--;
        return c;
    }
    else
    {
        printf("Nu se poate prelua elementul din stiva: stiva este goala.\n");
        return '\0';
    }
}

int main()
{
    Stack stack;
    stack.top = -1;
    char input[MAX_SIZE];

    printf("Introduceti sirul de caractere dorit: ");
    fgets(input, MAX_SIZE, stdin);

    for (int i = 0; i < strlen(input) - 1; i++)
    {
        push(&stack, input[i]);
    }

    printf("Sirul de caractere inversat este: ");

    while (stack.top >= 0)
    {
        printf("%c", pop(&stack));
    }

    return 0;
}