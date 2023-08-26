/**
 * Simplify Path
 *
 * Given an absolute path for a file (Unix-style), simplify it.
 *
 * For example,
 *
 *    path = "/home/", => "/home"
 *    path = "/a/./b/../../c/", => "/c"
 *
 * Corner Cases:
 *
 *    - Did you consider the case where path = "/../"?
 *      In this case, you should return "/".
 *    - Another corner case is the path might contain multiple slashes '/'
 *      together, such as "/home//foo/".
 *      In this case, you should ignore redundant slashes and return "/home/foo".
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        if (path[path.size()-1] != '/')
            path += '/';
        vector<string> vec;
        string::size_type start = 1;
        string::size_type pos = 0;
        while ((pos = path.find('/', start)) != string::npos) {
            string fragment = path.substr(start, pos - start);
            start = pos + 1;
            if (fragment == "." || fragment == "")
                continue;
            if (!vec.empty()) {
                if (fragment == "..")
                    vec.pop_back();
                else if (fragment != vec.back())
                    vec.push_back(fragment);
            }
            else if (fragment != ".." && fragment != ".")
                vec.push_back(fragment);
        }
        string result;
        for (int i = 0; i < vec.size(); ++i)
            result = result + "/" + vec[i];
        return result == "" ? "/" : result;
    }
};

int main(int argc, char **argv) {
    Solution sln;
    string line;
    while (getline(cin, line)) {
        cout << sln.simplifyPath(line) << endl;
    }
    return 0;
}
