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
            insertMonomialBetweenTwoMonomials(polynomial_dev, copy, current->prev, current); // On insert le monome entre le monome courant et celui qui le précède.
		}
    }
}


// Ajoute deux polynomes entre eux et renvoie le résultat
//Polynomial_dev addPolynomials (Polynomial_dev poly1, Polynomial_dev poly2)
//{
//    Polynomial_dev *result = (Polynomial_dev*) malloc(sizeof(Polynomial_dev));
//    Monomial *current = poly1.first;
//}



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
    monomial->prev = NULL;
    monomial->next = polynomial_dev->first;
    polynomial_dev->first->prev = monomial;
    polynomial_dev->first = monomial;
    polynomial_dev->lenght++;
}


// Insert un monome à la fin d'un polynome développé.
void insertMonomialAtEndPolynomial (Polynomial_dev *polynomial_dev, Monomial *monomial)
{
    polynomial_dev->last->next = monomial;
    monomial->prev = polynomial_dev->last;
    monomial->next = NULL;
    polynomial_dev->last = monomial;
    polynomial_dev->lenght++;
}

// Insert un monome entre deux autres monomes d'un polynome développé.
void insertMonomialBetweenTwoMonomials (Polynomial_dev *polynomial_dev, Monomial *monomialInsert, Monomial *monomialLeft, Monomial *monomialRight)
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







