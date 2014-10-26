#include "operations.h"

// Ajouter un monome à un polynome développé.
void addMonomialToPolynomial (Polynomial_dev *polynomial_dev, Monomial *monomial)
{
    Monomial *copy = (Monomial*) malloc (sizeof(Monomial)); // On alloue un monome.
    copyMonomial(copy, *monomial); // On copie le contenu de monomial dedans.

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
        Monomial *current = (Monomial*) malloc (sizeof(Monomial)); // On alloue une variable monomial de parcours.
        current = polynomial_dev->first; // On la fait pointer vers le premier monome du polynome.

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
        // Sinon
		else
		{
            insertMonomialBetweenTwoMonomials(copy, current->prev, current); // On insert le monome entre le monome courant et celui qui le précède.
            // On met à jour la longueur et le degré du polynome.
            polynomial_dev->lenght++;
            polynomial_dev->deg = getDegrePolynomialDev(*polynomial_dev);
		}

        free(current); // On libère la variable de parcours.
	}
}




// Insert un monome dans un polynome développé vide.
void insertMonomialIntoEmptyPolynomial (Polynomial_dev *polynomial_dev, Monomial *monomial)
{
    polynomial_dev->first = monomial;
    polynomial_dev->last = monomial;
    polynomial_dev->deg = monomial->exponent;
    polynomial_dev->lenght++;
    polynomial_dev->deg = getDegrePolynomialDev(*polynomial_dev);
}

// Insert un monome au début d'un polynome développé.
void insertMonomialAtBeginningPolynomial (Polynomial_dev *polynomial_dev, Monomial *monomial)
{
    monomial->prev = NULL;
    monomial->next = polynomial_dev->first;
    polynomial_dev->first->prev = monomial;
    polynomial_dev->first = monomial;
    polynomial_dev->lenght++;
    polynomial_dev->deg = getDegrePolynomialDev(*polynomial_dev);
}


// Insert un monome à la fin d'un polynome développé.
void insertMonomialAtEndPolynomial (Polynomial_dev *polynomial_dev, Monomial *monomial)
{
    polynomial_dev->last->next = monomial;
    monomial->prev = polynomial_dev->last;
    monomial->next = NULL;
    polynomial_dev->last = monomial;
    polynomial_dev->lenght++;
    polynomial_dev->deg = getDegrePolynomialDev(*polynomial_dev);
}

// Insert un monome entre deux autres monomes d'un polynome développé.
void insertMonomialBetweenTwoMonomials (Monomial *monomialInsert, Monomial *monomialLeft, Monomial *monomialRight)
{
	monomialLeft->next = monomialInsert;
	monomialInsert->prev = monomialLeft;
	monomialInsert->next = monomialRight;
    monomialRight->prev = monomialInsert;
}


// Copie les champs de monomial2 dans monomial1.
void copyMonomial (Monomial *monomial1, Monomial monomial2)
{
    initMonomial(monomial1, monomial2.exponent, monomial2.coef, monomial2.next, monomial2.prev);
}
