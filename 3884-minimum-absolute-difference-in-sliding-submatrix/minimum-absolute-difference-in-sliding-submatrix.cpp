class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        if (k == 1)
            return vector<vector<int>>(m, vector<int>(n, 0));

        vector<vector<int>> ans(m - k + 1, vector<int>(n - k + 1, 0));

        for (int i = 0; i + k <= m; i++) {
            for (int j = 0; j + k <= n; j++) {
                vector<int> currDiff;
                for (int x = i; x < i + k; x++) {
                    for (int y = j; y < j + k; y++) {
                        currDiff.push_back(grid[x][y]);
                    }
                }
                sort(currDiff.begin(), currDiff.end());
                int diff = 0;
                int mini = INT_MAX;
                for (int t = 1; t < k * k; t++) {
                    diff = currDiff[t] - currDiff[t - 1];
                    if (diff == 0)
                        continue;
                    mini = min(diff, mini);
                }
                if (mini == INT_MAX)
                    mini = 0;
                ans[i][j] = mini;
            }
        }
        return ans;
    }
};