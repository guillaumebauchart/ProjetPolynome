#include "operations.h"
#include "polynomial.h"


// Ajoute un monome à un polynome développé et retourne l'adresse du polynome résultat.
Polynomial_dev *addMonomialToPolynomial (Polynomial_dev *polynomial_dev, Monomial *monomial)
{
    /* Pour ajouter un monome à un polynome, on va ajouter le monome
     * dans un polynome singleton temporaire, et on va faire la
     * somme des deux polynomes.
     */

    Polynomial_dev *result = NULL ; // On crée le pointeur qui va récupérer le résultat.

    if (monomial->coef.x != 0 || monomial->coef.y != 0) // Si le coef n'est pas nul.
    {
        Polynomial_dev *singleton = createPolynomialDev(); // On crée un polynome vide.
        insertMonomialIntoEmptyPolynomial(singleton, monomial); // On insert le monome dans le polynome singleton.

        result = addPolynomials(polynomial_dev, singleton); // On fait la somme du singleton et du polynome, récupère l'adresse du résultat dans result.
    }

    return result; // On retourne l'adresse du resultat.
}

// Ajoute deux polynomes entre eux et retourne l'adresse du polynome résultat.
Polynomial_dev *addPolynomials (Polynomial_dev *poly1, Polynomial_dev *poly2)
{
    /* On sait que les deux polynomes sont triés dans l'ordre croissant.
     * Le résultat de la somme va être renvoyé dans result, on va parcourir les deux
     * polynomes en même temps, et ajouter au fur et à mesure les monomes de poly2 dans result.
     */

    Polynomial_dev *result = createPolynomialDev(); // On créer le polynome vide qui va contenir le résultat.
    copyPolynomial(result, poly1); // On copie poly1 dans result.

    Monomial *current1 = result->first, *current2 = poly2->first; // On déclare les deux variables de parcours.

    while (current2 != NULL) // Tant qu'on n'est pas arrivé à la fin de poly2.
    {
        if (current1 != NULL && current1->exponent == current2->exponent) // Si on n'est pas à la fin de poly1, et que l'on a deux monomes à exposants égaux.
        {
            current1->coef = complexSum(current1->coef, current2->coef); // On fait la sommes des coefs, et on stock le résultat dans le monome correspondant de result.

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
                removeMonomial(result, toRemove);
            }
        }
        else if (current1 == NULL || current1->exponent > current2->exponent) // Sinon si on n'est à la fin de result, ou que l'exposant du monome courant de result est supérieur à celui du monome courant de poly2.
        {
            /* Si on est à la fin de result, alors tous les monomes restant de poly2
             * sont de degré supérieur au dernier de result, donc il faut les
             * ajouter à la fin de result.
             *
             * Ou alors tant que le monome courant de result est de degré supérieur
             * au monome courant de poly2, on ajoute le monome courant de poly2
             * avant le monome courant de result.
             */

            Monomial *copy = createMonomial(); // On crée une copie du monome courant de poly2, que l'on va insérer dans result.
            copyMonomial(copy, current2); // On copie current2 dans copy.
            insertMonomialBeforeCurrent(result, current1, copy); // On insert copy avant le monome current1 dans result.
            current2 = current2->next; // On fait avancer la variable de parcours de poly2.
        }
        else // Sinon on fait avancer la variable de parcours de result.
        {
            current1 = current1->next;
        }
    }

    return result; // On retourne l'adresse du résultat.
}

// Soustrait deux polynomes entre eux et retourne l'adresse du polynome résultat.
Polynomial_dev *subtractPolynomials (Polynomial_dev *poly1, Polynomial_dev *poly2)
{
    /* On sait que les deux polynomes sont triés dans l'ordre croissant.
     * Le résultat de la somme va être renvoyé dans result, on va parcourir les deux
     * polynomes en même temps, et soustraire au fur et à mesure les monomes de poly2 dans result.
     */

    Polynomial_dev *result = createPolynomialDev(); // On créer le polynome vide qui va contenir le résultat.
    copyPolynomial(result, poly1); // On copie poly1 dans result.

    Monomial *current1 = result->first, *current2 = poly2->first; // On déclare les deux variables de parcours.

    while (current2 != NULL) // Tant qu'on n'est pas arrivé à la fin de poly2.
    {
        if (current1 != NULL && current1->exponent == current2->exponent) // Si on n'est pas à la fin de poly1, et que l'on a deux monomes à exposants égaux.
        {
            current1->coef = complexSubtract(current1->coef, current2->coef); // On fait la soustraction des coefs, et on stock le résultat dans le monome correspondant de result.

            // Il faut vérifier que la soustraction n'a pas rendu nul le coef.
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
                removeMonomial(result, toRemove);
            }
        }
        else if (current1 == NULL || current1->exponent > current2->exponent)
        {
            /* Si on est à la fin de result, alors tous les monomes restant de poly2
             * sont de degré supérieur au dernier de result, donc il faut les
             * ajouter à la fin de result.
             *
             * Ou alors tant que le monome courant de result est de degré supérieur
             * au monome courant de poly2, on ajoute le monome courant de poly2
             * avant le monome courant de result.
             */

            Monomial *copy = createMonomial(); // On crée une copie du monome courant de poly2, que l'on va insérer dans result.
            copyMonomial(copy, current2); // On copie current2 dans copy.
            copy->coef.x *= -1; copy->coef.y *= -1;
            insertMonomialBeforeCurrent(result, current1, copy); // On insert copy avant le monome current1 dans result.
            current2 = current2->next; // On fait avancer la variable de parcours de poly2.
        }
        else // Sinon on fait avancer la variable de parcours de result.
        {
            current1 = current1->next;
        }
    }

    return result; // On retourne l'adresse du résultat.
}


