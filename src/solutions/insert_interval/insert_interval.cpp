/*
 * Insert Interval
 *
 * Given a set of non-overlapping intervals, insert a new interval into the
 * intervals (merge if necessary).
 *
 * You may assume that the intervals were initially sorted according to their
 * start times.
 *
 * Example 1:
 * Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].
 *
 * Example 2:
 * Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as
 * [1,2],[3,10],[12,16].
 *
 * This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
 *
 * Tags: Array, Sort
 */
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

// Definition for an interval
struct Interval {
    int start;
    int end;
    Interval(int s = 0, int e = 0) : start(s), end(e) {}
};

class Solution {
public:
    vector<Interval> insert3(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> result;
        bool inserted = false;
        for (int i = 0; i < intervals.size(); ++i) {
            // 如果当前 interval 跟要插入的 interval overlap，则进行合并
            if (intervals[i].start <= newInterval.end && newInterval.start <= intervals[i].end) {
                newInterval.start = min(intervals[i].start, newInterval.start);
                newInterval.end = max(intervals[i].end, newInterval.end);
                continue;
            }

            // 如果新的 interval 还没有插入到 vector 中去并且当前 interval
            // 在新的 interval 之后，则把新的 interval 插入进去
            if (!inserted && intervals[i].start > newInterval.end) {
                result.push_back(newInterval);
                inserted = true;
            }

            // 把当前 interval 插入到 vector 中去
            result.push_back(intervals[i]);
        }

        // 如果新的 interval 还没被插入到 vector 中，说明新的 interval 跟最后
        // 一个 interval overlap 了或者在最后一个 interval 之后
        if (!inserted)
            result.push_back(newInterval);
        return result;
    }

    vector<Interval> insert2(vector<Interval>& intervals, Interval newInterval) {
        auto iter = intervals.begin();
        vector<Interval> result;
        // 把比 newInterval 小的区间直接放入结果
        for (; iter != intervals.end() && iter->end < newInterval.start; ++iter)
            result.push_back(*iter);

        // 如果全部 interval 都比 newInterval 小，那么把 newInterval 添加到末尾
        // 并返回
        if (iter == intervals.end()) {
            result.push_back(newInterval);
            return result;
        }

        // 否则，把与 newInterval overlap 的所有区间合并为一个区间并添加到末尾
        newInterval.start = min(newInterval.start, iter->start);
        for (; iter != intervals.end() && iter->start <= newInterval.end; ++iter)
            newInterval.end = max(newInterval.end, iter->end);
        result.push_back(newInterval);

        // 把剩余的比 newInterval 大的区间全部添加到 result 末尾
        result.insert(result.end(), iter, intervals.end());
        return result;
    }

    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> result;
        // 找到第一个与 newInterval overlap 的区间，那么 iter 左边的都是小于
        // newInterval 的区间，把他们直接添加到 result 尾部
        auto overlap_begin = find_if(intervals.begin(), intervals.end(),
                [&newInterval](const Interval& interval)
                    { return interval.end >= newInterval.start; });

        result.insert(result.end(), intervals.begin(), overlap_begin);

        // 找到第一个比 newInterval 大的区间
        auto overlap_end = find_if(overlap_begin, intervals.end(),
                [&newInterval](const Interval& interval)
                    { return interval.start > newInterval.end; });
        // 把与 newInterval overlap 的所有区间以及 newInterval 本身合并为一个
        // 区间并添加到末尾。
        // 注意：iter2 - 1 不适用于 singly-linked list，如果需要处理
        // singly-linked list，需要从 iter 一直循环到 iter2
        Interval mergedInterval(newInterval);
        if (overlap_begin != overlap_end) {
            mergedInterval.start = min(overlap_begin->start, newInterval.start);
            mergedInterval.end = max((overlap_end-1)->end, newInterval.end);
        }
        result.push_back(mergedInterval);

        // 把剩余的比 newInterval 大的区间全部添加到 result 末尾
        result.insert(result.end(), overlap_end, intervals.end());
        return result;
    }
};

int main(int argc, char **argv) {
    string line;
    while (getline(cin, line)) {
        istringstream iss(line);
        vector<Interval> intervals;
        int start, end;
        // Read the list of intervals
        while (iss >> start >> end)
            intervals.push_back(Interval(start, end));
        // Read the new interval
        getline(cin, line);
        iss.str(line);
        // Don't forget to reset the internal state of string stream
        iss.clear();
        iss >> start >> end;
        auto result = Solution().insert(intervals, Interval(start, end));
        for (const Interval& interval : result)
            cout << '(' << interval.start << ", " << interval.end << ") ";
        cout << endl;
    }
    return 0;
}
