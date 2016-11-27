#include <stdio.h>
#include <stdlib.h>


int climbStair(int n)
{
	unsigned int ulloop = 0;
	unsigned int *adata = NULL;
	unsigned int ret;

	adata = (unsigned int*)malloc(n * sizeof(unsigned int));

	for (ulloop=0; ulloop <= n;ulloop ++)
	{
		adata[ulloop] = 0;
	}

	adata[0] = adata[1] = 1;

	for (ulloop = 2; ulloop <= n; ulloop ++)
	{
		adata[ulloop] = adata[ulloop-1] + adata[ulloop -2];
		printf("adata[%d] is %d\n", ulloop, adata[ulloop]);
		/* code */
	}

	ret = adata[n];
	free(adata);
	return ret;
}

int main(int argc, char *argv[])
{
	int ret = 0;
	ret = climbStair(atoi(argv[1]));
	printf("#RET is %d\n",ret);
	return 0;
}
