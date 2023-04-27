#include <stdio.h>
#include <stdlib.h>

// 01.05.2002
int N = 1;
int M = 5;

struct Node
{
    double data;
    struct Node *prev;
    struct Node *next;
};

// Functie care insereaza un nod la sfarsitul unei liste
void inserareFinal(struct Node **head_ref, double new_data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    struct Node *last = *head_ref;

    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL)
    {
        new_node->prev = NULL;
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL)
    {
        last = last->next;
    }

    last->next = new_node;
    new_node->prev = last;

    return;
}

// Functie care concateneaza doua liste dublu inlantuite
void concatenare(struct Node **head1_ref, struct Node **head2_ref)
{
    struct Node *last = *head1_ref;

    while (last->next != NULL)
    {
        last = last->next;
    }

    last->next = *head2_ref;
    (*head2_ref)->prev = last;
}

// Functie care afseaza continutul unei liste
void printLista(struct Node *node)
{
    while (node != NULL)
    {
        printf("%f ", node->data);
        node = node->next;
    }
    printf("\n");
}

// Functie care gaseste cel mai mic si cel mai mare numar din lista
void gasireMinMax(struct Node *node, double *min, double *max)
{
    *min = node->data;
    *max = node->data;
    while (node != NULL)
    {
        if (node->data < *min)
        {
            *min = node->data;
        }
        if (node->data > *max)
        {
            *max = node->data;
        }
        node = node->next;
    }
}

int main()
{
    if (N < 4)
    {
        N *= 3;
    }

    if (M < 4)
    {
        M *= 3;
    }

    // Realizam doua liste dublu inlantuite
    struct Node *head1 = NULL;
    struct Node *head2 = NULL;

    for (int i = 0; i < N; i++)
    {
        inserareFinal(&head1, i + 1);
    }

    for (int i = 0; i < M; i++)
    {
        inserareFinal(&head2, i + 1);
    }

    // Concatenare cele două liste
    concatenare(&head1, &head2);

    // Afisare continut lista
    printf("Lista concatenata este: ");
    printLista(head1);

    // Returnarea celui mai mic și celui mai mare element din lista
    double min, max;
    gasireMinMax(head1, &min, &max);

    printf("Cel mai mic element din lista este  %f\n", min);
    printf("Cel mai mare element din lista este  %f\n", max);

    return 0;
}