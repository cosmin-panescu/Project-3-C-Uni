#include <stdio.h>
#include <stdlib.h>

// 01.05.2002
int N = 1;

struct Student
{
    char nume[30];
    char prenume[30];
    int note[5];
    struct Student *next, *prev;
};

void inserareFinal(struct Student **list)
{
    int i;

    struct Student *elem = (struct Student *)malloc(sizeof(struct Student));
    printf("Numele studentului: ");
    fgets(elem->nume, sizeof(elem->nume), stdin);
    printf("Prenumele sutdentului: ");
    fgets(elem->prenume, sizeof(elem->prenume), stdin);
    printf("Notele studentului (maxim 5 note): \n");

    for (i = 0; i < 5; i++)
    {
        int nota;
        scanf("%d%*c", &nota);

        if (nota == 0)
        {
            break;
        }
        elem->note[i] = nota;
    }
    printf("\n");

    if (*list == NULL)
    {
        elem->prev = NULL;
        elem->next = NULL;
        *list = elem;
    }
    else
    {
        struct Student *current = *list;
        while (current->next != NULL)
            current = current->next;
        current->next = elem;
        elem->prev = current;
        elem->next = NULL;
    }
}

void afisareStudent(struct Student *elem)
{
    printf("Numele: %s", elem->nume);
    printf("Prenumele: %s", elem->prenume);
    printf("Notele: ");
    int i;
    for (i = 0; i < 5; i++)
    {
        if (elem->note[i] != 0)
            printf("%d ", elem->note[i]);
    }
    printf("\n----------------------------\n");
}

void listaStudenti(struct Student *list)
{
    printf("\nSituatia studentilor: \n");
    printf("----------------------------\n");
    struct Student *current = list;
    while (current != NULL)
    {
        afisareStudent(current);
        current = current->next;
    }
}

double medieStudent(struct Student *elem)
{
    double average;
    int sum = 0, numb = 0, i;

    for (i = 0; i < 5; i++)
    {
        if (elem->note[i] != 0)
        {
            sum += elem->note[i];
            numb++;
        }
    }
    average = (double)sum / numb;

    return average;
}

void medieGrupa(struct Student *list)
{
    double average = 0;
    struct Student *current = list;

    while (current != NULL)
    {
        average += medieStudent(current);
        current = current->next;
    }
    average = average / N;
    printf("Media grupei este: %f\n", average);
}

void situatieStudenti(struct Student *list)
{
    int nepromovat = 0;
    int promovat = 0;
    struct Student *current = list;

    while (current != NULL)
    {
        if (medieStudent(current) >= 5)
        {
            promovat++;
        }
        else
        {
            nepromovat++;
        }
        current = current->next;
    }

    printf("Numar studenti promovati: %d\n", promovat);
    printf("Numar studenti nepromovati: %d\n", nepromovat);
}

int main()
{
    if (N < 10)
    {
        N += 10;
    }

    struct Student *list = NULL;

    for (int i = 0; i < N; i++)
    {
        inserareFinal(&list);
    }

    listaStudenti(list);
    medieGrupa(list);
    situatieStudenti(list);

    return 0;
}
