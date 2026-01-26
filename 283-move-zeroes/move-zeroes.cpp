class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        int index = 0;
        vector<int> ans(n,0);

        for(int i=0; i<n; i++){
            if(nums[i]!=0){
                ans[index] = nums[i];
                index++;
            }
        }
        nums = ans;
    }
};