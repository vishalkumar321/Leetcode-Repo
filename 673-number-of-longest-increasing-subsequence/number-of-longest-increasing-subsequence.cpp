class Solution {
public:
    vector<int> nums;
    vector<pair<int, int>> memo;
    int n;

    pair<int, int> dfs(int i) {
        if (memo[i].first != -1)
            return memo[i];

        int bestLen = 1;
        int ways = 1;

        for (int j = i + 1; j < n; j++) {
            if (nums[j] > nums[i]) {
                auto [len, cnt] = dfs(j);
                if (1 + len > bestLen) {
                    bestLen = 1 + len;
                    ways = cnt;
                } else if (1 + len == bestLen) {
                    ways += cnt;
                }
            }
        }
        return memo[i] = {bestLen, ways};
    }

    int findNumberOfLIS(vector<int>& arr) {
        nums = arr;
        n = nums.size();
        memo.assign(n, {-1, -1});

        int maxLen = 0, result = 0;

        for (int i = 0; i < n; i++) {
            auto [len, cnt] = dfs(i);
            if (len > maxLen) {
                maxLen = len;
                result = cnt;
            } else if (len == maxLen) {
                result += cnt;
            }
        }

        return result;
    }
};
