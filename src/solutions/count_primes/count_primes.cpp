/*
 * Count Primes
 *
 * Count the number of prime numbers less than a non-negative number, n
 *
 * References:
 *
 *   - How Many Primes Are There? (https://primes.utm.edu/howmany.html)
 *   - Sieve of Eratosthenes (http://en.wikipedia.org/wiki/Sieve_of_Eratosthenes)
 *
 * Credits: Special thanks to @mithmatt for adding this problem and creating all
 * test cases.
 *
 * Tags: Hash Table, Math
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int countPrimes1(int n) {
        if (n == 1) return 0;
        vector<bool> primes(n, true);
        primes[0] = primes[1] = false;
        int p = 2;
        while (p < n) {
            while (p < n && !primes[p])
                ++p;
            if (p >= n) break;
            int multiple = 2 * p;
            while (multiple < n) {
                primes[multiple] = false;
                multiple += p;
            }
            ++p;
        }
        return count(primes.begin(), primes.end(), true);
    }

    size_t nextPrime(size_t p, const vector<bool> &primes) {
        while (p < primes.size() && !primes[p])
            p += 2;
        return p;
    }

    void filter(vector<bool> &primes, size_t p) {
        size_t multiple = p * p;
        while (multiple < primes.size()) {
            primes[multiple] = false;
            multiple += p;
        }
    }

    int countPrimes(int n) {
        if (n == 1) return 0;
        vector<bool> primes(n, true);
        primes[0] = primes[1] = false;
        filter(primes, 2);
        size_t p = 3;
        while (p * p < n) {
            while (p * p < n && !primes[p])
                p += 2;
            if (p * p >= n) break;
            filter(primes, p);
            p += 2;
        }
        return count(primes.begin(), primes.end(), true);
    }
};

int main(int argc, char **argv) {
    int n;
    while (cin >> n)
        cout << Solution().countPrimes(n) << endl;
    return 0;
}
