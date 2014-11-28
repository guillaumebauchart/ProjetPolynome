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
    complexSet(&z, 0, 0); // On l'initialise à 0.

    z.x = z1->x + z2->x; // On additionne les parties réelles.
    z.y = z1->y + z2->y; // On additionne les parties imaginaires.

    return z; // On renvoie le nombre Complex obtenu.
}

// Réalise une somme de nombre Complexes.
Complex complexSubtract (Complex *z1, Complex *z2)
{
    Complex z; // On crée un nombre Complex.
    complexSet(&z, 0, 0); // On l'initialise à 0.

    z.x = z1->x - z2->x; // On soustrait les parties réelles.
    z.y = z1->y - z2->y; // On soustrait les parties imaginaires.

    return z; // On renvoie le nombre Complex obtenu.
}

// Réalise un produit de nombres Complexes.
Complex complexMultiply (Complex *z1, Complex *z2)
{
    Complex z; // On crée un nombre Complex.
    complexSet(&z, 0, 0); // On l'initialise à 0.

    z.x = z1->x * z2->x - z1->y * z2->y; // On regroupe les parties réelles.
    z.y = z1->y * z2->x + z1->x * z2->y; // On regroupe les parties imaginaires.

    return z; // On renvoie le nombre Complex obtenu.
}

// Réalise un quotient de nombres Complexes.
Complex complexDivide (Complex *z1, Complex *z2)
{
    Complex z;

    z.x = (z1->x*z2->x + z1->y*z2->y)/(z2->x*z2->x + z2->y*z2->y);
    z.y = (z1->y*z2->x - z1->x*z2->y)/(z2->x*z2->x + z2->y*z2->y);

    return z;
}

// Conjugue un nombre complexe.
Complex complexConjugate (Complex *z1)
{
    Complex z;

    z.x = z1->x;
    z.y = -z1->y;

    return z;
}

// Renvoie le complexe z1 élevé à la puissance n.
Complex complexPow (Complex *z1, int n)
{
    Complex z;
    z.x = z1->x;
    z.y = z1->y;

    if(n == 0)
        {
            z.x = 1.;
            z.y = 0.;
            return z;
        }

        if(n == 1)
        {
            return *z1;
        }
        else if(n % 2 == 0)
        {
            z = complexMultiply(&z, &z);
            return complexPow(&z, n/2);
        }
        else
        {
            Complex copy = z;
            z = complexMultiply(&z, &z);
            z = complexPow(&z, (n-1)/2);
            //return Complex_multiply(&z, &copy);
            return complexMultiply(&z, &copy);
        }
}

// Saisie manuelle d'un nombre Complexe.
void getComplexFromKeyBoard (Complex *z)
{
    ASK_NUMBER("Choisissez une valeur pour la partie reelle : ", "%lf", &z->x);
    ASK_NUMBER("Choisissez une valeur pour la partie imaginaire : ", "%lf", &z->y);
}
