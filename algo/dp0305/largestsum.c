#include <stdio.h>
#include <stdlib.h>




int maxSubArray(int* nums, int numsSize) {
	
	int loop = 0;
	int *dat = NULL;
	int sum  = 0;
	int ret  = 0;	

	if (NULL == nums || numsSize <= 0)
	{
		return 0;
	}
	
	dat = (int*)malloc(numsSize * sizeof(int));
	if (NULL == dat)
	{
		return 0;	
	}
	
	for (loop = 0;loop < numsSize; loop ++)
	{
	
//		printf("#==============DBG:ITERATION START %d==============\n",loop);

		if (0 == loop)
		{
			ret = sum = dat[loop] = nums[loop];
		}
		else
		{
//			printf("sum = %d dat[loop-1] = %d\n nums[loop] = %d\n",sum, dat[loop-1],nums[loop]);
			if (nums[loop] >= 0)
			{
				dat[loop] =  (sum > 0) ? (sum + nums[loop]) : nums[loop];
				if (sum > 0)
				{
					dat[loop] = sum + nums[loop];		
					sum += nums[loop];
				}
				else
				{
					dat[loop] = nums[loop];
					sum = nums[loop];	
				}
//				printf("inner dat[loop] = %d sum = %d, nums[loop]=%d\n",dat[loop],sum,nums[loop]);
			}
			else if(nums[loop] >= sum)
			{
				dat[loop] = nums[loop];
				sum = nums[loop];
			}
			else
			{
				dat[loop] = dat[loop-1];
				sum += nums[loop];
			}
				

			ret = (dat[loop] > ret)?dat[loop]:ret;
//			printf("dat[loop] = %d\n",dat[loop]);
		}

//		printf("#==============DBG:ITERATION END  %d==============\n",loop);
	}
	
	free(dat);
	return ret;
}






int main(int argc, char* argv[])
{
//	int arg0 = atoi(argv[1]);
//	int testData[] = {-2,1,-3,4,-1,2,1,-5,4};
	int testData[] = {-2,-1};
//	int testData[] = {3,-1,9};
	printf("#TEST RES:%d\n", maxSubArray(testData, sizeof(testData)/sizeof(int)));
}
