// BRUTE FORCE APPROACH
// class Solution {
// public:
//     bool isprime(int n) {
//         if (n < 2)
//             return false;
//         for (int i = 2; i * i <= n; i++) {
//             if (n % i == 0)
//                 return false;
//         }
//         return true;
//     }
//     int countPrimes(int n) {
//         int count = 0;
//         for (int i = 2; i < n; i++) {
//             if (isprime(i)) {
//                 count++;
//             }
//         }
//         return count;
//     }
// };

// Sieve of Eratosthenes & OPTIMISED APPROACH

class Solution {
public:
    int countPrimes(int n) {
        if (n <= 1)
            return 0;
        vector<bool> isprime(n, true);
        isprime[0] = isprime[1] = false;

        for (int i = 2; i * i < n; i++) {
            if (isprime[i]) {
                for (int j = i * i; j < n; j += i) {
                    isprime[j] = false;
                }
            }
        }

        int count = 0;
        for (int i = 2; i < n; i++) {
            if (isprime[i]) {
                count++;
            }
        }
        return count;
    }
};