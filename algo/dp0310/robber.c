#include <stdio.h>
#include <stdlib.h>





int rob(int* nums, int numsSize) {
	
	int* dp = NULL;
	int loop = 0;
	int temp = 0;

	if ((NULL == nums) || (numsSize <= 0))
	{
		return 0;
	}
   	
	dp = (int*)malloc(numsSize * sizeof(int));
	if (NULL == dp)
	{
		return 0;
	}

	dp[0] = nums[0];
	dp[1] = nums[1] > nums[0]? nums[1]:nums[0];

	for (loop=2;loop < numsSize;loop ++)
	{
		temp  = dp[loop-2] + nums[loop];
		dp[loop] = dp[loop-1];
		dp[loop] = dp[loop] > temp ? dp[loop]:temp;
//		printf("#TEST: dp[%d] = %d, num = %d\n", loop,dp[loop],nums[loop]);
	}

	temp = dp[numsSize-1];
	free(dp);
	return temp;
}


int main(int argc, char* argv[])
{
	int test[] = {0,2,4,1,2,4};
//	printf("#RES:%d\n",rob(test,sizeof(test)/sizeof(int)));
}

