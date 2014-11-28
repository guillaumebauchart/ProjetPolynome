#ifndef COMPLEX_H_INCLUDED
#define COMPLEX_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>


// Définie une structure pour nombre Complex, avec partie réelle et partie imaginaire.
typedef struct
{
    double x;
    double y;
}Complex;


// Affecte les réels x et y au champs x et y du Complex z.
void complexSet (Complex *z, double x, double y);

// Affiche le nombre Complexe z
void complexDisplay (Complex *z);

// Réalise une somme de nombre Complexes.
Complex complexSum (Complex *z1, Complex *z2);

// Réalise une somme de nombre Complexes.
Complex complexSubtract (Complex *z1, Complex *z2);

// Réalise un produit de nombres Complexes.
Complex complexMultiply (Complex *z1, Complex *z2);

// Réalise un quotient de nombres Complexes.
Complex complexDivide (Complex *z1, Complex *z2);

// Conjugue un nombre complexe.
Complex complexConjugate (Complex *z1);

// Renvoie le complexe z élevé à la puissance n.
Complex complexPow (Complex *z1, int n);

// Saisie manuelle d'un nombre Complexe.
void getComplexFromKeyBoard (Complex *z);


#endif // COMPLEX_H_INCLUDED
