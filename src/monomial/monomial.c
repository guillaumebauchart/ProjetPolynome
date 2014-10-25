#include "monomial.h"

// Initialise les champs d'un monome aux valeurs passées en paramètres.
void initMonomial (Monomial *monomial, int exponent, Complex coef, Monomial *next, Monomial *prev)
{
    monomial->exponent = exponent;
    monomial->coef = coef;
    monomial->next = next;
    monomial->prev = prev;
}

// Affiche un monome
void displayMonomial (Monomial monomial)
{
    complexDisplay(monomial.coef);
    printf("X^%d ", monomial.exponent);
}

// Saisie manuelle des valeurs d'un monome.
void getMonomialFromKeyboard (Monomial *monomial)
{
    int exponent, saisie;
    Complex coef;

    do
    {
        printf("Choisissez une valeur pour l'exposent : ");
        saisie = scanf("%d", &exponent);
        fflush(stdin); // On vide la mémoire tampon.
    }while(!saisie); // Tant que l'utilisateur ne rentre pas un reel comme on le lui demande.

    getComplexFromKeyBoard(&coef);
    printf("\n");

    initMonomial(monomial, exponent, coef, NULL, NULL);
}
