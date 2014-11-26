#include "ui.h"


void launch ()
{
	int choix, saisie;
	display_menu();
	srand(time(NULL));
	
	do
    {
        printf("Votre choix : ");
        saisie = scanf("%d", &choix); // On récupère la saisie.
        fflush(stdin); // On vide la mémoire tampon.
    }while(!saisie); // Tant que l'utilisateur ne rentre pas un entier comme on le lui demande.

    

}


void display_menu ()
{
	printf("#=#=#=#=#=#=#=#=#=#=#=#=#=#\n");
	printf("|        Polynomes        |\n");
	printf("=#=#=#=#=#=#=#=#=#=#=#=#=#=\n");

	printf("Le programme propose de faire différentes opérations sur les polynomes. Les voici :\n");

	printf("1) Générer aléatoirement des polynomes.\n");
	printf("2) Addition deux polynomes.\n");
	printf("3) Soustraire deux polynomes.\n");
	printf("4) Multiplier naïvement deux polynomes.\n");
	printf("5) Multiplier deux polynomes.\n");
}