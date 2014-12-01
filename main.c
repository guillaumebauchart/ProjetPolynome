#include <stdio.h>
#include <stdlib.h>

#include "src/tools/complex.h"
#include "src/tools/monomial.h"
#include "src/tools/utility.h"
#include "src/tools/ui.h"
#include "src/polynomial/polynomial.h"
#include "src/polynomial/operations.h"


int main()
{
    launch();


/*
    //while (1)
    //{
        Polynomial_dev *polynomial_dev1 = generateRandomPolynomialDev(0, 1000, 1, -50.0, 50.0);
        //displayPolynomialDev(polynomial_dev1);

        Polynomial_dev *polynomial_dev2 = generateRandomPolynomialDev(0, 1000, 1, -50.0, 50.0);
        //displayPolynomialDev(polynomial_dev2);

        clock_t start = clock();
        //Polynomial_dev *result1 = powPolynomial(polynomial_dev1, 100);
        Polynomial_dev *result1 = multiplyPolynomials(polynomial_dev1, polynomial_dev2);
        double elapsed = (double)(clock() - start)/CLOCKS_PER_SEC;
        //displayPolynomialDev(result1);
        printf("result1 :\n"); printf("L'operation s'est effectue en %2.40lfs\n", elapsed);

        start = clock();
        Polynomial_dev *result2 = multiplyRawPolynomials(polynomial_dev1, polynomial_dev2);
        elapsed = (double)(clock() - start)/CLOCKS_PER_SEC;
        //displayPolynomialDev(result2);
        printf("result2 :\n"); printf("L'operation s'est effectue en %2.40lfs\n", elapsed);


        removePolynomialDev(polynomial_dev1);
        removePolynomialDev(polynomial_dev2);
        removePolynomialDev(result1);
        removePolynomialDev(result2);
    //}

*/

    /*
    Polynomial_dev polynomial_dev = generateRandomPolynomialDev(2, 6, 1);
    displayPolynomialDev(&polynomial_dev);

    while(1)
    {
        Monomial monomial;
        getMonomialFromKeyboard (&monomial);
        polynomial_dev = multiplyPolynomialByMonomial(&polynomial_dev, &monomial);
        displayPolynomialDev(&polynomial_dev);
    }
    */

    return 0;
}
