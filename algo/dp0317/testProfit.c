#include <stdio.h>
#include <stdlib.h>





int maxProfit(int* prices, int pricesSize) {
	int loop = 0;
	int inPrice = 0;
	int tempProfit = 0;
	int saleProfit = 0;
	

	if (NULL == prices || 0 > pricesSize)
	{
		return 0;
	}
	
	inPrice = prices[0];

	for (loop=0; loop < pricesSize; loop ++)
	{
		if(inPrice >= prices[loop])
		{
			inPrice = prices[loop];
		}

		tempProfit = prices[loop] - inPrice;
		
		saleProfit = (saleProfit > tempProfit)? saleProfit:tempProfit;
	}
	return saleProfit;
}

int main(int argc, char* argv[])
{
	int testData[] = {7, 6, 4, 3, 1};

	printf("#TestResult:%d\n", maxProfit(testData,sizeof(testData)/sizeof(int)));
}
