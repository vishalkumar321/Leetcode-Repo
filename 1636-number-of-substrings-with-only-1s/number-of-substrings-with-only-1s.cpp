class Solution {
public:
    int numSub(string s) {

        int MOD = 1e9 + 7;
        long long currOnes = 0;
        long long maxSubstring = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1') {
                currOnes++;
            } else {
                maxSubstring += ((currOnes * (currOnes + 1)) / 2) % MOD;
                currOnes = 0;
            }
        }
        maxSubstring += ((currOnes * (currOnes + 1)) / 2) % MOD;
        return maxSubstring;
    }
};