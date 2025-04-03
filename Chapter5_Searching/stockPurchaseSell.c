#include <stdio.h>
#include <stdlib.h>

void BruteForce(int* arr, int size)
{
    int buy;
    int sell;
    int maxProfit = 0;

    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] - arr[i] > maxProfit)
            {
                maxProfit = arr[j] - arr[i];
                buy = i;
                sell = j;
            }
        }
    }

    printf("Buy: %d | Sell: %d | Profit: %d\n", arr[buy], arr[sell], maxProfit);
}

void maxProfit(int* stocks, int size)
{
    int buy = 0, sell = 0;
    int curMin = 0;
    int currProfit = 0;
    int maxProfit = 0;
    
    for (int i = 0; i < size; i++)
    {
        if (stocks[i] < stocks[curMin])
            curMin = i;
        
        currProfit = stocks[i] - stocks[curMin];

        if (currProfit > maxProfit)
        {
            buy = curMin;
            sell = i;
            maxProfit = currProfit;
        }
    }
    printf("\nPurchase day is- %d at price %d", buy, stocks[buy]);
    printf("\nSell day is- %d at price %d", sell, stocks[sell]);
}

int main()
{
    int arr[20];

    for (int i = 0; i < 20; i++)
    {
        arr[i] = rand() % 7 + 5;
    }

    //BruteForce(arr, 20);
    maxProfit(arr, 20);
}