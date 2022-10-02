#include <iostream>
#include <stack>
#include <algorithm>
#include <math.h>
#include <vector>
#include <unordered_map>
using namespace std;


int maxWater(int arr[], int n)
{
    // To store the maximum water
    // that can be stored
    int res = 0;
 
    // For every element of the array
    for (int i = 1; i < n - 1; i++) {
 
        // Find the maximum element on its left
        int left = arr[i];
        for (int j = 0; j < i; j++)
            left = max(left, arr[j]);
 
        // Find the maximum element on its right
        int right = arr[i];
        for (int j = i + 1; j < n; j++)
            right = max(right, arr[j]);
 
        // Update the maximum water
        res = res + (min(left, right) - arr[i]);
    }
 
    return res;
}


int maxProfit(int price[], int start, int end)
{
 
    // If the stocks can't be bought
    if (end <= start)
        return 0;
 
    // Initialise the profit
    int profit = 0;
 
    // The day at which the stock
    // must be bought
    for (int i = start; i < end; i++) {
 
        // The day at which the
        // stock must be sold
        for (int j = i + 1; j <= end; j++) {
 
            // If buying the stock at ith day and
            // selling it at jth day is profitable
            if (price[j] > price[i]) {
 
                // Update the current profit
                int curr_profit
                    = price[j] - price[i]
                      + maxProfit(price, start, i - 1)
                      + maxProfit(price, j + 1, end);
 
                // Update the maximum profit so far
                profit = max(profit, curr_profit);
            }
        }
    }
    return profit;
}

int main()
{
	int arr[5]={1,2,3,4,5};
	return 0;
}
