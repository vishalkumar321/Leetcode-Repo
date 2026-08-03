class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {

        int m = image.size();
        int n = image[0].size();
        int initialColor = image[sr][sc];

        if (initialColor == color) {
            return image;
        }
        
        queue<pair<int, int>> q;
        q.push({sr, sc});

        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            image[row][col] = color;

            int delRow[4] = {-1, 0, 1, 0};
            int delCol[4] = {0, 1, 0, -1};

            for (int i = 0; i < 4; i++) {
                int nrow = row + delRow[i];
                int ncol = col + delCol[i];

                if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n &&
                    initialColor == image[nrow][ncol]) {
                    q.push({nrow, ncol});
                }
            }
        }
        return image;
    }
};