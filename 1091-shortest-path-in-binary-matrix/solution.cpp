class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        if (grid[0][0] != 0 || grid[n - 1][n - 1] != 0)
            return -1;

        vector<pair<int, int>> directions = {{0, 1},   {1, 0},  {1, 1},
                                             {-1, -1}, {-1, 0}, {0, -1},
                                             {-1, 1},  {1, -1}};

        queue<vector<int>> q;
        q.push({0, 0, 1});
        grid[0][0] = 1;

        while (!q.empty()) {
            vector<int>curr = q.front();
            q.pop();
            int row = curr[0];
            int col = curr[1];
            int dist = curr[2];

            if (row == n - 1 && col == n - 1)
                return dist;

            for (int i = 0; i < 8; i++) {
                int newrow = row + directions[i].first;
                int newcol = col + directions[i].second;

                if (newrow >= 0 && newcol >= 0 && newrow < n && newcol < n &&
                    grid[newrow][newcol] == 0) {
                    q.push({newrow, newcol, dist + 1});
                    grid[newrow][newcol] = 1;
                }
            }
        }
        return -1;
    }
};