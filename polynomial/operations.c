#include "operations.h"

// Ajouter un monome à un polynome développé
void addMonomialToPolynomial (Polynomial_dev *polynomial_dev, Monomial *monomial)
{
	if (polynomial_dev->first == NULL)
	{
		polynomial_dev->first = monomial;
		polynomial_dev->last = monomial;
		polynomial_dev->lenght = 1;
		polynomial_dev->deg = monomial->exponent;
	}
	else if (polynomial_dev->last->exponent < monomial->exponent)
	{
		polynomial_dev->last->next = monomial;
		monomial->prev = polynomial_dev->last;
		monomial->next = NULL;
		polynomial_dev->last = monomial;
	}
	else
	{
		Monomial *current = (Monomial*) malloc (sizeof(Monomial));

		current = polynomial_dev->first;

		while (current->next != NULL && current->exponent < monomial->exponent)
		{
			current = current->next;
		}

		if (current->exponent == monomial->exponent)
		{
			current->coef = complexSum(current->coef, monomial->coef);
		}		
		else
		{
			current->prev->next = monomial;
			monomial->prev = current->prev;
			monomial->next = current;
			current->next->prev = monomial;
		}
	}
}