// SPACE OPTIMIZATION APPROACH
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        int n = triangle[m - 1].size();

        vector<int> front(m, 0), curr(m, 0);

        for (int j = 0; j < n; j++) {
            front[j] = triangle[m - 1][j];
        }
        for (int i = m - 2; i >= 0; i--) {
            for (int j = i; j >= 0; j--) {

                int downLeft = triangle[i][j] + front[j];
                int downRight = triangle[i][j] + front[j + 1];
                curr[j] = min(downLeft, downRight);
            }
            front = curr;
        }
        return front[0];
    }
};

// BOTTOM-UP APPROACH
// class Solution {
// public:
//     int minimumTotal(vector<vector<int>>& triangle) {
//         int m = triangle.size();
//         int n = triangle[0].size();

//         vector<vector<int>>dp = triangle;

//         for(int j=0; j<n; j++){
//             dp[m-1][j] = triangle[m-1][j];
//         }
//         for(int i=m-2; i>=0; i--){
//             for(int j=i; j>=0; j--){

//                     int downLeft = triangle[i][j] + dp[i+1][j];
//                     int downRight = triangle[i][j] + dp[i+1][j+1];
//                     dp[i][j] = min(downLeft, downRight);
//             }
//         }
//         return dp[0][0];
//     }
// };

// TOP-DOWN APPROACH
// class Solution {
// public:
//     int solve(vector<vector<int>>& triangle, int i, int j,
//               vector<vector<int>>& dp) {
//         int m = triangle.size();
//         if (i == m - 1)
//             return triangle[i][j];

//         if (dp[i][j] != -1) {
//             return dp[i][j];
//         }

//         int downLeft = triangle[i][j] + solve(triangle, i + 1, j, dp);
//         int downRight = triangle[i][j] + solve(triangle, i + 1, j + 1, dp);

//         dp[i][j] = min(downLeft, downRight);
//         return dp[i][j];
//     }

//     int minimumTotal(vector<vector<int>>& triangle) {
//         int m = triangle.size();
//         int n = triangle.size();
//         vector<vector<int>> dp(m, vector<int>(n, -1));

//         return solve(triangle, 0, 0, dp);
//     }
// };