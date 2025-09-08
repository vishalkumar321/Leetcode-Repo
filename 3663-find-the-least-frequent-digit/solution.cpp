class Solution {
public:
    int getLeastFrequentDigit(int n) {
        unordered_map<int, int> mp;

        if (n == 0)
            mp[0]++;
        while (n > 0) {
            int L_digit = n % 10;
            mp[L_digit]++;
            n = n / 10;
        }

        int minFreq = INT_MAX;
        int ans = 9;
        for (auto [digit, count] : mp) {
            if (minFreq > count || (count == minFreq && digit < ans)) {
                minFreq = count;
                ans = digit;
            }
        }
        return ans;
    }
};