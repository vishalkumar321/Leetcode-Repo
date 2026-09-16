class Solution {
public:
    void solve(int idx, vector<int>& candidates, int target, vector<int>& curr,
               vector<vector<int>>& ans) {

        if (target == 0) {
            ans.push_back(curr);
            return;
        }

        if (target < 0 || idx < 0) {
            return;
        }
        // not take
        solve(idx - 1, candidates, target, curr, ans);
        // take
        curr.push_back(candidates[idx]);
        solve(idx, candidates, target - candidates[idx], curr, ans);
        curr.pop_back();
    
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();

        vector<int> curr;
        vector<vector<int>> ans;

        solve(n - 1, candidates, target, curr, ans);
        return ans;
    }
};