// Multiplication d'un polynome développé par un monome, retourne l'adresse du polynome résultat.
Polynomial_dev *multiplyPolynomialByMonomial (Polynomial_dev *polynomial_dev, Monomial *monomial)
{
    // On multiplie chaque monome du polynome par monomial.
    Polynomial_dev *result = createPolynomialDev(); // On créer le polynome vide qui va contenir le résultat.
    copyPolynomial(result, polynomial_dev); // On copie polynomial_dev dans result.

    Monomial *current = result->first; // On déclare la variable de parcours.

    while (current != NULL) // Tant qu'on n'est pas arrivé à la fin du polynome.
    {
        current->coef = complexMultiplication(current->coef, monomial->coef); // On multiplie les coefs entre eux, et on stock le résultat dans le coef courant.
        current->exponent += monomial->exponent; // On ajoute à l'exposant courant, l'exposant de monomial.

        // Il faut vérifier que le produit n'a pas rendu nul le coef.
        Monomial *toRemove = NULL; // On déclare un variable qui va stocker l'adresse du monome nul s'il s'avère qu'il y en a un.
        if (current->coef.x == 0 && current->coef.y == 0) // Si le coef est nul.
        {
            toRemove = current; // toRemove reçoit l'adresse du monome nul.
        }

        current = current->next;

        if (toRemove) // S'il y a bien un monome à retirer, on le retire.
        {
            removeMonomial(result, toRemove);
        }
    }

    return result; // On retourne l'adresse du résultat.
}

// Multiplication naïve de deux polynomes développé, retourne l'adresse du polynome résultat.
Polynomial_dev *multiplyRawPolynomials (Polynomial_dev *poly1, Polynomial_dev *poly2)
{
    Polynomial_dev *result = createPolynomialDev(); // On crée le polynome vide qui va contenir le résultat.
    Monomial *current = poly2->first;

    while (current != NULL)
    {
        Polynomial_dev *temp = NULL; // On crée le polynome vide qui va contenir un résultat temporaire.
        Polynomial_dev *before = result; // On crée un pointeur qui va stocker l'ancienne adresse de result, pour pouvoir libérer la mémoire ensuite.

        temp = multiplyPolynomialByMonomial(poly1, current); // temp reçoit le résultat de la multiplication du poly1 et du monome courant de poly2.
        result = addPolynomials(before, temp); // On ajoute temp à result.

        // On libère la mémoire.
        removePolynomialDev(before);
        removePolynomialDev(temp);

        current = current->next; // On fait avancer la variable de parcours.
    }

    return result; // On retourne l'adresse du résultat.
}

// Multiplie deux polynomes.
Polynomial_dev *multiplyPolynomials (Polynomial_dev *poly1, Polynomial_dev *poly2)
{
    Polynomial_dev *result;

    result = multiplyPolynomialsKaratsuba(poly1, poly2);

    return result;
}


// Découpe un polynome avant et après la puissance n et met les deux parties dans left et right.
void splitAndReducePolynomial (Polynomial_dev *polynomial_dev, Polynomial_dev *left, Polynomial_dev *right, int n)
{
    Monomial *current = polynomial_dev->first; // On crée une variable de parcours pour le polynome à découper.

    while (current != NULL) // Tant qu'on n'est pas arrivé à la fin du polynome.
    {
        Monomial *copyToAdd = createMonomial(); // On crée un monome qui va recevoir un copie du monome courrant du polynome.
        copyMonomial(copyToAdd, current); // On fait la copie.

        if (current->exponent >= n) // Si l'exposant est supérieur à n.
        {
            copyToAdd->exponent -= n; // On retire n à l'exposant, car on factorise par X^n.
            insertMonomialAtEndPolynomial(left, copyToAdd); // On ajoute le monome dans le polynome de gauche.
        }
        else
        {
            insertMonomialAtEndPolynomial(right, copyToAdd); // Sinon on ajoute directment la copie dans le polynome de droite.
        }

        current = current->next; // On fait avancer la variable de parcours.
    }
}

