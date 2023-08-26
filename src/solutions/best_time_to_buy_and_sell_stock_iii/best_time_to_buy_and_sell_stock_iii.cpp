/**
 * Best Time to Buy and Sell Stock III
 *
 * Say you have an array for which the ith element is the price of a given stock
 * on day i.
 *
 * Design an algorithm to find the maximum profit.  You may complete at most two
 * transactions.
 *
 * Note: You may not engage in multiple transactions at the same time (i.e., you
 * must sell the stock before you buy again).
 *
 * Tags: Array, Dynamic Programming
 */
#include <iostream>
#include <sstream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;

        // 先计算出每天的股票价格与前一天价格之差
        vector<int> diff(prices.size());
        for (int i = 1; i < prices.size(); ++i)
            diff[i] = prices[i] - prices[i-1];

        // left[i] 表示以 diff[i] 为末尾元素的最大子段和
        vector<int> left(diff.size());
        for (int i = 1; i < left.size(); ++i)
            left[i] = max(left[i-1] + diff[i], diff[i]);

        // 下面的循环使得 left[i] 表示分别以 diff[0], ..., diff[i] 为末尾
        // 元素的最大子段和的最大值，即子序列 diff[0], ..., diff[i] 的最大
        // 子段和
        for (int i = 1; i < left.size(); ++i)
            left[i] = max(left[i-1], left[i]);

        // right[i] 表示以 diff[i] 为起始元素的最大子段和
        vector<int> right(diff.size());
        right.back() = diff.back();
        for (int i = diff.size()-2; i >= 0; --i)
            right[i] = max(right[i+1] + diff[i], diff[i]);

        // 下面的循环使得 right[i] 表示分别以 diff[i], ..., diff[n-1] 为末尾
        // 元素的最大子段和的最大值，即子序列 diff[i], ..., diff[n-1] 的最大
        // 子段和
        for (int i = diff.size()-2; i >= 0; --i)
            right[i] = max(right[i], right[i+1]);

        // 枚举 i，计算所有左右两个最大字段和加起来的最大值
        int mp = 0;
        for (int i = 1; i < diff.size(); ++i)
            mp = max(mp, left[i-1] + right[i]);
        return mp;
    }

    int maxProfit(const vector<int>& prices) {
        int n = prices.size();
        if (n < 2) return 0;

        int min_price = prices[0];
        vector<int> left_max(n);
        for (int i = 1; i < n; ++i) {
            min_price = min(min_price, prices[i]);
            left_max[i] = max(left_max[i-1], prices[i] - min_price);
        }

        int max_price = prices[n-1];
        vector<int> right_max(n);
        for (int i = n-2; i >= 0; --i) {
            max_price = max(max_price, prices[i]);
            right_max[i] = max(right_max[i+1], max_price - prices[i]);
        }

        int max_profit = 0;
        for (int i = 0; i < n; ++i)
            max_profit = max(max_profit, left_max[i] + right_max[i]);
        return max_profit;
    }
};

int main(int argc, char **argv) {
    Solution sln;
    string line;
    while (getline(cin, line)) {
        istringstream iss(line);
        vector<int> prices((istream_iterator<int>(iss)), istream_iterator<int>());
        cout << sln.maxProfit(prices) << endl;
    }
    return 0;
}
