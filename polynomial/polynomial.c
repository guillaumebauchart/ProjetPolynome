#include "polynomial.h"


// Initialise les champs d'un monome aux valeurs passées en paramètres.
void initMonomial (Monomial *monomial, int exponent, Complex coef, Monomial *next, Monomial *prev)
{
	monomial->exponent = exponent;
	monomial->coef = coef;
	monomial->next = next;
	monomial->prev = prev;
}

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

// Affiche un monome
void displayMonomial (Monomial monomial)
{
	complexDisplay(monomial.coef);
	printf("X^%d ", monomial.exponent);
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

// Saisie manuelle des valeurs d'un monome.
void getMonomialFromKeyBoard (Monomial *monomial)
{
	int exponent, saisie;
	Complex coef;

	do
    {
        printf("Choisissez une valeur pour l'exposent : ");
        saisie = scanf("%d", &exponent);
        fflush(stdin); // On vide la mémoire tampon.
    }while(!saisie); // Tant que l'utilisateur ne rentre pas un reel comme on le lui demande.

    getComplexFromKeyBoard (&coef);

    initMonomial(monomial, exponent, coef, NULL, NULL);
}

/* DEV DE LA FONCTION EN COURS
// Saisie manuelle des valeurs d'un polynome developpé.
void getPolynomialDevFromKeyBoard (Polynomial_dev *polynomial_dev)
{
	int i = 0;
	long lenght;

	do
    {
        printf("Choisissez une longueur pour le polynome : ");
        saisie = scanf("%ld", &lenght);
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
