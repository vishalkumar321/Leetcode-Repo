// SPACE OPTIMIZATION APPROACH
class Solution {
public:
    int climbStairs(int n) {
        if(n==0 || n==1)return 1;
        int prev1 = 1;
        int prev2 = 1;

        for(int i=2; i<=n; i++){
            int curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};


// BOTTOM-UP APPROACH
// class Solution {
// public:
//     int climbStairs(int n) {
//         if(n==0 || n==1)return 1;
//         vector<int> dp(n+1,0);

//         dp[0] = 1;
//         dp[1] = 1;

//         for(int i=2; i<=n; i++){
//             dp[i] = dp[i-1] + dp[i-2];
//         }
//         return dp[n];
//     }
// };


// TOP-DOWN APPROACH
// class Solution {
// public:
//     int solve(int n, vector<int>& dp){
//         if(n==0){
//             return 1;
//         }
//         if(n<0){
//             return 0;
//         }
//         if(dp[n]!=-1){
//             return dp[n];
//         }

//         dp[n] = solve(n-1, dp) + solve(n-2, dp);
//         return dp[n];
//     }

//     int climbStairs(int n) {
//         vector<int> dp(n + 1, -1);
//         return solve(n, dp);
//     }
// };