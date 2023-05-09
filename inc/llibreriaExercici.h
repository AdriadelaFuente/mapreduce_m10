#ifndef D8E5564E_A998_46E6_9A70_0B73488F1AF3
#define D8E5564E_A998_46E6_9A70_0B73488F1AF3
//incloure les llibreries que es necessiten
#include <stdbool.h>
    
     #define ubicacioLorem2 "./fitxers/lorem1.txt"
     #define ubicacioFitxer "./fitxers/"
     #define MAXLLETRA 30


typedef struct
{
     int qtt;
     char lletra;
}LLETRA;


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




#endif /* D8E5564E_A998_46E6_9A70_0B73488F1AF3 */
