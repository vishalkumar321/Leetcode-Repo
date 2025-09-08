// ITERATIVE APPROACH
// class Solution {
// public:
//     vector<vector<int>> subsets(vector<int>& nums) {
//         vector<vector<int>> ans = {{}};

//         for (int num : nums) {
//             int n = ans.size();
//             for (int j = 0; j < n; j++) {
//                 vector<int>newSubset = ans[j];
//                 newSubset.push_back(num);
//                 ans.push_back(newSubset);
//             }
//         }
//         return ans;
//     }
// };

// BIT MANIPULATION APPROACH
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        int total = 1 << n;

        for (int i = 0; i < total; i++) {
            vector<int> subset;
            for (int j = 0; j < n; j++) {
                if (i & (1 << j)) {
                    subset.push_back(nums[j]);
                }
            }
            ans.push_back(subset);
        }
        return ans;
    }
};


// RECURSIVE AND BACKTRACKING APPROACH
// class Solution {
// public:
//     void subseq(vector<int>&result, vector<vector<int>>&ans,vector<int>&nums, int n, int index){
//         if(n==index){
//             ans.push_back(result);
//             return;
//         }
//         subseq(result,ans,nums,n,index+1);
//         result.push_back(nums[index]);
//         subseq(result,ans,nums,n,index+1);
//         result.pop_back();
//     }

//     vector<vector<int>> subsets(vector<int>& nums) {
//         vector<vector<int>>ans;
//         vector<int>result;
//         subseq(result,ans,nums,nums.size(),0);
//         return ans;
//     }
// };