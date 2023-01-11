/**
 * Candy
 *
 * There are N children standing in a line. Each child is assigned a rating
 * value.
 *
 * You are giving candies to these children subjected to the following
 * requirements:
 *
 *    - Each child must have at least one candy.
 *    - Children with a higher rating get more candies than their neighbors.
 *
 * What is the minimum candies you must give?
 *
 * Tags: Greedy
 */

class Solution {
public:
    int candy(vector<int> &ratings) {
        vector<int> candies(ratings.size(), 1);
        for (int i = 1; i < ratings.size(); ++i)
            if (ratings[i] > ratings[i-1])
                candies[i] = candies[i-1] + 1;
        for (int i = ratings.size()-2; i >= 0; --i)
            if (ratings[i] > ratings[i+1] && candies[i] <= candies[i+1])
                candies[i] = candies[i+1] + 1;
        return accumulate(candies.begin(), candies.end(), 0);
    }
};
