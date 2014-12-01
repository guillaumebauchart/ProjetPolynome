#include "complex.h"
#include "../tools/ui.h"


// Affecte les réels x et y au champs x et y du Complex z.
void complexSet (Complex *z, double x, double y)
{
    z->x = x;
    z->y = y;
}


// Affiche le nombre Complexe z
void complexDisplay (Complex *z)
{
    // Selon que les parties réelles et imaginaires soient négatives, nulles ou positives, on adapte l'affichage pour faire au mieux.
    if (z->x == 0 && (z->y < 0 || z->y > 0)) // Si la partie réelle est nulle, et pas la partie imaginaire.
    {
        printf("(%.2lfi)", z->y); // On affiche seulement la partie imaginaire.
    }
    else if (z->x == 0 && z->y == 0){} // Sinon si les parties imaginaires et réelles sont nulles, on n'affiche rien.
    else if ((z->x > 0 || z->x < 0) && z->y < 0) // Sinon si la partie réelle est non nulle et la partie imaginaire est négative.
    {
        printf("(%.2lf - %.2lfi)", z->x, -z->y); // On "décale" le signe moins, et on n'affiche pas le "+" pour rien entre les deux.
    }
    else if ((z->x > 0 || z->x < 0) && z->y == 0) // Sinon si la partie imaginaire est nulle, et pas la partie réelle.
    {
        printf("(%.2lf)", z->x); // On affiche seulement la partie réelle.
    }
    else if ((z->x > 0 || z->x < 0) && z->y > 0) // Sinon si la partie réelle est non nulle, et la partie imaginaire est positive.
    {
        printf("(%.2lf + %.2lfi)", z->x, z->y); // On affiche le complexe normalement.
    }
}


// Réalise une somme de nombre Complexes.
Complex complexSum (Complex *z1, Complex *z2)
{
    Complex z; // On crée un nombre Complex.

    z.x = z1->x + z2->x; // On additionne les parties réelles.
    z.y = z1->y + z2->y; // On additionne les parties imaginaires.

    return z; // On renvoie le nombre Complex obtenu.
}

// Réalise une somme de nombre Complexes.
Complex complexSubtract (Complex *z1, Complex *z2)
{
    Complex z; // On crée un nombre Complex.

    z.x = z1->x - z2->x; // On soustrait les parties réelles.
    z.y = z1->y - z2->y; // On soustrait les parties imaginaires.

    return z; // On renvoie le nombre Complex obtenu.
}

// Réalise un produit de nombres Complexes.
Complex complexMultiply (Complex *z1, Complex *z2)
{
    Complex z; // On crée un nombre Complex.

    z.x = z1->x * z2->x - z1->y * z2->y; // On regroupe les parties réelles.
    z.y = z1->y * z2->x + z1->x * z2->y; // On regroupe les parties imaginaires.

    return z; // On renvoie le nombre Complex obtenu.
}

// Réalise un quotient de nombres Complexes.
Complex complexDivide (Complex *z1, Complex *z2)
{
    Complex z; // On crée un nombre Complex.

    z.x = (z1->x*z2->x + z1->y*z2->y)/(z2->x*z2->x + z2->y*z2->y); // On calcule la partie réelle.
    z.y = (z1->y*z2->x - z1->x*z2->y)/(z2->x*z2->x + z2->y*z2->y); // On calcule la partie imaginaire.

    return z; // On renvoie le nombre Complex obtenu.
}

// Conjugue un nombre complexe.
Complex complexConjugate (Complex *z1)
{
    Complex z; // On crée un nombre Complex.

    z.x = z1->x; // On ne touche pas à la partie réelle.
    z.y = -z1->y; // On récupère l'opposée de la partie imaginaire.

    return z; // On renvoie le nombre Complex obtenu.
}

// Renvoie le complexe z1 élevé à la puissance n avec l'exponentiation rapide.
Complex complexPow (Complex *z1, int n)
{
    Complex z; // On crée un nombre Complex.
    complexSet(&z, z1->x, z1->y); // On en fait une copie de z1.

    if(n == 0) // Si la puissance est nulle.
    {
        complexSet(&z, 1, 0); // On z vaut 1.
        return z; // On venvoie z.
    }

    if(n == 1) // Si la piussance vaut 1.
    {
        return *z1; // On renvoie le nombre intacte.
    }
    else if(n % 2 == 0) // Si la puissance est paire.
    {
        z = complexMultiply(&z, &z); // On met le résultat au carré.
        return complexPow(&z, n/2); // Et on renvoie le résultat à la puissance n/2.
    }
    else // Sinon
    {
        Complex copy = z; // On crée une copie de z.
        z = complexMultiply(&z, &z); // On met z au carré.
        z = complexPow(&z, (n-1)/2); // z vaut z élevé à la puissance (n-1)/2.
        return complexMultiply(&z, &copy); // On renvoie z multiplié par le z de départ.
    }
}

// Saisie manuelle d'un nombre Complexe.
void getComplexFromKeyBoard (Complex *z)
{
    ASK_NUMBER("Choisissez une valeur pour la partie reelle : ", "%lf", &z->x);
    ASK_NUMBER("Choisissez une valeur pour la partie imaginaire : ", "%lf", &z->y);
}
