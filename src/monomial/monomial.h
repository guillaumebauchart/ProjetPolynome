#ifndef MONOMIAL_H_INCLUDED
#define MONOMIAL_H_INCLUDED

#include "../complex/complex.h"

// Définie une structure pour un monome, avec exposant, coefficient, pointeur vers monome suivant et précédent.
typedef struct Monomial Monomial;
struct Monomial
{
    int exponent;
    Complex coef;
    Monomial *next, *prev;
};


// Initialise les champs d'un monome aux valeurs passées en paramètres.
void initMonomial (Monomial *monomial, int exponent, Complex coef, Monomial *next, Monomial *prev);

// Affiche un monome.
void displayMonomial (Monomial *monomial);

// Saisie manuelle des valeurs d'un monome.
void getMonomialFromKeyboard (Monomial *monomial);


#endif // MONOMIAL_H_INCLUDED
