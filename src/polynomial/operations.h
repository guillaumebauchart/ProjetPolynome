#ifndef OPERATIONS_H_INCLUDED
#define OPERATIONS_H_INCLUDED

#include "polynomial.h"
#include "../monomial/monomial.h"


// Ajouter un monome à un polynome développé
void addMonomialToPolynomial (Polynomial_dev *polynomial_dev, Monomial *monomial);




// Insert un monome dans un polynome développé vide.
void insertMonomialIntoEmptyPolynomial (Polynomial_dev *polynomial_dev, Monomial *monomial);

// Insert un monome à la fin d'un polynome développé.
void insertMonomialAtEndPolynomial (Polynomial_dev *polynomial_dev, Monomial *monomial);

// Insert un monome entre deux autres monomes d'un polynome développé
void insertMonomialBetweenTwoMonomials (Monomial *monomialInsert, Monomial *monomialLeft, Monomial *monomialRight);


// Copie les champs de monomial2 dans monomial1.
void copyMonomial (Monomial *monomial1, Monomial *monomial2);


#endif // OPERATIONS_H_INCLUDED
