#include "utility.h"


// Insert un monome dans un polynome développé vide.
void insertMonomialIntoEmptyPolynomial (Polynomial_dev *polynomial_dev, Monomial *monomial)
{
    if (polynomial_dev != NULL && monomial != NULL)
    {
        // Le monome inséré devient à la fois le premier et le dernier du polynome.
        polynomial_dev->first = monomial;
        polynomial_dev->last = monomial;

        // Il n'a aucun prédécesseur ni successeur.
        monomial->prev = NULL;
        monomial->next = NULL;

        polynomial_dev->lenght++; // On incrémente la longueur du polynome.
    }
}

// Insert un monome au début d'un polynome développé.
void insertMonomialAtBeginningPolynomial (Polynomial_dev *polynomial_dev, Monomial *monomial)
{
    if (polynomial_dev != NULL && monomial != NULL)
    {
        if (polynomial_dev->lenght == 0) // Si le polynome est vide, on utilise la fonction pour inserer un monome dans un polynome vide.
        {
            insertMonomialIntoEmptyPolynomial(polynomial_dev, monomial);
        }
        else
        {
            // Le monome inséré n'a pas de prédécesseur, et son successeur est l'ancien premier monome du polynome
            monomial->prev = NULL;
            monomial->next = polynomial_dev->first;

            polynomial_dev->first->prev = monomial; // Le prédécesseur de l'ancien premier monome devient le monome inséré.
            polynomial_dev->first = monomial; // Le premier monome devient le monome inséré.

            polynomial_dev->lenght++; // On incrémente la longueur du polynome.
        }
    }
}

// Insert un monome à la fin d'un polynome développé.
void insertMonomialAtEndPolynomial (Polynomial_dev *polynomial_dev, Monomial *monomial)
{
    if (polynomial_dev != NULL && monomial != NULL)
    {
        if (polynomial_dev->lenght == 0) // Si le polynome est vide, on utilise la fonction pour inserer un monome dans un polynome vide.
        {
            insertMonomialIntoEmptyPolynomial(polynomial_dev, monomial);
        }
        else
        {
            // Le monome inséré a pour prédécesseur l'ancier dernier monome, et n'a pas de successeur.
            monomial->prev = polynomial_dev->last;
            monomial->next = NULL;

            polynomial_dev->last->next = monomial; // L'ancien dernier monome a pour successeur le monome inséré.
            polynomial_dev->last = monomial; // Le dernier monome devient le monome inséré.

            polynomial_dev->lenght++; // On incrémente la longueur du polynome.
        }
     }
}

// Insert un monome à gauche du monome courant.
void insertMonomialBeforeCurrent (Polynomial_dev *polynomial_dev, Monomial *current, Monomial *toInsert)
{
    if (current == NULL) // Si current pointe vers NULL, on insert le monome à la fin du polynome.
    {
        insertMonomialAtEndPolynomial(polynomial_dev, toInsert);
    }
    else if (current == polynomial_dev->first) // Sinon si le monome courant le premier du polynome, on insert le monome au début du polynome.
    {
        insertMonomialAtBeginningPolynomial(polynomial_dev, toInsert);
    }
    else
    {
        // Le monome inséré a pour prédécésseur l'ancien prédécesseur du monome courant, et pour successeur le monome courant.
        toInsert->prev = current->prev;
        toInsert->next = current;

        current->prev->next = toInsert; // L'ancien prédécesseur du monome courant a pour successeur le monome inséré.
        current->prev = toInsert; // Le monome courant a pour prédécesseur le monome inséré.

        polynomial_dev->lenght++; // On incrémente la longueur du polynome.
    }
}

