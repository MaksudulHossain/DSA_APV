#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        for (int i = 0; i < prices.size()-1; i++)
        {
            for (int j = i; j < prices.size(); j++)
            {
                if(prices[i]<prices[j]){
                    int profit = prices[i] - prices[j];
                    if(profit > max_profit) max_profit = profit;
                }
            }
            
        }
        return max_profit;
        
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        for (int i = 0; i < prices.size()-1; i++)
        {
            if(prices[i]<prices[i+1]){
                int profit = prices[i] - prices[i+1];
                if(profit > max_profit) max_profit = profit;
            }

            
        }
        return max_profit;
        
    }
};
