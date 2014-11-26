#include <stdio.h>
#include <stdlib.h>

#include "src/tools/complex.h"
#include "src/tools/monomial.h"
#include "src/tools/utility.h"
#include "src/polynomial/polynomial.h"
#include "src/polynomial/operations.h"
#include <time.h>

int main()
{
    
    //while (1)
    //{
        Polynomial_dev *polynomial_dev1 = generateRandomPolynomialDev(0, 10000, 1);
        //Polynomial_dev *polynomial_dev1 = createPolynomialDev();
        //printf("1 :\n");
        //displayPolynomialDev(polynomial_dev1);

        Polynomial_dev *polynomial_dev2 = generateRandomPolynomialDev(0, 10000, 1);
        //printf("2 :\n");
        //displayPolynomialDev(polynomial_dev2);


        clock_t start = clock();
        Polynomial_dev *result1 = multiplyPolynomials(polynomial_dev2, polynomial_dev1);
        double elapsed = (double)(clock() - start)/CLOCKS_PER_SEC;
        printf("result1 :\n"); printf("L'operation s'est effectue en %2.40lfs\n", elapsed);
        //displayPolynomialDev(result1);


        start = clock();
        Polynomial_dev *result2 = multiplyRawPolynomials(polynomial_dev2, polynomial_dev1);
        elapsed = (double)(clock() - start)/CLOCKS_PER_SEC;
        printf("result2 :\n"); printf("L'operation s'est effectue en %2.40lfs\n", elapsed);
        //displayPolynomialDev(result2);


        removePolynomialDev(polynomial_dev1);
        removePolynomialDev(polynomial_dev2);
        removePolynomialDev(result1);
        removePolynomialDev(result2);
    //}


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
