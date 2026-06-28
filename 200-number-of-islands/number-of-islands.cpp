class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int island = 0;
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        queue<pair<int, int>> q;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    q.push({i, j});
                    visited[i][j] = true;

                    while (!q.empty()) {
                        int row = q.front().first;
                        int col = q.front().second;
                        q.pop();

                        int delRow[4] = {-1, 0, 1, 0};
                        int delCol[4] = {0, 1, 0, -1};

                        for (int i = 0; i < 4; i++) {
                            int nrow = row + delRow[i];
                            int ncol = col + delCol[i];

                            if (nrow >= 0 && nrow < n && ncol >= 0 &&
                                ncol < m && grid[nrow][ncol] == '1' &&
                                !visited[nrow][ncol]) {
                                visited[nrow][ncol] = true;
                                q.push({nrow, ncol});
                            }
                        }
                    }
                    island++;
                }
            }
        }
        return island;
    }
};