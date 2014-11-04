#include "monomial.h"

// Initialise les champs d'un monome aux valeurs passées en paramètres.
void initMonomial (Monomial *monomial, int exponent, Complex coef, Monomial *next, Monomial *prev)
{
    monomial->exponent = exponent;
    monomial->coef = coef;
    monomial->next = next;
    monomial->prev = prev;
}

// Affiche un monome.
void displayMonomial (Monomial *monomial)
{
    complexDisplay(monomial->coef); // On affiche le coef complexe.
    if (monomial->exponent != 0) // Si l'exposant n'est pas nul.
    {
        printf("X^%d", monomial->exponent); // On affiche "X^exposant".
    }
}

// Saisie manuelle des valeurs d'un monome.
void getMonomialFromKeyboard (Monomial *monomial)
{
    int exponent, saisie; // On déclare les variables pour l'exposant et pour la vérification de saisie sécurisée.
    Complex coef; // On déclare le coefficient complexe;

    do
    {
        printf("Choisissez une valeur pour l'exposent : ");
        saisie = scanf("%d", &exponent); // On récupère la saisie.
        fflush(stdin); // On vide la mémoire tampon.
    }while(!saisie); // Tant que l'utilisateur ne rentre pas un entier comme on le lui demande.

    getComplexFromKeyBoard(&coef); // On récupère le coefficient complexe.
    printf("\n");

    initMonomial(monomial, exponent, coef, NULL, NULL); // On initialise le monome aux valeurs récupérées.
}


// Créer un monome, alloue la mémoire, l'initialise à 0, et retourne l'adresse du monome.
Monomial *createMonomial ()
{
    Monomial *monomial = (Monomial*) malloc(sizeof(Monomial)); // On déclare le monome et on alloue la mémoire.
    Complex z; // On déclare le coefficient.

    complexSet(&z, 0, 0); // On initialise le complexe à 0.
    initMonomial(monomial, 0, z, NULL, NULL); // On initialise ses champs à 0.

    return monomial; // On renvoie l'adresse du monome.
}

// Génère un monome aléatoirement et en retourne l'adresse.
Monomial *generateRandomMonomial (int deg)
{
    Monomial *monomial = createMonomial(); // On crée un monome.

    // complexSet(&(monomial->coef), randomInInterval(-5,5), randomInInterval(-5,5)); // On initialise le complexe aléatoirement.
    complexSet(&(monomial->coef), 1+rand()%3, 1+rand()%3); // On initialise le complexe aléatoirement.
    initMonomial(monomial, deg, monomial->coef, NULL, NULL); // On initialise ses champs à 0.

    return monomial; // On renvoie l'adresse du monome.
}



