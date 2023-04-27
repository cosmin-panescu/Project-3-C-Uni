#include <stdio.h>
#include <stdbool.h>
#include <string.h>

struct masina
{
    char nrInmatriculare[10];
    char marca[30];
    char culoare[10];
    int combustibil;
};

bool stop = false;
struct masina lista[100];
int raspuns;

void adaugare_masina()
{
    for (int i = 0; i < 100; i++)
    {
        if (lista[i].nrInmatriculare[0] == '\0')
        {
            printf("Numar inmatriculare: ");
            scanf("%s", lista[i].nrInmatriculare);
            printf("Marca: ");
            scanf("%s", lista[i].marca);
            printf("Culoare: ");
            scanf("%s", lista[i].culoare);

            while (lista[i].combustibil != 1 && lista[i].combustibil != 2)
            {
                printf("Combustibil -> 1(benzina) 2(motorina): ");
                scanf("%d", &lista[i].combustibil);
                printf("\n");
            }
            return;
        }
    }
}

void eliminare_masina()
{
    for (int i = 0; i < 100; i++)
    {
        if (lista[i].nrInmatriculare[0] == '\0')
        {
            if (i == 0)
                return;
            memset(&lista[i - 1].nrInmatriculare, 0, sizeof(lista[i - 1].nrInmatriculare));
            memset(&lista[i - 1].marca, 0, sizeof(lista[i - 1].marca));
            memset(&lista[i - 1].culoare, 0, sizeof(lista[i - 1].culoare));
            lista[i - 1].combustibil = 0;
            return;
        }
    }
}

void listare_masini()
{
    for (int i = 0; i < 100; i++)
    {
        if (lista[i].nrInmatriculare[0] == '\0')
        {
            return;
        }

        printf("%d.%s\n", i + 1, lista[i].nrInmatriculare);
        printf("-> %s\n", lista[i].marca);
        printf("-> %s\n", lista[i].culoare);
        if (lista[i].combustibil == 1)
        {
            printf("-> %s\n", "benzina");
            printf("\n");
        }
        else if (lista[i].combustibil == 2)
        {
            printf("-> %s\n", "motorina");
            printf("\n");
        }
    }
    printf("\n");
}

void listare_masini_benzina()
{
    for (int i = 0; i < 100; i++)
    {
        if (lista[i].nrInmatriculare[0] == '\0')
        {
            return;
        }
        if (lista[i].combustibil == 1)
        {
            printf("%d.%s\n", i + 1, lista[i].nrInmatriculare);
            printf("-> %s\n", lista[i].marca);
            printf("-> %s\n", lista[i].culoare);
            printf("-> %s\n", "benzina");
        }
    }
    printf("\n");
}

void listare_masini_motorina()
{
    for (int i = 0; i < 100; i++)
    {
        if (lista[i].nrInmatriculare[0] == '\0')
        {
            return;
        }
        if (lista[i].combustibil == 2)
        {
            printf("%d.%s\n", i + 1, lista[i].nrInmatriculare);
            printf("-> %s\n", lista[i].marca);
            printf("-> %s\n", lista[i].culoare);
            printf("-> %s\n", "motorina");
        }
    }
    printf("\n");
}

void lungime_coada_masini()
{
    for (int i = 0; i < 100; i++)
    {
        if (lista[i].nrInmatriculare[0] == '\0')
        {
            printf("Lungime coada: %d \n", i);
            return;
        }
    }
    printf("\n");
}

int main()
{
    while (!stop)
    {
        printf("1. Adaugare masina \n");
        printf("2. Eliminare masina \n");
        printf("3. Listare masini \n");
        printf("4. Listare masini pe benzina \n");
        printf("5. Listare masini pe motorina \n");
        printf("6. Lungime coada \n");
        printf("7. Terminare \n\n");
        scanf("%d", &raspuns);

        switch (raspuns)
        {
        case 1:
            adaugare_masina();
            break;
        case 2:
            eliminare_masina();
            break;
        case 3:
            listare_masini();
            break;
        case 4:
            listare_masini_benzina();
            break;
        case 5:
            listare_masini_motorina();
            break;
        case 6:
            lungime_coada_masini();
            break;
        case 7:
            stop = true;
            break;
        }
    }

    return 0;
}
