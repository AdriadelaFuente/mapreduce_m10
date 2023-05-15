#ifndef D8E5564E_A998_46E6_9A70_0B73488F1AF3
#define D8E5564E_A998_46E6_9A70_0B73488F1AF3
//incloure les llibreries que es necessiten
#include <stdbool.h>
    
     #define ubicacioLorem1 "./fitxers/lorem1.txt"
     #define ubicacioLorem2 "./fitxers/lorem2.txt"
     #define ubicacioLorem3 "./fitxers/lorem3.txt"
     #define ubicacioAuxiliar "./fitxers/auxiliar.txt"
     #define ubicacioAuxiliar2 "./fitxers/auxiliar2.txt"
     #define ubicacioFinalLletres "./fitxers/resultatLletres.txt"
     #define ubicacioFinalParaules "./fitxers/resultatParaules.txt"
     #define ubicacioFitxer "./fitxers/"
     #define MAXLLETRA 30


typedef struct
{
     int qtt;
     char lletra;
}LLETRA;

typedef struct
{
     char paraula[MAXCADENA];
     int quantitat;
}PARAULES;


enum OPCIOMENU
{
     COMPTALLETRES = 1,
     COMPTAPARAULES,
     SORTIR
};

void pintaMenu();
void quantitatLletres();
void guardaLletraDinsEstructura(LLETRA [], char, int *);
int qttLinies();
void mostraResultatLletres(LLETRA [],int);
void quantitatParaules();
bool caracterDeSaltLinia(char);
void guardaCaracter(char,FILE *);
void fiDeParaula(FILE *);
void copiaFitxerAuxiliar2();
void guardaDadesEstructura();
bool cadenaRepetida(char [],int);
void guardaEnFitxerFinal(PARAULES,FILE *);




#endif /* D8E5564E_A998_46E6_9A70_0B73488F1AF3 */
