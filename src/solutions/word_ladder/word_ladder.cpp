/**
 * Word Ladder
 *
 * Given two words (start and end), and a dictionary, find the length of
 * shortest transformation sequence from start to end, such that:
 *
 *    - Only one letter can be changed at a time
 *    - Each intermediate word must exist in the dictionary
 *
 * For example, Given:
 *
 *    start = "hit"
 *    end   = "cog"
 *    dict  = ["hot","dot","dog","lot","log"]
 *
 * As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
 * return its length 5.
 *
 * Note: Return 0 if there is no such transformation sequence.
 *
 * Tags: Breadth-first Search
 */
#include <iostream>
#include <sstream>
#include <string>
#include <queue>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<string> getNeighborWords(const string& word) {
        vector<string> neighbors;
        for (int i = 0; i < word.size(); ++i) {
            for (char c = 'a'; c <= 'z'; ++c) {
                if (word[i] != c)
                    neighbors.push_back(word.substr(0, i) + c + word.substr(i+1));
            }
        }
        return neighbors;
    }

    int ladderLength(const string& source, const string& target, unordered_set<string>& dict) {
        unordered_set<string> visited;
        int length = 1;
        queue<string> Q;
        Q.push(source);
        while (!Q.empty()) {
            ++length;
            int numNodesCurrLevel = Q.size();
            for (int i = 0; i < numNodesCurrLevel; ++i) {
                // Pop a string from the queue
                string word = Q.front();
                Q.pop();
                // For each string neighbor that is adjacent to word and has not
                // been visited, visit neighbor (push it to the back of the
                // queue)
                vector<string> neighbors = getNeighborWords(word);
                for (const string& neighbor : neighbors) {
                    if (neighbor == target)
                        return length;
                    if (visited.find(neighbor) == visited.end()
                            && dict.find(neighbor) != dict.end()) {
                        visited.insert(neighbor);
                        Q.push(neighbor);
                    }
                }
            }
        }
        return 0;
    }
};

int main(int argc, char **argv) {
    string line;
    while (getline(cin, line)) {
        istringstream iss(line);
        string start, end;
        iss >> start >> end;
        unordered_set<string> dict((istream_iterator<string>(iss)), istream_iterator<string>());
        cout << Solution().ladderLength(start, end, dict) << endl;
    }
}
