/**
 * Majority Element
 *
 * Given an array of size n, find the majority element.  The majority element is
 * the element that appears more than ⌊ n/2 ⌋ times.
 *
 * You may assume that the array is non-empty and the majority element always
 * exists in the array.
 *
 * Credits: Special thanks to @ts for adding this problem and creating all test
 * cases.
 *
 * Tags: Divide and Conquer, Array, Bit Manipulation
 */


class Solution {
public:
    int majorityElement(vector<int> &num) {
        sort(num.begin(), num.end());
        return num[num.size()/2];
    }

    int majorityElement(vector<int> num) {
        unordered_map<int, int> map;
        for (int x : num)
            map[x]++;
        for (int x : num)
            if (map[x] > num.size() / 2)
                return x;
        return 0;
    }

    int majorityElement(vector<int> num) {
        unordered_map<int, int> map;
        for (int x : num)
            if (++map[x] > num.size() / 2)
                return x;
        return 0;
    }

    int majorityElement(vector<int> &num) {
        int result = 0;
        for (int i = 0; i < 32; ++i) {
            int ones = 0, zeroes = 0;
            for (int j = 0; j < num.size(); ++j) {
                if (num[j] & (1 << i))
                    ++ones;
                else
                    ++zeroes;
            }
            if (ones > zeroes)
                result |= (1 << i);
        }
        return result;
    }

    int majorityElement(vector<int> &num) {
        int result = 0;
        for (int i = 0; i < 32; ++i) {
            int ones = 0;
            for (int j = 0; j < num.size(); ++j)
                if (num[j] & (1 << i))
                    ++ones;
            if (ones > num.size() / 2)
                result |= (1 << i);
        }
        return result;
    }
};
