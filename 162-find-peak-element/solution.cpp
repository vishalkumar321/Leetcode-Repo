class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int start = 0;
        int end = nums.size() - 1;
        int mid;

        while(start<=end){
            mid  = start +(end - start)/2;

            if((mid==0 || nums[mid-1]<nums[mid]) && (mid == nums.size()-1 || nums[mid]>nums[mid+1])){
                return mid;
            }
            else if(nums[mid]<nums[mid+1] && mid<nums.size()-1){
                start = mid +1;
            }
            else{
                end = mid -1;
            }
        }
        return -1;
    }
};