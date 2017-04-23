#include <stdio.h>
#include <stdlib.h>


void register_atom_group(int **tab, int n);
int getMoneyAmount(int n);
void sub_grouping(int** dat, int start, int length, int end);


int main(int argc, char* argv[])
{
	int param = atoi(argv[1]);
	printf("#RESULT = %d\n", getMoneyAmount(param));
}


int getMoneyAmount(int n)
{
	int loop = 0;
	int ret = 0;
	int **dat = (int**)malloc((n+1) * sizeof(int*));
	for (loop = 0;loop <= n; loop++)
	{
		dat[loop] = (int*)malloc((n+1) * sizeof(int));
	}
	register_atom_group(dat, n);
	
	for (loop = 3; loop <= n; loop++)
	{// length from 3 to maximum
		sub_grouping(dat, 1, loop, n);
	}
	ret = dat[1][n];
	for (loop = 0;loop <= n; loop++)
	{
		free(dat[loop]);
	}
	free(dat);
	return ret;
}

void core_grouping(int **dat, int start, int end)
{
	int loop = 0;
	int cost_left = 0;
	int cost_right = 0;
	int tmp_cost = 0;
	int min = 65535;
	for (loop = start; loop <= end; loop ++)
	{
//		printf("#TEST left preparing costl= %d, start=%d pleft=%d\n",cost_left, start, loop);
		if (start == loop)
		{
			cost_left = dat[start][loop];
		}
		else
		{
			cost_left = dat[start][loop-1];
		}
//		printf("#TEST right preparing costr = %d, pright=%d end=%d\n",cost_right,loop+1, end);
		if (loop < end)
		{
			cost_right= dat[loop+1][end];
		}
		else
		{
			cost_right = dat[loop][end];
		}
//		printf("costl = %d, costr=%d\n",cost_left,cost_right);
		tmp_cost = (cost_left > cost_right?cost_left:cost_right) + loop;
		min = (tmp_cost < min) ? tmp_cost : min;
		printf("#TEST special pivot = %d, left = %d, right = %d, min = %d\n", loop,start,end,min);
		
//		printf("#TEST conclusion: left = %d right=%d min = %d\n\n", cost_left, cost_right, min);	
	}
	dat[start][end] = min;
	printf("#TEST core grouping start = %d, end = %d, min=%d\n", start, end, min);
}


void sub_grouping(int** dat, int start, int length, int end)
{
	int loop = 0;
	int times = end - start - length + 2;
		
	printf("#TEST:subgroup length = %d, times=%d, start = %d, end=%d\n", length, times, start, end);
	
	for (; loop < times; loop ++)
	{
		printf("*****************#TEST EXEC coreGrp start = %d, end = %d, length = %d******************\n",start+loop, start+loop+length-1,length);
		core_grouping(dat, start + loop, start + loop + length-1);	
		printf("\a\a\a\a\a\n");
	}
}

void register_atom_group(int **tab, int n)
{
	int loop = 1;
	for (;loop <= n;loop ++)
	{
		tab[loop][loop] = 0;
	}

	for (loop = 1; loop < n;loop ++)
	{
		tab[loop][loop+1] = loop;
		printf("#TEST tab[%d][%d]=%d\n", loop, loop+1, loop);
	}
}


