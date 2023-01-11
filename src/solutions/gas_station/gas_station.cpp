/**
 * Gas Station
 *
 * There are N gas stations along a circular route, where the amount of gas at
 * station i is gas[i].
 *
 * You have a car with an unlimited gas tank and it costs cost[i] of gas to
 * travel from station i to its next station (i+1).  You begin the journey with
 * an empty tank at one of the gas stations.
 *
 * Return the starting gas station's index if you can travel around the circuit
 * once, otherwise return -1.
 *
 * Note: The solution is guaranteed to be unique.
 *
 * Tags: Greedy
 */

class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int current_remainder = 0;
        int overall_remainder = 0;
        int next_start = 0;
        for (int i = 0; i < gas.size(); ++i) {
            current_remainder += gas[i] - cost[i];
            overall_remainder += gas[i] - cost[i];
            if (current_remainder < 0) {
                current_remainder = 0;
                next_start = i+1;
            }
        }
        return overall_remainder >= 0 ? next_start : -1;
    }
};
