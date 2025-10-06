class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();

        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>
            pq;

        vector<vector<int>> visited(n, vector<int>(n, 0));

        pq.push({grid[0][0], 0, 0});
        visited[0][0] = 1;

        int maxTime = 0;

        while (!pq.empty()) {
            vector<int> top = pq.top();
            pq.pop();

            int height = top[0];
            int x = top[1];
            int y = top[2];

            maxTime = max(maxTime, height);

            if (x == n - 1 && y == n - 1)
                return maxTime;

            for (int k = 0; k < 4; k++) {
                int newX = x + dx[k];
                int newY = y + dy[k];

                if (newX >= 0 && newX < n && newY >= 0 && newY < n &&
                    !visited[newX][newY]) {
                    visited[newX][newY] = 1;
                    pq.push({grid[newX][newY], newX, newY});
                }
            }
        }

        return -1;
    }
};
