#include "ui.h"


void launch ()
{
    int choice;
    displayMenu();
	srand(time(NULL));

    ASK_NUMBER("Votre choix ? ", "%d", &choice);

    switch (choice)
    {
        case 1 :    uiGenerate(); break;

        case 7 :{    Complex temp;
                    double x, y;
                    int n;
                    ASK_NUMBER("x = ", "%lf", &x);
                    ASK_NUMBER("y = ", "%lf", &y);
                    ASK_NUMBER("n = ", "%d", &n);
                    temp.x = x; temp.y = y;
                    temp = complexPow(&temp, n);
                    printf ("result ");
                    complexDisplay(&temp);
                    PRINT_SPACE();
                    break;}


        default :   printf("Veuillez choisir un nombre correspondant à une foncitonnalite propose ci-dessus"); break;
    }

}


void displayMenu ()
{
    printf("\t\t\t#=#=#=#=#=#=#=#=#=#=#=#=#=#\n");
    printf("\t\t\t|        Polynomes        |\n");
    printf("\t\t\t=#=#=#=#=#=#=#=#=#=#=#=#=#=\n");

    printf("\n\nLe programme propose de faire differentes operations sur les polynomes.\nLes voici :\n\n");

    printf("1) Generer aleatoirement un polynome.\n");
	printf("2) Addition deux polynomes.\n");
	printf("3) Soustraire deux polynomes.\n");
    printf("4) Multiplier naivement deux polynomes.\n");
	printf("5) Multiplier deux polynomes.\n");

    printf("15) Quitter\n");
    printf("\n\n");
}



void uiGenerate ()
{
    int minExp, maxExp;
    double minDeg, maxDeg, density;

    CLEAR();
    printf("Pour generer un polynome, il faut renseigner :");
    printf("\n\t- Les deux exposants minimal et maximal de polynome");
    printf("\n\t- Les deux bornes d'ou les coefficients aleatoires seront choisis");
    printf("\n\t- La probabilite pour chaque monome d'etre present dans le polynome (choisir 1 pour faire un polynome 'complet').");
    PRINT_SPACE();


    ASK_NUMBER("Choisissez le petit exposant du polynome : ", "%d", &minExp);
    ASK_NUMBER("Choisissez le grand exposant du polynome : ", "%d", &maxExp);
    ASK_NUMBER("Choisissez la petite borne de generation: ", "%lf", &minDeg);
    ASK_NUMBER("Choisissez la grande borne de generation: ", "%lf", &maxDeg);
    ASK_NUMBER("Choisissez la densite de generation: ", "%lf", &density);

    //printf("minExp = %d maxExp = %d minDeg = %lf maxDeg = %lf density = %lf", minExp, maxExp, minDeg, maxDeg, density);

    Polynomial_dev *generated = generateRandomPolynomialDev(minDeg, maxDeg, density, minExp, maxExp);


}


//void uiAdd ();
//void uiSubtract ();
//void uiRawMultiply ();
//void uiMultiply ();
