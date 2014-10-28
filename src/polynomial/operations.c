#include "operations.h"

// Ajouter un monome à un polynome développé.
void addMonomialToPolynomial (Polynomial_dev *polynomial_dev, Monomial *monomial)
{
    Monomial *copy = (Monomial*) malloc (sizeof(Monomial)); // On alloue un monome.
    copyMonomial(copy, monomial); // On copie le contenu de monomial dedans.

    // Si le polynome est vide.
    if (polynomial_dev->first == NULL)
    {
        insertMonomialIntoEmptyPolynomial(polynomial_dev, copy);
    }
    // Si l'exposant du premier monome est supérieur au monome que l'on veut ajouter, alors il faut l'insérer tout au début.
    else if (polynomial_dev->first->exponent > copy->exponent)
    {
        insertMonomialAtBeginningPolynomial(polynomial_dev, copy);
    }
    // Si l'exposant du dernier monome est inférieur au monome que l'on veut ajouter, alors il faut l'insérer tout à la fin.
    else if (polynomial_dev->last->exponent < copy->exponent)
	{
        insertMonomialAtEndPolynomial(polynomial_dev, copy);
    }
	else
	{
        Monomial *current = polynomial_dev->first; // On crée un variable de parcours, et on la fait pointer vers le premier monome du polynome.

        // Tant qu'on n'est pas arrivé à la fin ET que l'exposant du monome courrant est inférieur à celui du monome à insérer.
        while (current->next != NULL && current->exponent < copy->exponent)
		{
            current = current->next; // On passe au monome suivant.
		}

        // Si les deux exposant sont égaux.
        if (current->exponent == copy->exponent)
		{
            current->coef = complexSum(current->coef, copy->coef); // On ajouter les coefficients entre eux.
        }
		else
		{
            insertMonomialBeforeCurrent(polynomial_dev, current, copy); // On insert le monome avant le monome courant.
		}
    }
}

/*
// Ajoute deux polynomes entre eux et renvoie le résultat
Polynomial_dev addPolynomials (Polynomial_dev *poly1, Polynomial_dev *poly2)
{
    if (poly1 == NULL || poly1->first == NULL)
    {
        return poly2;
    }


    Polynomial_dev *result = (Polynomial_dev*) malloc(sizeof(Polynomial_dev));
    initPolynomialDev(result, 0, NULL, NULL, NULL, NULL);



    copyPolynomial(result, poly1);
    Monomial *current1 = result->first, *current2 = poly2->first;



}
*/

// Ajoute deux polynomes entre eux et renvoie le résultat
Polynomial_dev addPolynomials (Polynomial_dev *poly1, Polynomial_dev *poly2)
{
    Monomial *current1 = poly1->first, *current2 = poly2->first;

    while (current2 != NULL)
    {
        if (current1 != NULL && current1->exponent == current2->exponent)
        {
            current1->coef = complexSum(current1->coef, current2->coef);

            Monomial *toRemove = NULL;
            if (current1->coef.x == 0 && current1->coef.y == 0)
            {
                toRemove = current1;
            }

            current1 = current1->next;
            current2 = current2->next;

            if (toRemove)
            {
                removeMonomial(poly1, toRemove);
            }
        }
        else if (current1 == NULL || current1->exponent > current2->exponent)
        {
            Monomial *copy = (Monomial*) malloc (sizeof(Monomial));
            copyMonomial(copy, current2);
            insertMonomialBeforeCurrent(poly1, current1, copy);
            current2 = current2->next;
        }
        else
        {
            current1 = current1->next;
        }
    }
    return *poly1;
}



// Insert un monome dans un polynome développé vide.
void insertMonomialIntoEmptyPolynomial (Polynomial_dev *polynomial_dev, Monomial *monomial)
{
    polynomial_dev->first = monomial;
    polynomial_dev->last = monomial;
    monomial->prev = NULL;
    monomial->next = NULL;

    polynomial_dev->lenght++;
}

// Insert un monome au début d'un polynome développé.
void insertMonomialAtBeginningPolynomial (Polynomial_dev *polynomial_dev, Monomial *monomial)
{
    if (polynomial_dev->lenght == 0)
    {
        insertMonomialIntoEmptyPolynomial(polynomial_dev, monomial);
    }
    else
    {
        monomial->prev = NULL;
        monomial->next = polynomial_dev->first;
        polynomial_dev->first->prev = monomial;
        polynomial_dev->first = monomial;

        polynomial_dev->lenght++;
    }
}

// Insert un monome à la fin d'un polynome développé.
void insertMonomialAtEndPolynomial (Polynomial_dev *polynomial_dev, Monomial *monomial)
{
    if (polynomial_dev->lenght == 0)
    {
        insertMonomialIntoEmptyPolynomial(polynomial_dev, monomial);
    }
    else
    {
        polynomial_dev->last->next = monomial;
        monomial->prev = polynomial_dev->last;
        monomial->next = NULL;
        polynomial_dev->last = monomial;

        polynomial_dev->lenght++;
    }
}

// Insert un monome à gauche du monome courant.
void insertMonomialBeforeCurrent (Polynomial_dev *polynomial_dev, Monomial *current, Monomial *toInsert)
{
    if (current == NULL)
    {
        insertMonomialAtEndPolynomial(polynomial_dev, toInsert);
    }
    else if (current == polynomial_dev->first)
    {
        insertMonomialAtBeginningPolynomial(polynomial_dev, toInsert);
    }
    else
    {
        toInsert->next = current;
        toInsert->prev = current->prev;
        current->prev->next = toInsert;
        current->prev = toInsert;

        polynomial_dev->lenght++;
    }
}

// Insert un monome à droite du monome courant.
void insertMonomialAfterCurrent (Polynomial_dev *polynomial_dev, Monomial *current, Monomial *toInsert)
{
    if (current == NULL || polynomial_dev->last == current)
    {
        insertMonomialAtEndPolynomial(polynomial_dev, toInsert);
    }
    else
    {
        toInsert->next = current;
        toInsert->prev = current->prev;
        current->prev->next =  toInsert;
        current->prev = toInsert;

        polynomial_dev->lenght++;
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

    polynomial_dev->lenght++;
}

// Copie les champs de monomial2 dans monomial1.
void copyMonomial (Monomial *monomial1, Monomial *monomial2)
{
    initMonomial(monomial1, monomial2->exponent, monomial2->coef, NULL, NULL); // On initialise monomial1 avec les valeurs des chamops de monomial2.
}

// Copie polynomial2 dans polynomial1.
void copyPolynomial (Polynomial_dev *polynomial1, Polynomial_dev *polynomial2)
{
    Monomial *current2 = polynomial2->first; // On crée une variable pour parcourir polynomial2.

    while (current2 != NULL) // Tant qu'on n'est pas arrivé à la fin de polynomial2.
    {
        addMonomialToPolynomial(polynomial1, current2); // On ajoute une copie de current2 dans polynomial1.
        current2 = current2->next; // On passe au monome suivant.
    }
}







