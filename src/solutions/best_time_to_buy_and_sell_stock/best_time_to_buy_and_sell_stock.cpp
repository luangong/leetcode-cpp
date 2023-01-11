/**
 * Best Time to Buy and Sell Stock
 *
 * Say you have an array for which the i-th element is the price of a given
 * stock on day i.
 *
 * If you were only permitted to complete at most one transaction (i.e., buy one
 * and sell one share of the stock), design an algorithm to find the maximum
 * profit.
 *
 * Tags: Array, Dynamic Programming
 */

class Solution {
public:
    /*
     * 假设在第 i 天买入，第 j 天卖出 (0 <= i < j < n)，则收益为 p[j] - p[i]，
     * 现在考虑每日的股票价格与前一天的价格之差，即 d[i] = p[i] - p[i-1]，并且
     * 规定 d[0] = 0，那么就有
     *
     *     p[j] - p[i] = (p[i+1] - p[i]) + ... + (p[j] - p[j-1])
     *                 = d[i+1] + ... + d[j]
     *
     * 即原问题可转化为求数组 d 的最大子段和，这可以用动态规划算法在 O(n) 时间
     * 内
     * 解决
     */
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        int profit = 0;
        for (int i = 1; i < prices.size(); ++i) {
            int delta = prices[i] - prices[i-1];
            profit = max(delta, profit + delta);
            max_profit = max(max_profit, profit);
        }
        return max_profit;
    }

    /*
     * 先计算出在第 i 天卖出的情况下所能获得的最大收益，然后再求所有情况下的最
     * 大值。这就要求维护一个第 i 天之前的最小股票价格，那么第 i 天卖出所能获得
     * 的最大收益就是当天的股票价格减去之前的最小价格 prices[i] - min_price
     */
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) return 0;
        int max_profit = 0;
        int min_price = prices[0];
        for (int i = 1; i < prices.size(); ++i) {
            max_profit = max(max_profit, prices[i] - min_price);
            min_price = min(min_price, prices[i]);
        }
        return max_profit;
    }

    /*
     * 先计算出在第 i 天买入的情况下所能获得的最大收益，然后再求所有情况下的最
     * 大值。这就要求维护一个第 i 天之后的最大股票价格，那么第 i 天买入所能获得
     * 的最大收益就是那个最大价格减去当天的股票价格 max_price - prices[i]
     */
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) return 0;
        int max_profit = 0;
        int max_price = prices.back();
        for (int i = prices.size()-2; i >= 0; --i) {
            max_profit = max(max_profit, max_price - prices[i]);
            max_price = max(max_price, prices[i]);
        }
        return max_profit;
    }
};
