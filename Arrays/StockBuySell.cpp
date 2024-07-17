//  Best Time to Buy and Sell Stock

class Solution {
public:

void maxProfitFind(vector<int>&prices,int i,int &minPrice, int &maxProfit){

        // base case
        if(i == prices.size()) return;

        //process part
        // find min price for buying stock

        if(prices[i]<minPrice) minPrice = prices[i];

        // calculate difference for max profit
        int todaysProfit = prices[i] - minPrice;
        // return max profit
        if(todaysProfit> maxProfit) maxProfit= todaysProfit;

        // recursive call
        maxProfitFind(prices, i+1, minPrice, maxProfit);
}
    int maxProfit(vector<int>& prices) {
int minPrice = INT_MAX;
int maxProfit = INT_MIN;
maxProfitFind(prices, 0,minPrice, maxProfit);
return maxProfit;
    }
};