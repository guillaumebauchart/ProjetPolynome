#include "polynomial.h"


// Initialise les champs d'un polynome développé aux valeurs passées en paramètres.
void initPolynomialDev (Polynomial_dev *polynomial_dev, int lenght, int deg, Monomial *first, Monomial *last, Polynomial_dev *next, Polynomial_dev *prev)
{
	polynomial_dev->lenght = lenght;
	polynomial_dev->deg = deg;
	polynomial_dev->first = first;
	polynomial_dev->last = last;
	polynomial_dev->next = next;
	polynomial_dev->prev = prev;
}

// Initialise les champs d'un polynome factorisé aux valeurs passées en paramètres.
void initPolynomialFact (Polynomial_fact *polynomial_fact, int lenght, int deg, Polynomial_dev *first, Polynomial_dev *last)
{
	polynomial_fact->lenght = lenght;
	polynomial_fact->deg = deg;
	polynomial_fact->first = first;
	polynomial_fact->last = last;
}

// Initialise les champs d'un polynome aux valeurs passées en paramètres
void initPolynomial (Polynomial *polynomial, int lenght, int deg, Polynomial_dev *developed, Polynomial_fact *factored)
{
	polynomial->lenght = lenght;
	polynomial->deg = deg;
	polynomial->developed = developed;
	polynomial->factored = factored;
	polynomial->integrated = NULL;
	polynomial->derivative = NULL;
}


// Affiche un polynome développé
void displayPolynomialDev (Polynomial_dev polynomial_dev)
{
	int i = 0;
	Monomial *tmp = polynomial_dev.first;
	displayMonomial(*tmp);

	for (i = 0; i < polynomial_dev.lenght && tmp != NULL; ++i)
	{
		tmp = tmp->next;
		displayMonomial(*tmp);
        printf("\n");
	}
}

// Affiche un polynome factorisé
void displayPolynomialFact (Polynomial_fact polynomial_fact)
{
	int i = 0;
	Polynomial_dev *tmp = polynomial_fact.first;
	printf("(");
	displayPolynomialDev(*tmp);
	printf(") * ");

	for (i = 0; i < polynomial_fact.lenght && tmp != NULL; ++i)
	{
		tmp = tmp->next;
		printf("(");
		displayPolynomialDev(*tmp);
		printf(") * ");
	}
}


/* DEV DE LA FONCTION EN COURS
// Saisie manuelle des valeurs d'un polynome developpé.
void getPolynomialDevFromKeyBoard (Polynomial_dev *polynomial_dev)
{
	int i = 0, lenght;

	do
    {
        printf("Choisissez une longueur pour le polynome : ");
        saisie = scanf("%d", &lenght);
        fflush(stdin); // On vide la mémoire tampon.
    }while(!saisie); // Tant que l'utilisateur ne rentre pas un reel comme on le lui demande.

	Monomial *tmp = polynomial_dev.first;
	displayMonomial(*tmp);

	for (i = 0; i < polynomial_dev.lenght && tmp != NULL; ++i)
	{
		tmp = tmp->next;
		displayMonomial(*tmp);
	}
}

*/


/* Recherche pour faire une fonction de saisie sécurisée générique, fonction actuellement non-terminée.

void* saisieSecure ()

do
    {
        cout << "Choisissez une valeure pour min : ";
        saisie = scanf("%lf", min);
        fflush(stdin); // On vide la mémoire tampon.
    }while(!saisie); // Tant que l'utilisateur ne rentre pas un reel comme on le lui demande.

*/


// Renvoie le degré d'un polyome développé.
int getDegrePolynomialDev (Polynomial_dev *polynomial_dev)
{
    return polynomial_dev->last->exponent;
}
