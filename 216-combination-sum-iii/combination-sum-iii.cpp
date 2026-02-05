class Solution {
public:
    void backTrack(vector<vector<int>>& ans, vector<int>& current, int index, int sum, int k, int n){
        if(current.size()==k && sum==n){
            ans.push_back(current);
            return;
        }
        if(current.size()>k || sum>n){
            return;
        }

        for(int i=index; i<=9; i++){
            current.push_back(i);
            backTrack(ans, current, i+1,sum+i, k, n);
            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int>current;

        backTrack(ans, current, 1, 0, k, n);
        return ans;
    }
};