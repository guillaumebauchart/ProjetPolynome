#ifndef OPERATIONS_H_INCLUDED
#define OPERATIONS_H_INCLUDED

#include "../tools/utility.h"
#include "polynomial.h"


#define KARATSUBA_MULTIPLY(P1, P2);         \
{                                           \
    before = P1;                            \
    P1 = multiplyPolynomials(P1, P2);       \
    removePolynomialDev(before);            \
}

#define KARATSUBA_ADD(P1, P2);              \
{                                           \
    before = P1;                            \
    P1 = addPolynomials(P1, P2);            \
    removePolynomialDev(before);            \
}

#define KARATSUBA_SUBTRACT(P1, P2);         \
{                                           \
    before = P1;                            \
    P1 = subtractPolynomials(P1, P2);       \
    removePolynomialDev(before);            \
}



// Ajoute un monome à un polynome développé et retourne l'adresse du polynome résultat.
Polynomial_dev *addMonomialToPolynomial (Polynomial_dev *polynomial_dev, Monomial *monomial);

// Ajoute deux polynomes entre eux et retourne l'adresse du polynome résultat.
Polynomial_dev *addPolynomials (Polynomial_dev *poly1, Polynomial_dev *poly2);

// Soustrait deux polynomes entre eux et retourne l'adresse du polynome résultat.
Polynomial_dev *subtractPolynomials (Polynomial_dev *poly1, Polynomial_dev *poly2);



// Multiplication d'un polynome développé par un monome, retourne l'adresse du polynome résultat.
Polynomial_dev *multiplyPolynomialByMonomial (Polynomial_dev *polynomial_dev, Monomial *monomial);

// Multiplication d'un polynome développé par un scalaire k.
Polynomial_dev *multiplyPolynomialByScalar (Polynomial_dev *polynomial_dev, Complex *z);

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



// Dérive le polynome développé et retourne l'adresse du polynome résultat.
Polynomial_dev *derivePolynomial (Polynomial_dev *polynomial_dev);

// Intègre le polynome développé et retourne l'adresse du polynome résultat.
Polynomial_dev *integratePolynomial (Polynomial_dev *polynomial_dev);



#endif // OPERATIONS_H_INCLUDED