// Insert un monome à droite du monome courant.
void insertMonomialAfterCurrent (Polynomial_dev *polynomial_dev, Monomial *current, Monomial *toInsert)
{
    if (current == NULL || polynomial_dev->last == current) // Si current pointe vers NULL, ou que c'est le dernier monome du polynome, on l'insert à la fin du polynome.
    {
        insertMonomialAtEndPolynomial(polynomial_dev, toInsert);
    }
    else
    {
        // Le monome inséré a pour prédécesseur le monome courant, et pour successeur le successeur du monome courant.
        toInsert->prev = current;
        toInsert->next = current->next;

        current->next->prev =  toInsert; // L'ancien successeur du monome courant a pour successeur le monome inséré.
        current->next = toInsert; // Le monome courant a pour successeur le monome inséré.

        polynomial_dev->lenght++; // On incrémente la longueur du polynome.
    }
}

/*
 * insertMonomialBetweenTwoMonomials à garder ? Ou inutile ?
 */

// Insert un monome entre deux autres monomes d'un polynome développé.
void insertMonomialBetweenTwoMonomials (Polynomial_dev *polynomial_dev, Monomial *monomialLeft, Monomial *monomialRight, Monomial *monomialInsert)
{
    monomialLeft->next = monomialInsert;
    monomialInsert->prev = monomialLeft;
    monomialInsert->next = monomialRight;
    monomialRight->prev = monomialInsert;

    polynomial_dev->lenght++; // On incrémente la longueur du polynome.
}


// Copie les champs de monomial2 dans monomial1.
void copyMonomial (Monomial *monomial1, Monomial *monomial2)
{
    if (monomial1 != NULL && monomial2 != NULL)
    {
        initMonomial(monomial1, monomial2->exponent, monomial2->coef, NULL, NULL); // On initialise monomial1 avec les valeurs des champs de monomial2.
    }
}

// Copie polynomial2 dans polynomial1.
void copyPolynomial (Polynomial_dev *polynomial1, Polynomial_dev *polynomial2)
{
    // La fonction assume que polynomial1 est toujours vide.
    if (polynomial1 != NULL && polynomial2 != NULL)
    {
        Monomial *current2 = polynomial2->first; // On crée une variable pour parcourir polynomial2.

        while (current2 != NULL) // Tant qu'on n'est pas arrivé à la fin de polynomial2.
        {
            Monomial *toAddPoly1 = createMonomial(); // On crée un monome vide.
            copyMonomial(toAddPoly1, current2); // Il reçoit une copie de current2.
            insertMonomialAtEndPolynomial(polynomial1, toAddPoly1); // On l'ajoute à la fin de polynomial1.
            current2 = current2->next; // On passe au monome suivant.
        }
    }
}


// Renvoie le degré maximum d'un polyome développé.
int getDegreMaxPolynomialDev (Polynomial_dev *polynomial_dev)
{
    if (polynomial_dev != NULL && polynomial_dev->last != NULL) // Si le polynome n'est pas vide, on renvoie le l'exposant du dernier monome.
    {
        return polynomial_dev->last->exponent;
    }
    else // Sinon on retourne 0.
    {
        return 0;
    }
}

// Renvoie le degré minimum d'un polyome développé.
int getDegreMinPolynomialDev (Polynomial_dev *polynomial_dev)
{
    if (polynomial_dev != NULL && polynomial_dev->first != NULL) // Si le polynome n'est pas vide, on renvoie le l'exposant du premier monome.
    {
        return polynomial_dev->first->exponent;
    }
    else // Sinon on retourne 0.
    {
        return 0;
    }
}

// Renvoie le plus grand entre a et b.
int normeSup (int a, int b)
{
    if (a >= b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

// Renvoie le plus petit entre a et b.
int normeInf (int a, int b)
{
    if (a >= b)
    {
        return b;
    }
    else
    {
        return a;
    }
}


// Génère un double aléatoire entre a et b.
double randomInInterval (double a, double b)
{
    /* rand()/RAND_MAX donne un nombre entre 0 et 1.
     * On mutliplie de résultat par l'écart entre les deux bornes.
     * On ajoute la valeur de la première borne.
     * On renvoie le résultat.
     */

    return (rand()/(double)RAND_MAX)*(b-a)+a;
}
