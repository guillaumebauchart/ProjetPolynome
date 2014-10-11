#include <stdio.h>
#include <stdlib.h>


// Définie une structure pour nombre Complex, avec partie réelle et partie imaginaire.
typedef struct
{
    double x ;
    double y;
}Complex;


// Définie une structure pour un monome, avec exposant, coefficient, pointeur vers monome suivant et précédent.
typedef struct Monomial Monomial;
struct Monomial
{
    long exponent;
    double coef;
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
    Polynomial_dev developed, integrated, derivative;
    Polynomial_fact factored;
}Polynomial;


// Affecte les réels x et y au champs x et y du Complex z.
void setComplexNumber (Complex *z, double x, double y);

// Réalise une somme de nombre Complexs.
Complex complexSum (Complex z1, Complex z2);

// Réalise un produit de nombres Complexs.
Complex complexMultiplication (Complex z1, Complex z2);


// Affecte les réels x et y au champs x et y du Complex z.
void setComplexNumber (Complex *z, double x, double y)
{
    z->x = x;
    z->y = y;
}

// Réalise une somme de nombre Complexs.
Complex complexSum (Complex z1, Complex z2)
{
    Complex z; // On créer un nombre Complex.
    setComplexNumber(&z, 0, 0); // On l'initialise à 0.

    z.x = z1.x + z2.x; // On additionne les parties réelles.
    z.y = z1.y + z2.y; // On additionne les parties imaginaires.

    return z; // On renvoie le nombre Complex obtenu.
}

// Réalise un produit de nombres Complexs.
Complex complexMultiplication (Complex z1, Complex z2)
{
    Complex z; // On créer un nombre Complex.
    setComplexNumber(&z, 0, 0); // On l'initialise à 0.

    z.x = z1.x * z2.x - z1.y * z2.y; // On regroupe les parties réelles.
    z.y = z1.y * z2.x + z1.x * z2.y; // On regroupe les parties imaginaires.

    return z; // On renvoie le nombre Complex obtenu.
}


int main()
{
    


    return 0;
}
