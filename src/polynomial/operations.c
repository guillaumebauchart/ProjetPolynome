#include "operations.h"

// Ajouter un monome à un polynome développé.
void addMonomialToPolynomial (Polynomial_dev *polynomial_dev, Monomial *monomial)
{
    Monomial *copy = (Monomial*) malloc (sizeof(Monomial));
    copyMonomial(copy, monomial);

    if (polynomial_dev->first == NULL)
    {
        insertMonomialIntoEmptyPolynomial(polynomial_dev, copy);
	}

    /*
     * Ajouter le cas où on doit ajouter au début d'un polynome non vide.
     */

    else if (polynomial_dev->last->exponent < copy->exponent)
	{
        insertMonomialAtEndPolynomial(polynomial_dev, copy);
	}
	else
	{
		Monomial *current = (Monomial*) malloc (sizeof(Monomial));

		current = polynomial_dev->first;

        while (current->next != NULL && current->exponent < copy->exponent)
		{
			current = current->next;
		}

        if (current->exponent == copy->exponent)
		{
            current->coef = complexSum(current->coef, copy->coef);
		}
		else
		{
            insertMonomialBetweenTwoMonomials(copy, current->prev, current);
		}

        free(current);
	}

	polynomial_dev->lenght += 1;
    polynomial_dev->deg = getDegrePolynomialDev(polynomial_dev);
}




// Insert un monome dans un polynome développé vide.
void insertMonomialIntoEmptyPolynomial (Polynomial_dev *polynomial_dev, Monomial *monomial)
{
		polynomial_dev->first = monomial;
		polynomial_dev->last = monomial;
		polynomial_dev->deg = monomial->exponent;
}


// Insert un monome à la fin d'un polynome développé.
void insertMonomialAtEndPolynomial (Polynomial_dev *polynomial_dev, Monomial *monomial)
{
    polynomial_dev->last->next = monomial;
    monomial->prev = polynomial_dev->last;
    monomial->next = NULL;
    polynomial_dev->last = monomial;
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
void copyMonomial (Monomial *monomial1, Monomial *monomial2)
{
    initMonomial(monomial1, monomial2->exponent, monomial2->coef, monomial2->next, monomial2->prev);
}
