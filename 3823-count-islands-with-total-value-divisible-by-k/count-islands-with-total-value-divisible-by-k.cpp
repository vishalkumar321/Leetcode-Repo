class Solution {
public:
    void bfs(int i, int j, int m, int n, long long& sum, vector<vector<int>>& grid,
             vector<vector<bool>>& visited) {

        queue<pair<int, int>> q;
        q.push({i, j});
        visited[i][j] = true;

        sum = grid[i][j];

        int delR[4] = {0, 0, 1, -1};
        int delC[4] = {1, -1, 0, 0};

        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for (int k = 0; k < 4; k++) {
                int nrow = row + delR[k];
                int ncol = col + delC[k];

                if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n &&
                    grid[nrow][ncol] != 0 && !visited[nrow][ncol]) {
                    visited[nrow][ncol] = true;
                    sum += grid[nrow][ncol];
                    q.push({nrow, ncol});
                }
            }
        }
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        long long sum = 0;
        int ans = 0;
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != 0 && !visited[i][j]) {
                    bfs(i, j, m, n, sum, grid, visited);
                    if (sum % k == 0)
                        ans++;
                }
            }
        }
        return ans;
    }
};