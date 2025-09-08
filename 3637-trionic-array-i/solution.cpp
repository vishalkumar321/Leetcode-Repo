class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        if(nums.size()<=3)return false;

        int i=0;
        int n = nums.size();
        if(nums.size()<4)return false;

        while(i+1<n && nums[i] < nums[i+1]){
            i++;
        }
        if(i==0 || i>=n-2) return false;
        
        int peak = i;
        while(i+1<n && nums[i] > nums[i+1]){
            i++;
        }
        if(i==peak || i>=n-1)return false;
        
        while(i+1<n && nums[i] < nums[i+1]){
            i++;
        }
        return i==n-1;
    }
};