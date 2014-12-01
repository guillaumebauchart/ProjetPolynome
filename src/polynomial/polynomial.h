#ifndef POLYNOMIAL_H_INCLUDED
#define POLYNOMIAL_H_INCLUDED

#include <time.h>

#include "../tools/monomial.h"


// Définie une structure pour un polynome développé, avec longueur, pointeur vers le premier et le dernier polynome de la liste, également vers le polynome suivant et précédent dans le cas où il y aurait une liste de molynomes développés (comme dans la forme factorisée par exemple).
typedef struct Polynomial_dev Polynomial_dev;
struct Polynomial_dev
{
    int lenght;
    Monomial *first, *last;
    Polynomial_dev *next, *prev;
};


// Définie une structure pour un polynome factorisé, avec longueur, pointeur vers le premier et le dernier polynome developpé de la liste.
typedef struct Polynomial_fact Polynomial_fact;
struct Polynomial_fact
{
    int lenght;
    Polynomial_dev *first, *last;
};


// Définie une structure pour un polynome avec la longueur, la forme développée, intégrée, dérivée, factorisée.
typedef struct Polynomial
{
    int lenght;
    Polynomial_dev *developed, *integrated, *derivative;
    Polynomial_fact *factored;
}Polynomial;

// Initialise les champs d'un polynome développé aux valeurs passées en paramètres.
void initPolynomialDev (Polynomial_dev *polynomial_dev, int lenght, Monomial *first, Monomial *last, Polynomial_dev *next, Polynomial_dev *prev);

// Initialise les champs d'un polynome factorisé aux valeurs passées en paramètres.
void initPolynomialFact (Polynomial_fact *polynomial_fact, int lenght, Polynomial_dev *first, Polynomial_dev *last);

// Initialise les champs d'un polynome aux valeurs passées en paramètres.
void initPolynomial (Polynomial *polynomial, int lenght, Polynomial_dev *developed, Polynomial_fact *factored);


// Affiche un polynome développé.
void displayPolynomialDev (Polynomial_dev *polynomial_dev);

// Affiche un polynome factorisé.
void displayPolynomialFact (Polynomial_fact *polynomial_fact);


// Saisie manuelle des valeurs d'un polynome developpé.
// void getPolynomialDevFromKeyBoard (Polynomial_dev *polynomial_dev);



// Créer un polynome, alloue la mémoire, l'initialise à 0, et retourne l'adresse du polynome.
Polynomial_dev *createPolynomialDev ();

// Génère un polynome développé aléatoirement et en retourne l'adresse.
Polynomial_dev *generateRandomPolynomialDev (int minDeg, int maxDeg, double density, double minCoef, double maxCoef);


// Supprime monomial de polynomial_dev et libère la mémoire.
void removeMonomial (Polynomial_dev *polynomial_dev, Monomial *monomial);

// Supprimer un polynome developpé et libère la mémoire.
void removePolynomialDev (Polynomial_dev *polynomial_dev);


#endif // POLYNOMIAL_H_INCLUDED
