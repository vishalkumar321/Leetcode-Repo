class Solution {
public:
    void combination(vector<vector<int>>& ans, vector<int>& arr,
                     vector<int>& curr, int n, int idx, int target) {

        if (idx == n || target < 0) {
            return;
        }

        if (target == 0) {
            ans.push_back(curr);
            return;
        }

        curr.push_back(arr[idx]);

        combination(ans, arr, curr, n, idx, target - arr[idx]);
        curr.pop_back();
        combination(ans, arr, curr, n, idx + 1, target);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;

        combination(ans, candidates, curr, candidates.size(), 0, target);
        return ans;
    }
};