#include <iostream>

using namespace std;

class Solution {
public:
    int hammingWeight(int n) {
        int count = 0;
        for (int i = 0; i < 32; ++i)
            count += (n >> i) & 1;
        return count;
    }
    int hammingWeight(int n) {
        int count = 0;
        while (n != 0) {
            n &= n-1;
            ++count;
        }
        return count;
    }
};

int main(int argc, char **argv) {
    int n;
    while (cin >> n)
        cout << Solution().hammingWeight(n) << endl;
    return 0;
}
