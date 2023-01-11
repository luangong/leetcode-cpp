/**
 * Next Permutation
 *
 * Implement next permutation, which rearranges numbers into the
 * lexicographically next greater permutation of numbers.
 *
 * If such arrangement is not possible, it must rearrange it as the lowest
 * possible order (i.e., sorted in ascending order).
 *
 * The replacement must be in-place, do not allocate extra memory.
 *
 * Here are some examples.  Inputs are in the left-hand column and its
 * corresponding outputs are in the right-hand column.
 *
 *    1 2 3 --> 1 3 2
 *    3 2 1 --> 1 2 3
 *    1 1 5 --> 1 5 1
 *
 * Tags: Array
 */
#include <iostream>
#include <sstream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& numbers) {
        /* 先从右往左找到第一个比右边小的元素 */
        int i = numbers.size()-2;
        while (i >= 0 && numbers[i] >= numbers[i+1])
            --i;
        /*
         * 如果整个序列都是递减排列的，说明该序列已经是字典序最大，
         * 则直接把整个序列逆转，变成字典序最小
         */
        if (i < 0) {
            reverse(numbers.begin(), numbers.end());
            return;
        }

        /* 在第 i 个元素右边找到比 numbers[i] 大的最小的数，跟 numbers[i] 交换 */
        int j = numbers.size()-1;
        while (numbers[j] <= numbers[i])
            --j;
        swap(numbers[i], numbers[j]);

        /*
         * 最后把第 i 个元素右边的所有元素都逆序（变成字典序最小），
         * 整个过程的效果相当于把最右边最大的字典序向左边进了一位，
         * 同时右边变成最小的字典序（类似于 1999 + 1 = 2000）
         */
        reverse(numbers.begin()+i+1, numbers.end());
    }

    bool prev_permutation(vector<int>& numbers) {
        int i = numbers.size() - 2;
        while (i >= 0 && numbers[i] <= numbers[i+1]) {
            --i;
        }
        if (i < 0) {
            reverse(numbers.begin(), numbers.end());
            return false;
        }
        int j = numbers.size() - 1;
        while (numbers[j] >= numbers[i]) {
            --j;
        }
        swap(numbers[i], numbers[j]);
        reverse(numbers.begin()+i+1, numbers.end());
        return true;
    }
};

int main(int argc, char **argv) {
    string line;
    while (getline(cin, line)) {
        // Read data
        istringstream iss(line);
        vector<int> vec((istream_iterator<int>(iss)), istream_iterator<int>());
        // Sort
        sort(vec.begin(), vec.end());
        // Next permutation
        do {
            copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, " "));
            cout << endl;
        } while (Solution().nextPermutation(vec));

        cout << "------------------------" << endl;
        reverse(vec.begin(), vec.end());

        // Previous permutation
        do {
            copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, " "));
            cout << endl;
        } while (Solution().prev_permutation(vec));
    }
    return 0;
}
