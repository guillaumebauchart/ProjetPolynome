#include "complex.h"


// Affecte les réels x et y au champs x et y du Complex z.
void setComplexNumber (Complex *z, double x, double y)
{
    z->x = x;
    z->y = y;
}

// Affiche le nombre complexe z
void complexDisplay (Complex z)
{
    printf("(%lf + %lfi)", z.x, z.y);
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

// Saisie manuelle d'un nombre complexe.
void getComplexFromKeyBoard (Complex *z)
{
    int saisie;

    do
    {
        printf("Choisissez une valeur pour la partie reelle : ");
        saisie = scanf("%lf", &z->x);
        fflush(stdin); // On vide la mémoire tampon.
    }while(!saisie); // Tant que l'utilisateur ne rentre pas un reel comme on le lui demande.

    do
    {
        printf("Choisissez une valeur pour la partie imaginaire : ");
        saisie = scanf("%lf", &z->y);
        fflush(stdin); // On vide la mémoire tampon.
    }while(!saisie); // Tant que l'utilisateur ne rentre pas un reel comme on le lui demande.
}
