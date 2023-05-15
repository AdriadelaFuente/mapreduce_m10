#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "rlutil.h"
#include "llibreriaPropia.h"
#include "llibreriaExercici.h"

// ******************* COMPTA PARAULES *******************

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
    cls();
    LLETRA l[MAXLLETRA];
    FILE *f;
    char car;
    int qtt = 0, i = 0;
    // if (qttLinies() == 1)
    // {
    f = fopen(ubicacioLorem1, "rt");
    car = fgetc(f);
    while (feof(f) == 0)
    {
        car = tolower(car);
        if (car >= 'a' && car <= 'z')
        {
            guardaLletraDinsEstructura(l, car, &qtt);
        }
        car = fgetc(f);
    }
    fclose(f);
    //}

    mostraResultatLletres(l, qtt);
    printf("\n\nPrem una tecla per a tornar al menu");
}

void guardaLletraDinsEstructura(LLETRA l[], char car, int *qtt)
{
    for (int i = 0; i <= *qtt; i++)
    {
        if (car == l[i].lletra)
        {
            l[i].qtt++;
            break;
        }
        else if (i == *qtt)
        {
            l[i].lletra = car;
            l[i].qtt = 1;
            (*qtt)++;
            i++;
        }
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

void mostraResultatLletres(LLETRA l[], int qtt)
{
    FILE *final = fopen(ubicacioFinalLletres,"wt");
    printf("\nHI HA UN TOTAL DE %d LLETRES\nTOTAL DE VEGADES QUE APAREIX CADA LLETRA");
    for (int i = 0; i < qtt; i++)
    {
        printf("\nLLETRA: %c QTT: %d", l[i].lletra, l[i].qtt);
        fprintf(final,"%c - %d\n", l[i].lletra, l[i].qtt);
    }
    fclose(final);
}

// ******************* COMPTA PARAULES *******************

void quantitatParaules()
{
    char car, carAnt;
    FILE *f = fopen(ubicacioLorem1, "rt");
    FILE *fauxiliar = fopen(ubicacioAuxiliar, "wt");

    car = fgetc(f);
    carAnt = car;
    while (feof(f) == 0)
    {
        if (caracterDeSaltLinia(car)) // Si es , . - ;
        {
            if (!caracterDeSaltLinia(carAnt))
            {
                fiDeParaula(fauxiliar);
            }
        }
        else
        {
            guardaCaracter(car, fauxiliar);
        }
        carAnt = car;
        car = fgetc(f);
    }
    fclose(f);
    fclose(fauxiliar);
    copiaFitxerAuxiliar2();
    guardaDadesEstructura();
}

bool caracterDeSaltLinia(char car)
{
    bool caracterSaltLinia = false;

    if (car == ESPAI)
        caracterSaltLinia = true;
    else if (car == '.')
        caracterSaltLinia = true;
    else if (car == ',')
        caracterSaltLinia = true;
    else if (car == ';')
        caracterSaltLinia = true;
    else if (car == ':')
        caracterSaltLinia = true;
    return caracterSaltLinia;
}

void guardaCaracter(char car, FILE *fauxiliar)
{
    fputc(car, fauxiliar);
}

void fiDeParaula(FILE *fauxiliar)
{
    fputc(SALTLINIA, fauxiliar);
}

void guardaDadesEstructura()
{
    PARAULES p;
    FILE *faux1 = fopen(ubicacioAuxiliar, "rt");
    FILE *faux2;
    FILE *final = fopen(ubicacioFinalParaules,"wt");
    int qtt = 0, pos = 0;
    char cadena[MAXCADENA], cadenaAux[MAXCADENA];

    fgets(cadena, sizeof(cadena), faux1);
    eliminarSaltLinia(cadena, sizeof(cadena));
    while (feof(faux1) == 0)
    {
        if (!cadenaRepetida(cadena, pos))
        {
            faux2 = fopen(ubicacioAuxiliar2, "rt");
            fgets(cadenaAux, sizeof(cadenaAux), faux2);
            eliminarSaltLinia(cadenaAux, sizeof(cadenaAux));
            while (feof(faux2) == 0)
            {
                if (strcmpi(cadena, cadenaAux) == 0)
                {
                    qtt++;
                }
                fgets(cadenaAux, sizeof(cadenaAux), faux2);
                eliminarSaltLinia(cadenaAux, sizeof(cadenaAux));
            }
            fclose(faux2);
            strcpy(p.paraula, cadena);
            p.quantitat = qtt;
            qtt = 0;
            printf("\n%s - %d", p.paraula, p.quantitat);
            guardaEnFitxerFinal(p,final);
        }

        fgets(cadena, sizeof(cadena), faux1);
        eliminarSaltLinia(cadena, sizeof(cadena));
        pos++;
    }
    fclose(faux1);
    fclose(final);

    remove(ubicacioAuxiliar);
    remove(ubicacioAuxiliar2);
}

void copiaFitxerAuxiliar2()
{
    FILE *faux1 = fopen(ubicacioAuxiliar, "rt");
    FILE *faux2 = fopen(ubicacioAuxiliar2, "wt");
    char cadena[MAXCADENA];

    fgets(cadena, sizeof(cadena), faux1);
    while (feof(faux1) == 0)
    {
        printf("\n%s", cadena);
        fprintf(faux2, "%s", cadena);
        fgets(cadena, sizeof(cadena), faux1);
    }
    fclose(faux1);
    fclose(faux2);
}

bool cadenaRepetida(char cadena[], int pos)
{
    FILE *f = fopen(ubicacioAuxiliar2, "rt");
    char cadena2[MAXCADENA];
    int i = 0;
    bool repetit = false;

    while (i < pos)
    {
        fgets(cadena2, sizeof(cadena2), f);
        eliminarSaltLinia(cadena2, sizeof(cadena2));
        if (strcmpi(cadena, cadena2) == 0)
        {
            repetit = true;
        }

        i++;
    }
    fclose(f);

    return repetit;
}

void guardaEnFitxerFinal(PARAULES p, FILE *final)
{
    fprintf(final,"%s - %d\n", p.paraula, p.quantitat);
}