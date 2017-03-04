#include <stdlib.h>
#include <stdio.h>



typedef struct {
	unsigned int	numSize;
	int*		nums;
	int*		dat;
} NumArray;



NumArray* numArrayCreate(int* nums, int numsSize) {
	
	int loop = 0;
	NumArray* p_array = NULL;
	
	if (0 >= numsSize ||(NULL == nums))
	{
		return NULL;
	}
	
	p_array = (NumArray*)malloc(sizeof(NumArray));
	
	if (NULL == p_array)
	{
		return NULL;
	} 	

	p_array->numSize = numsSize;
	p_array->nums = (int*)malloc(numsSize*sizeof(int));
	
	if (NULL == p_array->nums)
	{
		return NULL;
	}
	
	for (loop = 0;loop < numsSize;loop ++)
	{
		p_array->nums[loop] = nums[loop];		
	}
	
	p_array->dat = (int*)malloc(numsSize * sizeof(int));
	
	if (NULL == p_array->dat)
	{
		return NULL;
	}

	for(loop = 0;loop < numsSize;loop ++)
	{
		if (0 == loop)
		{
			p_array->dat[loop] = p_array->nums[loop];
		}
		else
		{
			p_array->dat[loop] = p_array->dat[loop-1] + p_array->nums[loop];
		}
	}
		
	return p_array;
}

int numArraySumRange(NumArray* obj, int i, int j) {
	
	if (NULL == obj)
	{
		return 0;
	}

	if (j < i)
	{
		return 0;
	}

	if (j > obj->numSize)
	{
		return 0;
	}	

	if (i < 0 || j < 0)
	{
		return 0;
	}
	return obj->dat[j] - obj->dat[i] + obj->nums[i];
}

void numArrayFree(NumArray* obj) {
	
	if (NULL == obj)
		return;
	free(obj->nums);
	free(obj->dat);
	free(obj);
}

/**
 * Your NumArray struct will be instantiated and called as such:
 * struct NumArray* obj = numArrayCreate(nums, numsSize);
 * int param_1 = numArraySumRange(obj, i, j);
 * numArrayFree(obj);
 */

int main(int argc, char* argv[])
{
	int arg0,arg1 = 0;
	int num[] = {-2,0,3,-5,2,-1};

	arg0 = atoi(argv[1]);
	arg1 = atoi(argv[2]);

	NumArray* obj = numArrayCreate(num,6);
	printf("#TEST:numSize = %d, arg0=%d, arg1=%d\n",obj->numSize, arg0, arg1);
	printf("#RES:%d\n",numArraySumRange(obj,arg0,arg1));
	numArrayFree(obj);
}
