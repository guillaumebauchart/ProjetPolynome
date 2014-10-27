#include <stdio.h>
#include <stdlib.h>

#include "src\complex\complex.h"
#include "src\monomial\monomial.h"
#include "src\polynomial\polynomial.h"
#include "src\polynomial\operations.h"

int main()
{
	/*
	Complex z;
	getComplexFromKeyBoard (&z);
	complexDisplay (z);
	*/

    /*
	Monomial monomial;
	getMonomialFromKeyboard (&monomial);
	displayMonomial (monomial);
    printf("\n");
    */


    Polynomial_dev polynomial_dev = generatePolynomialDev(0, 25, 1);
    displayPolynomialDev(&polynomial_dev);

    /*
    while(1)
    {
        Monomial monomial;
        getMonomialFromKeyboard (&monomial);
        addMonomialToPolynomial(&polynomial_dev, &monomial);
        displayPolynomialDev(&polynomial_dev);
    }
    */

    /*
    int i;
    srand(time(NULL));
    for (i=0;i<40;i++)
    printf("%.5lf\n", random(0,1));
    */

    /*
	Complex z1, z2, result1, result2;
	complexSet (&z1, 2, -4);
	complexSet (&z2, -3, 7);
	result1 = complexSum (z1, z2);
	result2 = complexMultiplication (z1, z2);
	printf("z1 + z2 = ");
	complexDisplay (result1);
    printf("\nz1 * z2 = ");
	complexDisplay (result2);
	printf("\n\n");
    */

	/*
    Monomial monomial


	*/

    return 0;
}
