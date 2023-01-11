/*
 * Merge Intervals
 *
 * Given a collection of intervals, merge all overlapping intervals.
 *
 * For example,
 * Given [1,3],[2,6],[8,10],[15,18],
 * return [1,6],[8,10],[15,18].
 *
 * Tags: Array, Sort
 */

#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

// Definition for an interval.
struct Interval {
  int start;
  int end;
  Interval() : start(0), end(0) {}
  Interval(int s, int e) : start(s), end(e) {}
};

bool operator <(const Interval& lhs, const Interval& rhs) {
  return lhs.start < rhs.start;
}

class Solution {
 public:
  vector<Interval> merge(vector<Interval> &intervals) {
    vector<Interval> result;
    if (intervals.empty()) return result;
    sort(intervals.begin(), intervals.end());
    Interval lastInterval = intervals[0];
    for (int i = 1; i < intervals.size(); ++i) {
      // 如果当前 interval 与前一个 interval 交叠，则合并他们，否则输出前一个 interval
      if (intervals[i].start <= lastInterval.end) {
        lastInterval.start = min(lastInterval.start, intervals[i].start);
        lastInterval.end = max(lastInterval.end, intervals[i].end);
      } else {
        result.push_back(lastInterval);
        lastInterval = intervals[i];
      }
    }
    result.push_back(lastInterval);
    return result;
  }
};


int main(int argc, char **argv) {
    string line;
    while (getline(cin, line)) {
        istringstream iss(line);
        int start, end;
        vector<Interval> intervals;
        while (iss >> start >> end)
            intervals.push_back(Interval(start, end));
        auto mergedIntervals = Solution().merge(intervals);
        for (Interval interval : mergedIntervals)
            cout << "(" << interval.start << ", " << interval.end << ") ";
        cout << endl;
    }
    return 0;
}
