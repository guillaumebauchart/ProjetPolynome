#include "complex.h"


// Affecte les réels x et y au champs x et y du Complex z.
void complexSet (Complex *z, double x, double y)
{
    z->x = x;
    z->y = y;
}


// Affiche le nombre Complexe z
void complexDisplay (Complex z)
{
    // Selon que les parties réelles et imaginaires soient négatives, nulles ou positives, on adapte l'affichage pour faire au mieux.
    if (z.x == 0 && (z.y < 0 || z.y > 0)) // Si la partie réelle est nulle, et pas la partie imaginaire.
    {
        printf("(%.2lfi)", z.y); // On affiche seulement la partie imaginaire.
    }
    else if (z.x == 0 && z.y == 0){} // Sinon si les parties imaginaires et réelles sont nulles, on n'affiche rien.
    else if ((z.x > 0 || z.x < 0) && z.y < 0) // Sinon si la partie réelle est non nulle et la partie imaginaire est négative.
    {
        printf("(%.2lf - %.2lfi)", z.x, -z.y); // On "décale" le signe moins, et on n'affiche pas le "+" pour rien entre les deux.
    }
    else if ((z.x > 0 || z.x < 0) && z.y == 0) // Sinon si la partie imaginaire est nulle, et pas la partie réelle.
    {
        printf("(%.2lf)", z.x); // On affiche seulement la partie réelle.
    }
    else if ((z.x > 0 || z.x < 0) && z.y > 0) // Sinon si la partie réelle est non nulle, et la partie imaginaire est positive.
    {
        printf("(%.2lf + %.2lfi)", z.x, z.y); // On affiche le complexe normalement.
    }
}


// Réalise une somme de nombre Complexes.
Complex complexSum (Complex z1, Complex z2)
{
    Complex z; // On crée un nombre Complex.
    complexSet(&z, 0, 0); // On l'initialise à 0.

    z.x = z1.x + z2.x; // On additionne les parties réelles.
    z.y = z1.y + z2.y; // On additionne les parties imaginaires.

    return z; // On renvoie le nombre Complex obtenu.
}

// Réalise une somme de nombre Complexes.
Complex complexSubtract (Complex z1, Complex z2)
{
    Complex z; // On crée un nombre Complex.
    complexSet(&z, 0, 0); // On l'initialise à 0.

    z.x = z1.x - z2.x; // On soustrait les parties réelles.
    z.y = z1.y - z2.y; // On soustrait les parties imaginaires.

    return z; // On renvoie le nombre Complex obtenu.
}

// Réalise un produit de nombres Complexes.
Complex complexMultiplication (Complex z1, Complex z2)
{
    Complex z; // On crée un nombre Complex.
    complexSet(&z, 0, 0); // On l'initialise à 0.

    z.x = z1.x * z2.x - z1.y * z2.y; // On regroupe les parties réelles.
    z.y = z1.y * z2.x + z1.x * z2.y; // On regroupe les parties imaginaires.

    return z; // On renvoie le nombre Complex obtenu.
}

// Saisie manuelle d'un nombre Complexe.
void getComplexFromKeyBoard (Complex *z)
{
    int saisie; // On déclare la variable de vérification des saisies sécurisées.

    do
    {
        printf("Choisissez une valeur pour la partie reelle : ");
        saisie = scanf("%lf", &z->x); // On récupère la saisie.
        fflush(stdin); // On vide la mémoire tampon.
    }while(!saisie); // Tant que l'utilisateur ne rentre pas un reel comme on le lui demande.

    do
    {
        printf("Choisissez une valeur pour la partie imaginaire : ");
        saisie = scanf("%lf", &z->y); // On récupère la saisie.
        fflush(stdin); // On vide la mémoire tampon.
    }while(!saisie); // Tant que l'utilisateur ne rentre pas un reel comme on le lui demande.
}