// Multiplie le polynome par X^n
void increasePolynomial(Polynomial_dev *polynomial_dev, int n)
{
    Monomial *current = polynomial_dev->first; // On crée une variable de parcours qui pointe vers le premier monome du polynome.

    while (current != NULL) // Tant qu'on n'est pas arrivé à la fin du polynome.
    {
        current->exponent += n; // On ajoute n à l'exposant du monome courant.
        current = current->next; // On fait avancer la variable de parcours.
    }
}


// Algorightme de Karatsuba
Polynomial_dev *multiplyPolynomialsKaratsuba (Polynomial_dev *A, Polynomial_dev *B)
{
    if (A->lenght == 0 || B->lenght == 0) // On vérifie si l'un des polynomes est nul, si oui on renvoie un polynome nul.
    {
        return createPolynomialDev();
    }

    Polynomial_dev *before; // On définie cette variable temporaire qui va contenir les adresses précédentes de chaque pointeur, cela va permettre de libérer la mémoire à chaque fois.

    // On détermine la puissance centrale.
    int degMax = normeSup(getDegreMaxPolynomialDev(A), getDegreMaxPolynomialDev(B));
    int degMin = normeInf(getDegreMinPolynomialDev(A), getDegreMinPolynomialDev(B));
    int n = (degMin + degMax)/2;

    // Si un des polynomes est un singleton, on fait une multiplication de polynomes naïve.
    if (n == 0 || A->lenght == 1 || B->lenght == 1)
    {
        return multiplyRawPolynomials(A, B);
    }

    // On décompose les polynomes selon n, tel que : A = A1*X^n + A2 et B = B1*X^n + B2.
    Polynomial_dev *A1 = createPolynomialDev(), *A2 = createPolynomialDev(), *B1 = createPolynomialDev(), *B2 = createPolynomialDev();
    splitAndReducePolynomial(A, A1, A2, n);
    splitAndReducePolynomial(B, B1, B2, n);

    // On calcule un premier résultat intermédiaire : I1 = A2 * B2.
    Polynomial_dev *I1 = createPolynomialDev();
    copyPolynomial(I1, A2);
    before = I1; // On stocke l'adresse précédente.
    I1 = multiplyPolynomials(I1, B2);
    removePolynomialDev(before); // On libère la mémoire.

    // Puis le deuxième : I2 = A1 * B1
    Polynomial_dev *I2 = createPolynomialDev();
    copyPolynomial(I2, A1);
    before = I2; // On stocke l'adresse précédente.
    I2 = multiplyPolynomials(I2, B1);
    removePolynomialDev(before); // On libère la mémoire.

    // On réutilise A2 et B2 pour respectivement stocker A1+A2 et B1+B2.
    before = A2; // On stocke l'adresse précédente.
    A2 = addPolynomials(A1, A2);
    removePolynomialDev(before); // On libère la mémoire.

    before = B2; // On stocke l'adresse précédente.
    B2 = addPolynomials(B1, B2);
    removePolynomialDev(before); // On libère la mémoire.

    // On calcul un premier résultat
    before = A2; // On stocke l'adresse précédente.
    A2 = multiplyPolynomials(A2, B2);
    removePolynomialDev(before); // On libère la mémoire.

    before = A2; // On stocke l'adresse précédente.
    A2 = subtractPolynomials(A2, I1);
    removePolynomialDev(before); // On libère la mémoire.

    before = A2; // On stocke l'adresse précédente.
    A2 = subtractPolynomials(A2, I2);
    removePolynomialDev(before); // On libère la mémoire.

    // On élève la puissance de A2 et I2
    increasePolynomial(A2, n);
    increasePolynomial(I2, 2*n);

    // On ajoute I2 et I1 à A2
    before = A2; // On stocke l'adresse précédente.
    A2 = addPolynomials(A2, I2);
    removePolynomialDev(before); // On libère la mémoire.

    before = A2; // On stocke l'adresse précédente.
    A2 = addPolynomials(A2, I1);
    removePolynomialDev(before); // On libère la mémoire.

    // On libère la mémoire
    removePolynomialDev(A1);
    removePolynomialDev(B1);
    removePolynomialDev(B2);
    removePolynomialDev(I1);
    removePolynomialDev(I2);

    return A2;
}











