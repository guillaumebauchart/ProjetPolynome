#ifndef OPERATIONS_H_INCLUDED
#define OPERATIONS_H_INCLUDED

#include "../tools/utility.h"
#include "polynomial.h"


// Ajoute un monome à un polynome développé et retourne l'adresse du polynome résultat.
Polynomial_dev *addMonomialToPolynomial (Polynomial_dev *polynomial_dev, Monomial *monomial);

// Ajoute deux polynomes entre eux et retourne l'adresse du polynome résultat.
Polynomial_dev *addPolynomials (Polynomial_dev *poly1, Polynomial_dev *poly2);

// Soustrait deux polynomes entre eux et retourne l'adresse du polynome résultat.
Polynomial_dev *subtractPolynomials (Polynomial_dev *poly1, Polynomial_dev *poly2);



// Multiplication d'un polynome développé par un monome, retourne l'adresse du polynome résultat.
Polynomial_dev *multiplyPolynomialByMonomial (Polynomial_dev *polynomial_dev, Monomial *monomial);

// Multiplication naïve de deux polynomes développé, retourne l'adresse du polynome résultat.
Polynomial_dev *multiplyRawPolynomials (Polynomial_dev *poly1, Polynomial_dev *poly2);


// Multiplie deux polynomes.
Polynomial_dev *multiplyPolynomials (Polynomial_dev *poly1, Polynomial_dev *poly2);

// Découpe un polynome avant et après la puissance n et met les deux parties dans left et right.
void splitAndReducePolynomial (Polynomial_dev *polynomial_dev, Polynomial_dev *left, Polynomial_dev *right, int n);

// Multiplie le polynome par X^n
void increasePolynomial(Polynomial_dev *polynomial_dev, int n);

// Algorightme de Karatsuba
Polynomial_dev *multiplyPolynomialsKaratsuba (Polynomial_dev *A, Polynomial_dev *B);



#endif // OPERATIONS_H_INCLUDED
