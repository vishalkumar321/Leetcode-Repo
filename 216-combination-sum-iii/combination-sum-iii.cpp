class Solution {
public:
    void solve(int k, int n, int start, int sum, vector<int>& combination,
               vector<vector<int>>& ans) {

        if (sum == n && combination.size() == k) {
            ans.push_back(combination);
            return;
        }
        if (sum > n || combination.size() > k) {
            return;
        }

        for (int i = start; i <= 9; i++) {
            combination.push_back(i);
            solve(k, n, i + 1, sum + i, combination, ans);
            combination.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> combination;
        vector<vector<int>> ans;

        solve(k, n, 1, 0, combination, ans);
        return ans;
    }
};