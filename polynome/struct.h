#ifndef STRUCT_H_INCLUDED
#define STRUCT_H_INCLUDED


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
    Polynomial_dev *developed, *integrated, *derivative;
    Polynomial_fact *factored;
}Polynomial;


#endif // STRUCT_H_INCLUDED