/**
 * Best Time to Buy and Sell Stock II
 *
 * Say you have an array for which the i-th element is the price of a given
 * stock on day i.
 *
 * Design an algorithm to find the maximum profit.  You may complete as many
 * transactions as you like (i.e., buy one and sell one share of the stock
 * multiple times).  However, you may not engage in multiple transactions at the
 * same time (i.e., you must sell the stock before you buy again).
 *
 * Tags: Array, Greedy
 */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // 计算每天的股票价格与前一天的价格之差，如果大于零就进行交易（累加）
        int profit = 0;
        for (int i = 1; i < prices.size(); ++i)
            if (prices[i] > prices[i-1])
                profit += prices[i] - prices[i-1];
        return profit;
    }
};
