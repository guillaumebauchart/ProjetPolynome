#include "struct.h"

#include <stdio.h>
#include <stdlib.h>


// Initialise les champs d'un monome aux valeurs passées en paramètres.
void initMonomial (Monomial *monomial, long exponent, double coef, Monomial *next, Monomial *prev)
{
	monomial->exponent = exponent;
	monomial->coef = coef;
	monomial->next = next;
	monomial->prev = prev;
}

// Initialise les champs d'un polynome développé aux valeurs passées en paramètres.
void initPolynomialDev (Polynomial_dev *polynomial_dev, int lenght, int deg, Monomial *first, Monomial *last, PolynomialDev *next, Polynomial_dev *prev)
{
	polynomial_dev->lenght = lenght;
	polynomial_dev->deg = deg;
	polynomial_dev->first = first;
	polynomial_dev->last = last;
	polynomial_dev->next = next;
	polynomial_dev->prev = prev;
}

// Initialise les champs d'un polynome factorisé aux valeurs passées en paramètres.
void initPolynomialFact (Polynomial_fact *polynomial_fact, int lenght, int deg, Polynomial_dev *first, Polynomial_dev *last)
{
	polynomial_fact->lenght = lenght;
	polynomial_fact->deg = deg;
	polynomial_fact->first = first;
	polynomial_fact->last = last;
}

// Initialise les champs d'un polynome aux valeurs passées en paramètres
void initPolynomial (Polynomial *polynomial, int lenght, int deg, Polynomial_dev *developed, Polynomial_dev *integrated, Polynomial_dev *derivative, Polynomial_fact *factored)
{
	polynomial->lenght = lenght;
	polynomial->deg = deg;
	polynomial->developed = developed;
	polynomial->integrated = integrated;
	polynomial->derivative = derivative;
	polynomial->factored = factored;
}

// Affiche un monome
void displayMonomial (Monomial monomial)
{
	printf("%lfX^%ld ", monomial.coef, monomial.exponent);
}

// Affiche un polynome développé
void displayPolynomialDev (Polynomial_dev polynomial_dev)
{
	int i = 0;
	monomial *tmp = polynomial_dev.first;
	displayMonomial(tmp);

	for (i = 0; i < polynomial_dev.lenght && tmp != NULL; ++i)
	{
		tmp = tmp->next;
		displayMonomial(tmp);
	}
}

// Affiche un polynome factorisé
void displayPolynomialFact (Polynomial_fact polynomial_fact)
{
	int i = 0;
	Polynomial_dev *tmp = polynomial_fact.first;
	printf("(");
	displayPolynomialDev(tmp);
	printf(") * ");

	for (i = 0; i < polynomial_fact.lenght && tmp != NULL; ++i)
	{
		tmp = tmp->next;
		printf("(");
		displayPolynomialDev(tmp);
		printf(") * ");
	}
}	