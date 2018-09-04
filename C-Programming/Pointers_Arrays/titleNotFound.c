#include <stdio.h>

int main()
{
	long long var1, var2;
	long long * var_ptr;

	var1 = 0x4ABADABBAD000000;

	var_ptr = &var1;
	var2 = *var_ptr;

	/* Compare var1 to var2 and print human-readable results */
	printf("\nComparing the two vars:\t");
	if (var1 == var2)						// If var1 is equal to var2 then...
	{
		printf("Equal\n");					// Good
	}
	else									// ...otherwise...
	{
		printf("NOT EQUAL\n");				// BAD
		printf("var1 == %d\nvar2 == %d\n", var1, var2);
	}

	getchar();
	getchar();
	return 0;
}