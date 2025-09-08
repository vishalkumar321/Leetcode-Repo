class Solution {
public:

        void subseq(vector<int>&result, vector<vector<int>>&ans,vector<int>&nums, int n, int index){

        if(n==index){
            ans.push_back(result);
            return;
        }
        
        

        result.push_back(nums[index]);
        subseq(result,ans,nums,n,index+1);
        result.pop_back();

         while (index + 1 < n && nums[index] == nums[index + 1]) {
            index++;
        }

        subseq(result,ans,nums,n,index+1);

    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>result;
        sort(nums.begin(),nums.end());
        subseq(result,ans,nums,nums.size(),0);
        return ans;
    }
};