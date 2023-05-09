#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "rlutil.h"
#include "llibreriaPropia.h"
#include "llibreriaExercici.h"

void pintaMenu()
{
    char opcio[SORTIR][MAXCADENA] = {"Quantitat de Lletres", "Quantitat de Paraules", "Sortir"};

    for (int i = 0; i < SORTIR; i++)
    {
        printf("\n%d - %s", i + 1, opcio[i]);
    }
}

void quantitatLletres()
{
    LLETRA l[MAXLLETRA];
    FILE *f;
    char car;
    int qtt = 0, i = 0;
    if (qttLinies() == 1)
    {
        f = fopen(ubicacioLorem2, "rt");
        car = fgetc(f);
        while (feof(f) == 0)
        {
            car = tolower(car);
            if (car >= 'a' && car <= 'z')
            {
                printf("\n%c", car);
                guardaLletraDinsEstructura(l, car, &qtt);
            }
            car = fgetc(f);
        }
        fclose(f);
    }
    while (i < qtt)
    {
        printf("\nLLETRA: %c QTT: %d", l[i].lletra, l[i].qtt);
        i++;
    }
    
}

void guardaLletraDinsEstructura(LLETRA l[], char car, int *qtt)
{
    int i = 0;

    while (i <= *qtt)
    {
        if (l[i].lletra == car)
        {
            l[i].qtt++;
            break;
        }
        else if (i == *qtt)
        {
            i++;
            l[i].lletra = car;
            l[i].qtt++;
            (*qtt)++;
        }
        i++;
    }
}

int qttLinies()
{
    FILE *f;
    char cadena[900];
    int cont = 0;

    f = fopen(ubicacioLorem2, "rt");

    while (feof(f) == 0)
    {
        fgets(cadena, sizeof(cadena), f);
        cont++;
    }
    fclose(f);

    return cont;
}
