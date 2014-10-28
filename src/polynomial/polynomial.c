#include "polynomial.h"
#include "operations.h"


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
        printf(" + \n");
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


/* Recherche pour faire une fonction de saisie sécurisée générique, fonction actuellement non-terminée.

void* saisieSecure ()

do
    {
        cout << "Choisissez une valeure pour min : ";
        saisie = scanf("%lf", min);
        fflush(stdin); // On vide la mémoire tampon.
    }while(!saisie); // Tant que l'utilisateur ne rentre pas un reel comme on le lui demande.

*/


// Renvoie le degré d'un polyome développé.
int getDegreMaxPolynomialDev (Polynomial_dev *polynomial_dev)
{
    if (polynomial_dev->last != NULL) // Si le polynome n'est pas vide, on renvoie le l'exposant du dernier monome.
    {
        return polynomial_dev->last->exponent;
    }
    else // Sinon on renvoie 0.
    {
        return 0;
    }
}



// Génère un polynome développé aléatoirement.
Polynomial_dev generatePolynomialDev(int minDeg, int maxDeg, double density)
{
    /* Génère un polnyome developpé aléatoire avec des monomes dont l'exposant est compris
     * entre minDeg et maxDeg. Sachant que la densité est un nombre en 0 et 1 qui
     * permet de déterminé la probabilité de chaque monome d'être crée.
     * Plus la densité est faible, moins il y a de chance que chaque monome ne
     * soit crée.
     */


    // Polynomial_dev *polynomial_dev = (Polynomial_dev*) malloc (sizeof(Polynomial_dev));
    Polynomial_dev polynomial_dev; // On déclare le polynome.
    initPolynomialDev(&polynomial_dev, 0, NULL, NULL, NULL, NULL); // On initialise ses champs à 0.
    int i = 0; // On déclare la variable de parcours.
    Complex z; // On déclare le coefficient.

    for (i=minDeg ; i<=maxDeg ; i++) // On parcours l'intervalle de degrés demandés.
    {
        double chance = random(0,1); // On calcul la chance aléatoirement entre 0 et 1.

        if (density > chance) // Si la densité est supérieur à la chance, on créer le monome, sinon non.
        {
            complexSet(&z, random(-50,50), random(-50,50)); // On initialise le complexe aléatoirement.

            Monomial *monomial = (Monomial*) malloc (sizeof(Monomial)); // On alloue un monome.
            initMonomial(monomial, i, z, NULL, NULL); // On initialise ses champs à 0.

            polynomial_dev = addMonomialToPolynomial(&polynomial_dev, monomial); // On l'ajoute dans le polynome.

            free(monomial); // On libère le monome (car c'est une copie qui sera ajouter dans le polynome).
        }
    }
    return polynomial_dev; // On renvoie le polynome.
}

// Supprime monomial de polynomial_dev et libère la mémoire.
void removeMonomial (Polynomial_dev *polynomial_dev, Monomial *monomial)
{
    if (polynomial_dev->first == monomial) // Si on doit supprimer le premier monome du polynome.
    {
        polynomial_dev->first = polynomial_dev->first->next; // Le premier monome devient le successeur de l'ancier premier monome.

        if (polynomial_dev->first != NULL) // Si le premier monome existe.
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

        if (polynomial_dev->last != NULL) // Si le dernier monome existe.
        {
            polynomial_dev->last->next = NULL; // Son successeur devient NULL.
        }
    }
    else
    {
        monomial->prev->next = monomial->next; // Le successeur du prédécesseur du monome à supprimer devient le successeur du monome à supprimer.
        monomial->next->prev = monomial->prev; // Le prédécesseur du successeur du monome à supprimer devient le prédécesseur du monome à supprimer.
    }
    polynomial_dev->lenght--; // On décrémente la longueur du polynome.

    free(monomial); // On libère le monome.
}


// Supprimer un polynome developpé et libère la mémoire.
void removePolynomialDev (Polynomial_dev *polynomial_dev)
{
    while (polynomial_dev->last != NULL) // Tant que le dernier monome existe.
    {
        removeMonomial(polynomial_dev, polynomial_dev->last); // On supprimer le dernier monome.
    }

    free(polynomial_dev); // On libère le polynome à la fin.
}




// Génère un double aléatoire entre a et b.
double random(double a, double b)
{
    /* rand()/RAND_MAX donne un nombre entre 0 et 1.
     * On mutliplie de résultat par l'écart entre les deux bornes.
     * On ajoute la valeur de la première borne.
     * On renvoie le résultat.
     */

    return (rand()/(double)RAND_MAX)*(b-a)+a;
}
