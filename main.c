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

    //while (1)
    //{
/*
        Polynomial_dev *polynomial_dev1 = generateRandomPolynomialDev(0, 10, 1, -50.0, 50.0);
        printf("polynomial 1 : \n\n");
        displayPolynomialDev(polynomial_dev1);

        Polynomial_dev *polynomial_dev2 = generateRandomPolynomialDev(0, 10, 1, -50.0, 50.0);
        printf("polynomial 2 : \n\n");
        displayPolynomialDev(polynomial_dev2);

        clock_t start = clock();
        Polynomial_dev *sum = addPolynomials(polynomial_dev1, polynomial_dev2);
        double elapsed = (double)(clock() - start)/CLOCKS_PER_SEC;
        printf("\n\nsum :\n");
        displayPolynomialDev(sum);
        printf("L'operation s'est effectue en %2.4lfs\n", elapsed);

        start = clock();
        Polynomial_dev *subtraction = subtractPolynomials(polynomial_dev1, polynomial_dev2);
        elapsed = (double)(clock() - start)/CLOCKS_PER_SEC;
        printf("\n\nsubtraction :\n");
        displayPolynomialDev(subtraction);
        printf("L'operation s'est effectue en %2.4lfs\n", elapsed);

        start = clock();
        Polynomial_dev *rawMultiply = multiplyRawPolynomials(polynomial_dev1, polynomial_dev2);
        elapsed = (double)(clock() - start)/CLOCKS_PER_SEC;
        printf("\n\nrawMultiply :\n");
        displayPolynomialDev(rawMultiply);
        printf("L'operation s'est effectue en %2.4lfs\n", elapsed);

        start = clock();
        Polynomial_dev *multiplykaratsuba = multiplyPolynomials(polynomial_dev1, polynomial_dev2);
        elapsed = (double)(clock() - start)/CLOCKS_PER_SEC;
        printf("\n\nmultiply karatsuba:\n");
        displayPolynomialDev(multiplykaratsuba);
        printf("L'operation s'est effectue en %2.4lfs\n", elapsed);

        start = clock();
        Polynomial_dev *derivated = derivePolynomial(polynomial_dev1);
        elapsed = (double)(clock() - start)/CLOCKS_PER_SEC;
        printf("\n\nderivated :\n");
        displayPolynomialDev(derivated);
        printf("L'operation s'est effectue en %2.4lfs\n", elapsed);

        start = clock();
        Polynomial_dev *integrated = integratePolynomial(polynomial_dev1);
        elapsed = (double)(clock() - start)/CLOCKS_PER_SEC;
        printf("\n\nintegrated :\n");
        displayPolynomialDev(integrated);
        printf("L'operation s'est effectue en %2.4lfs\n", elapsed);

        start = clock();
        Polynomial_dev *pow = powPolynomial(polynomial_dev1, 50);
        elapsed = (double)(clock() - start)/CLOCKS_PER_SEC;
        printf("\n\npow :\n"); fflush(NULL);
        displayPolynomialDev(pow); fflush(NULL);
        printf("L'operation s'est effectue en %2.4lfs\n", elapsed); fflush(NULL);

        removePolynomialDev(polynomial_dev1);
        removePolynomialDev(polynomial_dev2);
        removePolynomialDev(sum);
        removePolynomialDev(rawMultiply);
        removePolynomialDev(multiplykaratsuba);
        removePolynomialDev(derivated);
        removePolynomialDev(pow);

        Complex z;
        complexSet(&z, 2, 3);
        z = complexPow(&z, 150);
        printf("\n\ncomplex = ");
        complexDisplay(&z);
*/

    //}

    return 0;
}
