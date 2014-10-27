#include "polynomial.h"
#include "operations.h"


// Initialise les champs d'un polynome développé aux valeurs passées en paramètres.
void initPolynomialDev (Polynomial_dev *polynomial_dev, int lenght, Monomial *first, Monomial *last, Polynomial_dev *next, Polynomial_dev *prev)
{
    polynomial_dev->lenght = lenght;
	polynomial_dev->first = first;
	polynomial_dev->last = last;
	polynomial_dev->next = next;
	polynomial_dev->prev = prev;
}

// Initialise les champs d'un polynome factorisé aux valeurs passées en paramètres.
void initPolynomialFact (Polynomial_fact *polynomial_fact, int lenght, Polynomial_dev *first, Polynomial_dev *last)
{
    polynomial_fact->lenght = lenght;
	polynomial_fact->first = first;
	polynomial_fact->last = last;
}

// Initialise les champs d'un polynome aux valeurs passées en paramètres
void initPolynomial (Polynomial *polynomial, int lenght, Polynomial_dev *developed, Polynomial_fact *factored)
{
    polynomial->lenght = lenght;
	polynomial->developed = developed;
	polynomial->factored = factored;
	polynomial->integrated = NULL;
	polynomial->derivative = NULL;
}


// Affiche un polynome développé
void displayPolynomialDev (Polynomial_dev *polynomial_dev)
{
    Monomial *tmp = polynomial_dev->first;

    //for (i = 0; i < polynomial_dev->lenght && tmp != NULL; ++i)
    while (tmp != NULL)
	{
        displayMonomial(tmp);
        printf(" + \n");
        tmp = tmp->next;
	}
    printf("\n\n");
}

// Affiche un polynome factorisé
void displayPolynomialFact (Polynomial_fact *polynomial_fact)
{
    Polynomial_dev *tmp = polynomial_fact->first;

    //for (i = 0; i < polynomial_fact->lenght && tmp != NULL; ++i)
    while (tmp != NULL)
	{
        printf("(");
        displayPolynomialDev(tmp);
		printf(") * ");
        tmp = tmp->next;
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
int getDegreMaxPolynomialDev (Polynomial_dev *polynomial_dev)
{
    if (polynomial_dev->last != 0)
    {
        return polynomial_dev->last->exponent;
    }
    else
    {
        return 0;
    }
}



// Génère un polynome développé aléatoirement.
Polynomial_dev generatePolynomialDev(int minDeg, int maxDeg, double density)
{
    // Polynomial_dev *polynomial_dev = (Polynomial_dev*) malloc (sizeof(Polynomial_dev));
    Polynomial_dev polynomial_dev;
    initPolynomialDev(&polynomial_dev, 0, NULL, NULL, NULL, NULL);
    int i = 0;
    Complex z;
    srand(time(NULL));

    for (i=minDeg ; i<=maxDeg ; i++)
    {
        complexSet(&z, random(-50,50), random(-50,50));

        double chance = random(0,1);

        if (density > chance)
        {
            Monomial *monomial = (Monomial*) malloc (sizeof(Monomial)); // On alloue un monome.
            initMonomial(monomial, i, z, NULL, NULL);
            addMonomialToPolynomial(&polynomial_dev, monomial);
            free(monomial);
        }
    }
    return polynomial_dev;
}



// Génère un double aléatoire entre a et b.
double random(double a, double b)
{
    return (rand()/(double)RAND_MAX)*(b-a)+a;
}
