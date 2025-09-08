class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int top = n;
        int bottom = -1;
        int left = m;
        int right = -1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    top = min(i, top);
                    bottom = max(i, bottom);
                    left = min(j, left);
                    right = max(j, right);
                }
            }
        }
        int height = bottom - top + 1;
        int width = right - left + 1;
        return height * width;
    }
};