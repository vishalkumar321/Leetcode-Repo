class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        unordered_map<int, int> rowCnt, colCnt;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    rowCnt[i]++;
                    colCnt[j]++;
                }
            }
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && (rowCnt[i] > 1 || colCnt[j] > 1)) {
                    ans++;
                }
            }
        }
        return ans;
    }
};