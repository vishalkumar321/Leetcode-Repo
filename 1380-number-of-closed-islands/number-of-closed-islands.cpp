class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int ans = 0;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<int, int>> q;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0 && !visited[i][j]) {
                    q.push({i, j});
                    visited[i][j] = true;

                    int delR[4] = {0, 0, 1, -1};
                    int delC[4] = {1, -1, 0, 0};

                    int flag = false;
                    while (!q.empty()) {
                        int row = q.front().first;
                        int col = q.front().second;
                        q.pop();

                        if (row == 0 || row == m - 1 || col == 0 ||
                            col == n - 1) {
                            flag = true;
                        }

                        for (int k = 0; k < 4; k++) {
                            int nrow = row + delR[k];
                            int ncol = col + delC[k];

                            if (nrow >= 0 && nrow < m && ncol >= 0 &&
                                ncol < n && grid[nrow][ncol] == 0 &&
                                !visited[nrow][ncol]) {
                                visited[nrow][ncol] = true;
                                q.push({nrow, ncol});
                            }
                        }
                    }
                    if (!flag)
                        ans++;
                }
            }
        }
        return ans;
    }
};