#include "operations.h"


/*
// Ajouter un monome à un polynome développé.
Polynomial_dev addMonomialToPolynomial (Polynomial_dev *polynomial_dev, Monomial *monomial)
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

    return *polynomial_dev;
}
*/

// Ajouter un monome à un polynome développé.
Polynomial_dev addMonomialToPolynomial (Polynomial_dev *polynomial_dev, Monomial *monomial)
{
    /* Pour ajouter un monome à un polynome, on va ajouter le monome
     * dans un polynome singleton temporaire, et on va faire la
     * somme des deux polynomes.
     */

    if (monomial->coef.x != 0 || monomial->coef.y != 0) // Si le coef n'est pas nul.
    {
        Polynomial_dev singleton = generatePolynomialDev(0, 0, 0); // On génère un polynome vide.
        insertMonomialIntoEmptyPolynomial(&singleton, monomial); // On insert le monome dans le polynome singleton.

        *polynomial_dev = addPolynomials(polynomial_dev, &singleton); // On fait ajoute le singleton au polynome.
    }

    return *polynomial_dev; // On retourne le contenu du polynome.
}

// Ajoute deux polynomes entre eux et renvoie le résultat.
Polynomial_dev addPolynomials (Polynomial_dev *poly1, Polynomial_dev *poly2)
{
    /* On sait que les deux polynomes sont triés dans l'ordre croissant.
     * Le résultat de la somme va être stockés dans poly1, on va parcourir les deux
     * polynomes en même temps, et ajouter au fur et à mesure les monomes de poly2 dans poly1.
     */

    Monomial *current1 = poly1->first, *current2 = poly2->first; // On déclare les deux variables de parcours

    while (current2 != NULL) // Tant qu'on n'est pas arrivé à la fin de poly2.
    {
        if (current1 != NULL && current1->exponent == current2->exponent) // Si on n'est pas à la fin de poly1, et que l'on a deux monomes à exposants égaux.
        {
            current1->coef = complexSum(current1->coef, current2->coef); // On fait la sommes des coefs, et on stock le résultat dans le monome correspondant de poly1.

            // Il faut vérifier que la somme n'a pas rendu nul le coef.
            Monomial *toRemove = NULL; // On déclare un variable qui va stocker l'adresse du monome nul s'il s'avère qu'il y en a un.
            if (current1->coef.x == 0 && current1->coef.y == 0) // Si le coef est nul.
            {
                toRemove = current1; // toRemove reçoit l'adresse du monome nul.
            }

            // On fait avancer les deux variables de parcours.
            current1 = current1->next;
            current2 = current2->next;

            if (toRemove) // S'il y a bien un monome à retirer, on le retire.
            {
                removeMonomial(poly1, toRemove);
            }
        }
        else if (current1 == NULL || current1->exponent > current2->exponent) // Sinon si on n'est à la fin de poly1, ou que l'exposant du monome courant de poly1 est supérieur à celui du monome courant de poly2.
        {
            /* Si on est à la fin de poly1, alors tous les monomes restant de poly2
             * sont de degré supérieur au dernier de poly1, donc il faut les
             * ajouter à la fin de poly1.
             *
             * Ou alors tant que le monome courant de poly1 est de degré supérieur
             * au monome courant de poly2, on ajoute le monome courant de poly2
             * avant le monom courant de poly1
             */

            Monomial *copy = (Monomial*) malloc (sizeof(Monomial)); // On crée une copie du monome courant de poly2, que l'on va insérer dans poly1.
            copyMonomial(copy, current2);
            insertMonomialBeforeCurrent(poly1, current1, copy);
            current2 = current2->next; // On fait avancer la variable de parcours de poly2.
        }
        else // Sinon on fait avancer la variable de parcours de poly1.
        {
            current1 = current1->next;
        }
    }

    return *poly1; // On renvoie le contenu de poly1.
}



// Insert un monome dans un polynome développé vide.
void insertMonomialIntoEmptyPolynomial (Polynomial_dev *polynomial_dev, Monomial *monomial)
{
    // Le monome inséré devient à la fois le premier et le dernier du polynome.
    polynomial_dev->first = monomial;
    polynomial_dev->last = monomial;

    // Il n'a aucun prédécesseur ni successeur.
    monomial->prev = NULL;
    monomial->next = NULL;

    polynomial_dev->lenght++; // On incrémente la longueur du polynome.
}

// Insert un monome au début d'un polynome développé.
void insertMonomialAtBeginningPolynomial (Polynomial_dev *polynomial_dev, Monomial *monomial)
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

// Insert un monome à la fin d'un polynome développé.
void insertMonomialAtEndPolynomial (Polynomial_dev *polynomial_dev, Monomial *monomial)
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







