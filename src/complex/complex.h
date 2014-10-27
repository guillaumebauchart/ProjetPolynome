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

// Affiche le nombre complexe z
void complexDisplay (Complex z);

// Réalise une somme de nombre Complexs.
Complex complexSum (Complex z1, Complex z2);

// Réalise un produit de nombres Complexs.
Complex complexMultiplication (Complex z1, Complex z2);

// Saisie manuelle d'un nombre complexe.
void getComplexFromKeyBoard (Complex *z);


#endif // COMPLEX_H_INCLUDED