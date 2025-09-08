class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        for (int k = 1; k <= 60; ++k) {
            long long diff = num1 - 1LL * num2 * k;
            if (diff < k) continue;
            int bits = __builtin_popcountll(diff);
            if (bits <= k && k <= diff) {
                return k;
            }
        }
        return -1;
    }
};