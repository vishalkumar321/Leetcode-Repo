class Solution {
public:

    void combination(vector<vector<int>>&ans, vector<int>&arr, vector<int>&curr, int n, int idx,int target){

        if(target==0){
            ans.push_back(curr);
            return;
        }

        for(int i=idx; i<n; i++){
            
            if(i>idx && arr[i]==arr[i-1]) continue;
            if(arr[i]>target) break;

                curr.push_back(arr[i]);
                combination(ans,arr,curr,n,i+1,target-arr[i]);
                curr.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>curr;

        sort(candidates.begin(),candidates.end());
        combination(ans,candidates,curr,candidates.size(),0,target);
        return ans;
    }
};