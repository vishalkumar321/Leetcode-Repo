class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        int count = 1;
        int mini = 0;
        int ans = 0;

        for(int i=1; i<n; i++){
            if(nums[i-1] < nums[i]){
                count++;
            }
            else{
                mini = count;
                count = 1;
            }
            ans = max(ans, min(mini, count));
            ans = max(ans, count/2);
        }
        return ans;
    }
};