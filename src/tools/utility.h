#ifndef UTILITY_H_INCLUDED
#define UTILITY_H_INCLUDED

#include "../polynomial/polynomial.h"
#include "monomial.h"


// Insert un monome dans un polynome développé vide.
void insertMonomialIntoEmptyPolynomial (Polynomial_dev *polynomial_dev, Monomial *monomial);

// Insert un monome au début d'un polynome développé.
void insertMonomialAtBeginningPolynomial (Polynomial_dev *polynomial_dev, Monomial *monomial);

// Insert un monome à la fin d'un polynome développé.
void insertMonomialAtEndPolynomial (Polynomial_dev *polynomial_dev, Monomial *monomial);

// Insert un monome à gauche du monome courant.
void insertMonomialBeforeCurrent (Polynomial_dev *polynomial_dev, Monomial *current, Monomial *toInsert);

// Insert un monome à droite du monome courant.
void insertMonomialAfterCurrent (Polynomial_dev *polynomial_dev, Monomial *current, Monomial *toInsert);

// Insert un monome entre deux autres monomes d'un polynome développé.
void insertMonomialBetweenTwoMonomials (Polynomial_dev *polynomial_dev, Monomial *monomialLeft, Monomial *monomialRight, Monomial *monomialInsert);



// Copie les champs de monomial2 dans monomial1.
void copyMonomial (Monomial *monomial1, Monomial *monomial2);

// Copie polynomial2 dans polynomial1.
void copyPolynomial (Polynomial_dev *polynomial1, Polynomial_dev *polynomial2);



// Renvoie le degré maximum d'un polyome développé.
int getDegreMaxPolynomialDev (Polynomial_dev *polynomial_dev);

// Renvoie le degré minimum d'un polyome développé.
int getDegreMinPolynomialDev (Polynomial_dev *polynomial_dev);

// Renvoie le plus grand entre a et b.
int normeSup (int a, int b);

// Renvoie le plus petit entre a et b.
int normeInf (int a, int b);

// Génère un double aléatoire entre a et b.
double randomInInterval (double a, double b);


#endif // UTILITY_H_INCLUDED
