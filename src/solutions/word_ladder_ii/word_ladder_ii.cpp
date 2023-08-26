/**
 * Word Ladder II
 *
 * Given two words (start and end), and a dictionary, find all shortest
 * transformation sequence(s) from start to end, such that:
 *
 *    - Only one letter can be changed at a time
 *    - Each intermediate word must exist in the dictionary
 *
 * For example, given:
 *
 *    start = "hit"
 *    end   = "cog"
 *    dict  = ["hot","dot","dog","lot","log"]
 *
 * Return
 *
 *   [
 *     ["hit","hot","dot","dog","cog"],
 *     ["hit","hot","lot","log","cog"]
 *   ]
 *
 * Tags: Array, Backtracking, Breadth-first Search, String
 */
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <iterator>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> findLadders(const string& source,
                                       const string& target,
                                       unordered_set<string>& dict) {
        vector<vector<string>> ladders;
        unordered_map<string, vector<string>> parents;
        unordered_set<string> visited;      // 用来标记某个顶点是否已访问过
        visited.insert(source);
        unordered_map<string, int> dist;    // 顶点到源顶点的距离
        dist[source] = 0;

        queue<string> Q;
        Q.push(source);
        while (!Q.empty()) {
            auto numNodesInCurrLevel = Q.size();
            while (numNodesInCurrLevel-- > 0) {
                string word = Q.front();
                Q.pop();
                // cout << word << ' ';
                // 依次检查与当前字符串距离为 1 的字符串
                for (int i = 0; i < word.size(); ++i) {
                    string neighbor(word);
                    for (char c = 'a'; c <= 'z'; ++c) {
                        if (c == word[i]) continue;
                        neighbor[i] = c;
                        if (neighbor == target) {
                            parents[target].push_back(word);
                            continue;
                        }
                        // 访问所有未被访问过的 word 的邻居
                        if (dict.find(neighbor) != dict.end()) {
                            if (visited.find(neighbor) == visited.end() || dist[neighbor] == dist[word] + 1)
                                // Mark word as parent of neighbor
                                parents[neighbor].push_back(word);
                            if (visited.find(neighbor) == visited.end()) {
                                dist[neighbor] = dist[word] + 1;
                                Q.push(neighbor);
                                visited.insert(neighbor);
                            }
                        }
                    }
                }
            }
            // cout << endl;
            if (!(parents[target].empty())) {
                vector<string> ladder;
                // cout << "--- ";
                // copy(parents[target].begin(), parents[target].end(), ostream_iterator<string>(cout, " "));
                // cout << "--" << endl;
                backtrack(source, target, parents, ladder, ladders);
                return ladders;
            }
        }
        return ladders;
    }

    void backtrack(const string& source,
                   const string& curr,
                   unordered_map<string, vector<string>>& parents,
                   vector<string>& ladder,
                   vector<vector<string>>& ladders) {
        ladder.push_back(curr);
        if (parents[curr].empty()) {
            // cout << "--> ";
            // copy(ladder.rbegin(), ladder.rend(), ostream_iterator<string>(cout, " "));
            // cout << "-->" << endl;
            reverse(ladder.begin(), ladder.end());
            ladders.push_back(ladder);
            reverse(ladder.begin(), ladder.end());
            ladder.pop_back();
            return;
        }
        for (const auto& parent : parents[curr])
            backtrack(source, parent, parents, ladder, ladders);
        ladder.pop_back();
    }

    typedef unordered_multimap<string, string> Map;
    typedef pair<Map::iterator, Map::iterator> PairIter;

    vector<vector<string>> findLadders2(string start,
                                       string end,
                                       unordered_set<string>& dict) {
        Map map, parents;
        queue<string> q, q2;
        q.push(start);
        bool goal = false;
        while (!q.empty()) {
            string word = q.front();
            q.pop();
            for (int i = 0; i < start.length(); i++) {
                string s = word;
                for (char c = 'a'; c <= 'z'; c++) {
                    s[i] = c;
                    if (s == word)
                        continue;
                    if (s == end)
                        goal = true;
                    if (map.find(s) == map.end() && dict.find(s) != dict.end()) {
                        if (parents.find(s) == parents.end())
                            q2.push(s);
                        parents.insert(make_pair(s, word));
                    }
                }
            }
            if (q.empty()) {
                swap(q, q2);
                map.insert(parents.begin(), parents.end());
                parents.clear();
                if (goal)
                    return print(map, end, start);
            }
        }
        return vector<vector<string>>();
    }

    // backtrack to reconstruct the path from start -> end.
    vector<vector<string>> print(Map &map, string s, string start, int depth = 0) {
        if (depth > 0 && s == start)
            return vector<vector<string>>(1, vector<string>(1, s));
        vector<vector<string>> ret;
        for (PairIter it = map.equal_range(s); it.first != it.second; ++it.first) {
            vector<vector<string>> temp = print(map, it.first->second, start, depth + 1);
            for (int i = 0; i < temp.size(); i++)
                temp[i].push_back(s);
            ret.insert(ret.end(), temp.begin(), temp.end());
        }
        return ret;
    }
};

int main(int argc, char **argv) {
    Solution sln;
    string source, target;
    while (cin >> source >> target) {
        cin.get();
        string line;
        getline(cin, line);
        istringstream iss(line);
        unordered_set<string> dict;
        string word;
        while (iss >> word)
            dict.insert(word);
        auto ladders = sln.findLadders(source, target, dict);
        for (const auto& ladder : ladders) {
            copy(ladder.begin(), ladder.end(), ostream_iterator<string>(cout, " "));
            cout << endl;
        }
    }
    return 0;
}
