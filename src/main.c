#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
#include "rlutil.h"
#include <windows.h>
#include "llibreriaPropia.h"
#include "llibreriaExercici.h"

int main()
{
	SetConsoleCP(1252);
	SetConsoleOutputCP(1252);
	srand(time(NULL));

	enum OPCIOMENU opcio;

	do
	{
		pintaMenu();
		printf("\nIntrodueix quina opcio vols? [1..%d] ",SORTIR);
		opcio=demanaNumeroEntreDosValors(1,SORTIR);
	
		printf("\nL'opcio es %d",opcio);
		switch (opcio)
		{
			case SORTIR: printf("Adeu");break;
			case COMPTALLETRES: quantitatLletres();break;
			case COMPTAPARAULES: quantitatParaules();break;
		}
		getch();
		cls();
	}while (opcio!=SORTIR);

	acabament();
	return 0;
}
