#include "polynomial.h"
#include "../tools/utility.h"

// Initialise les champs d'un polynome développé aux valeurs passées en paramètres.
void initPolynomialDev (Polynomial_dev *polynomial_dev, int lenght, Monomial *first, Monomial *last, Polynomial_dev *next, Polynomial_dev *prev)
{
    polynomial_dev->lenght = lenght;
    polynomial_dev->first = first;
    polynomial_dev->last = last;
    polynomial_dev->next = next;
    polynomial_dev->prev = prev;
}

// Initialise les champs d'un polynome factorisé aux valeurs passées en paramètres.
void initPolynomialFact (Polynomial_fact *polynomial_fact, int lenght, Polynomial_dev *first, Polynomial_dev *last)
{
    polynomial_fact->lenght = lenght;
    polynomial_fact->first = first;
    polynomial_fact->last = last;
}

// Initialise les champs d'un polynome aux valeurs passées en paramètres.
void initPolynomial (Polynomial *polynomial, int lenght, Polynomial_dev *developed, Polynomial_fact *factored)
{
    polynomial->lenght = lenght;
    polynomial->developed = developed;
    polynomial->factored = factored;
    polynomial->integrated = NULL;
    polynomial->derivative = NULL;
}


// Affiche un polynome développé.
void displayPolynomialDev (Polynomial_dev *polynomial_dev)
{
    Monomial *tmp = polynomial_dev->first; // On crée une variable de parcours.

    while (tmp != NULL) // Tant que l'on n'est pas arrivé à la fin du polynome développé.
    {
        displayMonomial(tmp); // On affiche le monome courant.
        if (tmp->next != NULL)
        {
            printf(" + ");
        }
        tmp = tmp->next; // On fait avancer la variable de parcours.
    }
    printf("\n\n");
}

// Affiche un polynome factorisé.
void displayPolynomialFact (Polynomial_fact *polynomial_fact)
{
    Polynomial_dev *tmp = polynomial_fact->first; // On crée une variable de parcours.

    while (tmp != NULL) // Tant que l'on n'est pas arrivé à la du polynome factorisé.
    {
        printf("(");
        displayPolynomialDev(tmp); // On affiche le polynome développé courant.
        printf(") * ");
        tmp = tmp->next; // On fait avancer la variable de parcours.
    }
}


/* DEV DE LA FONCTION EN COURS
// Saisie manuelle des valeurs d'un polynome developpé.
void getPolynomialDevFromKeyBoard (Polynomial_dev *polynomial_dev)
{
    int i = 0, lenght;

    do
    {
        printf("Choisissez une longueur pour le polynome : ");
        saisie = scanf("%d", &lenght);
        fflush(stdin); // On vide la mémoire tampon.
    }while(!saisie); // Tant que l'utilisateur ne rentre pas un reel comme on le lui demande.

    Monomial *tmp = polynomial_dev.first;
    displayMonomial(*tmp);

    for (i = 0; i < polynomial_dev.lenght && tmp != NULL; ++i)
    {
        tmp = tmp->next;
        displayMonomial(*tmp);
    }
}

*/


// Créer un polynome, alloue la mémoire, l'initialise à 0, et retourne l'adresse du polynome.
Polynomial_dev *createPolynomialDev ()
{
    Polynomial_dev *polynomial_dev = (Polynomial_dev*) malloc(sizeof(Polynomial_dev)); // On déclare le polynome et on alloue la mémoire.
    initPolynomialDev(polynomial_dev, 0, NULL, NULL, NULL, NULL); // On initialise ses champs à 0.

    return polynomial_dev;
}


// Génère un polynome développé aléatoirement et en retourne l'adresse.
Polynomial_dev *generateRandomPolynomialDev (int minDeg, int maxDeg, double density, double minCoef, double maxCoef)
{
    /* Génère un polnyome developpé aléatoire avec des monomes dont l'exposant est compris
     * entre minDeg et maxDeg. Sachant que la densité est un nombre en 0 et 1 qui
     * permet de déterminé la probabilité de chaque monome d'être crée.
     * Plus la densité est faible, moins il y a de chance que chaque monome ne
     * soit crée.
     */

    Polynomial_dev *polynomial_dev = createPolynomialDev(); // On crée un polynome développé vide.
    int i = 0; // On déclare la variable de parcours.

    for (i=minDeg ; i<=maxDeg ; i++) // On parcours l'intervalle de degrés demandés.
    {
        double chance = randomInInterval(0,1); // On calcul la chance aléatoirement entre 0 et 1.

        if (density >= chance) // Si la densité est supérieur ou égale à la chance, on créer le monome, sinon non.
        {
            Monomial *monomial = generateRandomMonomial(i, minCoef, maxCoef);
            insertMonomialAtEndPolynomial(polynomial_dev, monomial);
        }
    }
    return polynomial_dev; // On renvoie l'adresse du polynome.
}

// Supprime monomial de polynomial_dev et libère la mémoire.
void removeMonomial (Polynomial_dev *polynomial_dev, Monomial *monomial)
{
    if (polynomial_dev->first == monomial) // Si on doit supprimer le premier monome du polynome.
    {
        polynomial_dev->first = polynomial_dev->first->next; // Le premier monome devient le successeur de l'ancier premier monome.
        if (polynomial_dev->first != NULL) // Si l'ancien premier monome a un successeur.
        {
            polynomial_dev->first->prev = NULL; // Son prédécesseur devient NULL.
        }
        else // Sinon le dernier monome du polynome devient NULL, car si le premier monome n'existe pas il s'agit d'un polynome vide.
        {
            polynomial_dev->last = NULL;
        }
    }
    else if (polynomial_dev->last == monomial) // Sinon si on doit supprimer le dernier monome du polynome.
    {
        polynomial_dev->last = polynomial_dev->last->prev; // Le dernier monome devient le prédécesseur de l'ancier dernier monome.

        if (polynomial_dev->last != NULL) // Si l'ancien dernier monome a un prédécesseur.
        {
            polynomial_dev->last->next = NULL; // Son successeur devient NULL.
        }
        else
        {
            polynomial_dev->first = NULL;
        }
    }
    else
    {
        monomial->prev->next = monomial->next; // Le successeur du prédécesseur du monome à supprimer devient le successeur du monome à supprimer.
        monomial->next->prev = monomial->prev; // Le prédécesseur du successeur du monome à supprimer devient le prédécesseur du monome à supprime
    }
    polynomial_dev->lenght--; // On décrémente la longueur du polynome.

    free(monomial); // On libère le monome.
}


// Supprimer un polynome developpé et libère la mémoire.
void removePolynomialDev (Polynomial_dev *polynomial_dev)
{
    if (polynomial_dev != NULL)
    {
        while (polynomial_dev->last != NULL) // Tant que le dernier monome existe.
        {
            removeMonomial(polynomial_dev, polynomial_dev->last); // On supprimer le dernier monome.
        }

        free(polynomial_dev); // On libère le polynome à la fin.
    }
}

