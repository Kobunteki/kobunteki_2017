#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int minDistance_DP(char* word1, char* word2){
	
	int len1 = 0;
	int len2 = 0;
	int loop = 0;
	int loop2= 0;
	int dis0 = 0;
	int dis1 = 0;
	int ret  = 0;
	int **dp = NULL;

	if (NULL == word1 || NULL == word2)
	{
		return 0;
	}

	len1 = strlen(word1);
	len2 = strlen(word2);

	if (0 == len1)
	{
		return len2;
	}
	
	if (0 == len2)
	{
		return len1;
	}
	

	dp = (int**)malloc((len1+1)*sizeof(int*));
	if (NULL == dp)
	{
		printf("#FAILURE:malloc FAILURE\n");
		return 0;
	}

	for (loop = 0;loop <= len1;loop ++)
	{
		dp[loop] = (int*)malloc((len2+1)*sizeof(int));
		if (NULL == dp[loop])
		{
			printf("#FAILURE:malloc FAILURE\n");
			return 0;
		}
		
	}

	for (loop = 0;loop <= len1;loop ++)
	{
		dp[loop][0] = loop;
	}	

	for (loop = 0;loop <= len2;loop ++)
	{
		dp[0][loop] = loop;
	}

	for (loop = 1;loop <= len1;loop ++)
	{
		for (loop2 = 1;loop2 <= len2;loop2 ++)
		{
			dis0 = (dp[loop-1][loop2] < dp[loop][loop2-1]) ? (dp[loop-1][loop2]+1):(dp[loop][loop2-1]+1);
			dis1 = dp[loop-1][loop2-1];
		
			printf("#FORE:dis_insert_delete = %d, dis_replace = %d\n", dis0, dis1);
			if (word1[loop-1] == word2[loop2-1])
			{
				dp[loop][loop2] = dis1;
			}
			else
			{
				dp[loop][loop2] = dis1+1;
			}

			if (dp[loop][loop2] > dis0)
			{
				dp[loop][loop2] = dis0;
			}
			printf("#RUN:dp[%d][%d] = %d,chA=\'%d\', chB=\'%d\'\n\n",loop,loop2,dp[loop][loop2],word1[loop],word2[loop2]);
		}
	}

	ret = dp[len1][len2];
	for (loop = 0;loop < len1;loop ++)
	{
		free(dp[loop]);
	}
	free(dp);
	return ret;	
}


int minDistance(char* word1, char* word2) {
	return minDistance_DP(word1,word2);
}

int main(int argc, char* argv[])
{
	int ret = 0;
	ret = minDistance(argv[1],argv[2]);
	printf("The result is %d\n", ret);
}
