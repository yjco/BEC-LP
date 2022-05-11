#include <stdio.h>
#include <limits.h>
#include <float.h>

/*
 * Exercise 2-1 (P. 36)
 * Determine the ranges of the variable types both signed and unsigned
 */

int main() {

	printf("Values from limits.g and float.h:\n\n");

	printf("The number of bits in a byte\t\t%d\n", CHAR_BIT);

	printf("The minimum value of CHAR\t\t%d\n", CHAR_MIN);
        printf("The maximum value of CHAR\t\t%d\n", CHAR_MAX);
   	
	printf("The minimum value of SIGNED CHAR\t%d\n", SCHAR_MIN);
   	printf("The maximum value of SIGNED CHAR\t%d\n", SCHAR_MAX);
   	
	printf("The maximum value of UNSIGNED CHAR\t%d\n", UCHAR_MAX);

   	printf("The minimum value of SHORT INT\t\t%d\n", SHRT_MIN);
   	printf("The maximum value of SHORT INT\t\t%d\n", SHRT_MAX); 
   	
	printf("The maximum value of UNSIGNED SHORT INT\t%d\n", USHRT_MAX); 

   	printf("The minimum value of INT\t\t%d\n", INT_MIN);
   	printf("The maximum value of INT\t\t%d\n", INT_MAX);
   	
	printf("The maximum value of UNSIGNED INT\t%d\n", UINT_MAX);

   	printf("The minimum value of LONG\t\t%ld\n", LONG_MIN);
	printf("The maximum value of LONG\t\t%ld\n", LONG_MAX);		
	
	printf("The maximum value of UNSIGNED LONG\t%ld\n", ULONG_MAX);		

   	printf("The minimum value of FLOAT\t\t%d\n", FLT_MIN);
   	printf("The maximum value of FLOAT\t\t%d\n", FLT_MAX);
	
   	printf("The minimum value of BOUBLE\t\t%d\n", DBL_MIN);
   	printf("The maximum value of BOUBLE\t\t%d\n", DBL_MAX);

   	printf("The minimum value of LONG BOUBLE\t%d\n", LDBL_MIN);
   	printf("The maximum value of LONG BOUBLE\t%d\n", LDBL_MAX);
	
}

