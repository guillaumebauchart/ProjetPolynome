#ifndef UI_H_INCLUDED
#define UI_H_INCLUDED

#include <time.h>
#include "utility.h"

#ifdef _WIN32
    #include <Windows.h>

    #define CLEAR(); system("cls");
#else
    #include <unistd.h>

    #define CLEAR(); system("clear");
#endif

#define PRINT_SPACE(); printf("\n\n");

#define ASK_NUMBER(txt, format, value);              \
    {                                               \
        int returned;                               \
        do                                          \
        {                                           \
            printf(txt);                            \
            fflush(stdout);                         \
            returned = scanf(format, value);        \
            fflush(stdin);                          \
         }while(!returned);                         \
    }

/*
do
{
    printf("Votre choix : ");
    returned = scanf("%d", &choice); // On récupère la valeur de retourné par scanf.
    fflush(stdin); // On vide la mémoire tampon.
}while(!returned); // Tant que l'utilisateur ne rentre pas un entier comme on le lui demande.
*/


typedef struct Polynomial_uiw
{
    Polynomial *polynomial;
    char *name;
}Polynomial_ui;

/*
typedef struct Polynomial_ui_tab
{
    Polynomial polynomial[];
}Polynomial_ui_tab;
*/


void launch ();
void displayMenu ();

void uiGenerate ();
void uiAdd ();
void uiSubtract ();
void uiRawMultiply ();
void uiMultiply ();




#endif // UI_H_INCLUDED
