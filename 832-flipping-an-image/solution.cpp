class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int n = image.size();
        
        for (int row = 0; row < n; row++) {
            int i = 0, j = n - 1;
            while (i <= j) {
                // Invert while swapping
                int left = image[row][i] ^ 1;
                int right = image[row][j] ^ 1;

                image[row][i] = right;
                image[row][j] = left;

                i++;
                j--;
            }
        }
        
        return image;
    }
};
