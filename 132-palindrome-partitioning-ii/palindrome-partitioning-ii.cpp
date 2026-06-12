class Solution {
public:
    bool isPalin(int i, int j, string& s) {
        while (i < j) {
            if (s[i] != s[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

    int helper(int i, int n, string& s, vector<int>& dp) {
        if (i == n) {
            return 0;
        }
        if (dp[i] != -1) {
            return dp[i];
        }

        int palin = INT_MAX;
        for (int j = i; j < n; j++) {
            if (isPalin(i, j, s)) {
                int cost = 1 + helper(j + 1, n, s, dp);
                palin = min(palin, cost);
            }
        }
        dp[i] = palin;
        return dp[i];
    }

    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n, -1);
        return helper(0, n, s, dp) - 1;
    }
};