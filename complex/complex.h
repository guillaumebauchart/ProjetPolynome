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
void setComplexNumber (Complex *z, double x, double y);

// Réalise une somme de nombre Complexs.
Complex complexSum (Complex z1, Complex z2);

// Réalise un produit de nombres Complexs.
Complex complexMultiplication (Complex z1, Complex z2);




#endif // COMPLEX_H_INCLUDED