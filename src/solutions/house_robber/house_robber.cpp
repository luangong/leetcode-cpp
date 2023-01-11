/*
 * House Robber
 *
 * You are a professional robber planning to rob houses along a street.  Each
 * house has a certain amount of money stashed, the only constraint stopping you
 * from robbing each of them is that adjacent houses have security system
 * connected and it will automatically contact the police if two adjacent houses
 * were broken into on the same night.
 *
 * Given a list of non-negative integers representing the amount of money of
 * each house, determine the maximum amount of money you can rob tonight without
 * alerting the police.
 *
 * Credits: Special thanks to @ifanchu for adding this problem and creating all
 * test cases.  Also thanks to @ts for adding additional test cases.
 *
 * Tags: Dynamic Programming
 */
class Solution {
public:
    int rob(vector<int> &num) {
        auto n = num.size();
        if (n == 0) return 0;
        if (n == 1) return num[0];
        vector<int> money(n, num[n-1]);
        money[n-2] = max(num[n-2], num[n-1]);
        for (int i = n-3; i >= 0; i--)
            money[i] = max(num[i] + money[i+2], money[i+1]);
        return money[0];
    }

    int rob(vector<int> &num) {
        auto n = num.size();
        if (n == 0) return 0;
        if (n == 1) return num[0];
        int z = num[n-1];
        int y = max(num[n-2], num[n-1]);
        for (auto i = n-3; i >= 0; --i) {
            int x = max(y, num[i] + z);
            z = y;
            y = x;
        }
        return y;
    }
};
