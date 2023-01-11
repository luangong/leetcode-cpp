/**
 * Edit Distance
 *
 * Given two words word1 and word2, find the minimum number of steps required to
 * convert word1 to word2.  (Each operation is counted as 1 step.)
 *
 * You have the following 3 operations permitted on a word:
 *
 *    a) Insert a character
 *    b) Delete a character
 *    c) Replace a character
 *
 * Tags: Dynamic Programming, String
 */
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int minDistance(string src, string dest) {
        vector<vector<int>> dist(src.size()+1, vector<int>(dest.size()+1));
        for (int j = 0; j <= dest.size(); ++j)
            dist[0][j] = j;
        for (int i = 0; i <= src.size(); ++i)
            dist[i][0] = i;
        for (int i = 1; i <= src.size(); ++i) {
            for (int j = 1; j <= dest.size(); ++j) {
                if (src[i-1] == dest[j-1])
                    dist[i][j] = dist[i-1][j-1];
                else
                    dist[i][j] = min(dist[i-1][j-1],    // replace src[i] with dest[j]
                                 min(dist[i-1][j],      // delete src[i]
                                     dist[i][j-1]))     // append dest[j] to src
                               + 1;
            }
        }
        return dist[src.size()][dest.size()];
    }

    /**
     * 空间优化版本，只需要两个一维数组，空间复杂度为 O(n)
     */
    int minDistance(const string& src, const string& dest) {
        vector<int> prev(dest.size() + 1);
        for (int j = 0; j <= dest.size(); ++j)
            prev[j] = j;
        vector<int> curr(dest.size() + 1);
        for (int i = 1; i <= src.size(); ++i) {
            curr[0] = i;
            for (int j = 1; j <= dest.size(); ++j) {
                if (src[i-1] == dest[j-1])
                    curr[j] = prev[j-1];
                else
                    curr[j] = 1 + min(prev[j-1], min(prev[j], curr[j-1]));
            }
            prev.swap(curr);
        }
        return prev[dest.size()];
    }

    int minDistance(const string& word1, const string& word2) {
        vector<vector<int>> dist(2, vector<int>(word2.size()+1));
        for (int j = 0; j <= word2.size(); ++j)
            dist[0][j] = j;
        for (int i = 1; i <= word1.size(); ++i) {
            dist[i%2][0] = i;
            for (int j = 1; j <= word2.size(); ++j)
                if (word1[i-1] == word2[j-1])
                    dist[i%2][j] = dist[(i-1)%2][j-1];
                else
                    dist[i%2][j] = 1 + min(dist[(i-1)%2][j-1], min(dist[i%2][j-1], dist[(i-1)%2][j]));
        }
        return dist[word1.size()%2][word2.size()];
    }
};
