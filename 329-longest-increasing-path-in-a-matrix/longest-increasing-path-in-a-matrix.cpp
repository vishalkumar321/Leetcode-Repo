class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> indegree(m, vector<int>(n, 0));

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < 4; k++) {
                    int ni = i + dr[k];
                    int nj = j + dc[k];

                    if (ni >= 0 && ni < m && nj >= 0 && nj < n &&
                        matrix[ni][nj] < matrix[i][j]) {
                        indegree[i][j]++;
                    }
                }
            }
        }

        queue<pair<int, int>> q;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (indegree[i][j] == 0)
                    q.push({i, j});
            }
        }

        int ans = 0;

        while (!q.empty()) {
            int sz = q.size();
            ans++;

            while (sz--) {
                auto [r, c] = q.front();
                q.pop();

                for (int k = 0; k < 4; k++) {
                    int nr = r + dr[k];
                    int nc = c + dc[k];

                    if (nr >= 0 && nr < m && nc >= 0 && nc < n &&
                        matrix[nr][nc] > matrix[r][c]) {

                        indegree[nr][nc]--;

                        if (indegree[nr][nc] == 0)
                            q.push({nr, nc});
                    }
                }
            }
        }

        return ans;
    }
};