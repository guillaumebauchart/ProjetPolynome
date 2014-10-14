#ifndef STRUCT_H_INCLUDED
#define STRUCT_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#include "../complex/complex.h"

// Définie une structure pour un monome, avec exposant, coefficient, pointeur vers monome suivant et précédent.
typedef struct Monomial Monomial;
struct Monomial
{
    int exponent;
    Complex coef;
    Monomial *next, *prev;
};


// Définie une structure pour un polynome développé, avec longueur, degré, pointeur vers le premier et le dernier polynome de la liste, également vers le polynome suivant et précédent dans le cas où il y aurait une liste de molynomes développés (comme dans la forme factorisée par exemple).
typedef struct Polynomial_dev Polynomial_dev;
struct Polynomial_dev
{
    int lenght, deg;
    Monomial *first, *last;
    Polynomial_dev *next, *prev;
};


// Définie une structure pour un polynome factorisé, avec longueur, degré, pointeur vers le premier et le dernier polynome developpé de la liste.
typedef struct Polynomial_fact Polynomial_fact;
struct Polynomial_fact
{
    int lenght, deg;
    Polynomial_dev *first, *last;
};


// Définie une structure pour un polynome avec la longueur, le degré, la forme développée, intégrée, dérivée, factorisée.
typedef struct Polynomial
{
    int lenght, deg;
    Polynomial_dev *developed, *integrated, *derivative;
    Polynomial_fact *factored;
}Polynomial;

// Initialise les champs d'un monome aux valeurs passées en paramètres.
void initMonomial (Monomial *monomial, int exponent, Complex coef, Monomial *next, Monomial *prev);

// Initialise les champs d'un polynome développé aux valeurs passées en paramètres.
void initPolynomialDev (Polynomial_dev *polynomial_dev, int lenght, int deg, Monomial *first, Monomial *last, Polynomial_dev *next, Polynomial_dev *prev);

// Initialise les champs d'un polynome factorisé aux valeurs passées en paramètres.
void initPolynomialFact (Polynomial_fact *polynomial_fact, int lenght, int deg, Polynomial_dev *first, Polynomial_dev *last);

// Initialise les champs d'un polynome aux valeurs passées en paramètres.
void initPolynomial (Polynomial *polynomial, int lenght, int deg, Polynomial_dev *developed, Polynomial_fact *factored);


// Affiche un monome.
void displayMonomial (Monomial monomial);

// Affiche un polynome développé.
void displayPolynomialDev (Polynomial_dev polynomial_dev);

// Affiche un polynome factorisé.
void displayPolynomialFact (Polynomial_fact polynomial_fact);


// Saisie manuelle des valeurs d'un monome.
void getMonomialFromKeyBoard (Monomial *monomial);

// Saisie manuelle des valeurs d'un polynome developpé.
void getPolynomialDevFromKeyBoard (Polynomial_dev *polynomial_dev);



#endif // STRUCT_H_INCLUDED
