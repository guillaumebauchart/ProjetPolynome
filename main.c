#include <stdio.h>
#include <stdlib.h>

#include "src/complex/complex.h"
#include "src/monomial/monomial.h"
#include "src/polynomial/polynomial.h"
#include "src/polynomial/operations.h"

int main()
{
    srand(time(NULL));

    /*
	Monomial monomial;
	getMonomialFromKeyboard (&monomial);
	displayMonomial (monomial);
    printf("\n");
    */



    //while (1)
    //{
        Polynomial_dev *polynomial_dev1 = generateRandomPolynomialDev(0, 50, 1);
        //Polynomial_dev *polynomial_dev1 = createPolynomialDev();
        printf("1 :\n");
        displayPolynomialDev(polynomial_dev1);

        Polynomial_dev *polynomial_dev2 = generateRandomPolynomialDev(0, 50, 1);
        printf("2 :\n");
        displayPolynomialDev(polynomial_dev2);

        Polynomial_dev *result = multiplyRawPolynomials(polynomial_dev2, polynomial_dev1);
        printf("result :\n");
        displayPolynomialDev(result);

        removePolynomialDev(polynomial_dev1);
        removePolynomialDev(polynomial_dev2);
        removePolynomialDev(result);
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
