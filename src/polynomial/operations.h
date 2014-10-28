#ifndef OPERATIONS_H_INCLUDED
#define OPERATIONS_H_INCLUDED

#include "polynomial.h"


// Ajoute un monome à un polynome développé
void addMonomialToPolynomial (Polynomial_dev *polynomial_dev, Monomial *monomial);

// Ajoute deux polynomes entre eux et renvoie le résultat
Polynomial_dev addPolynomials (Polynomial_dev *poly1, Polynomial_dev *poly2);



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


#endif // OPERATIONS_H_INCLUDED
