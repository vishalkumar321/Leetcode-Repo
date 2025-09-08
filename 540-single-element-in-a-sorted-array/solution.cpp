class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int start =0;
        int end=nums.size()-1;
        int mid;

        if(nums.size()==1){
            return nums[0];
        }

        while(start<=end){
            mid = start + (end-start)/2;

            if((mid==0 || nums[mid-1]!=nums[mid]) && nums[mid]!=nums[mid+1]){
                return nums[mid];
            }
            else if(mid==0 && nums[mid]!=nums[mid+1]){
                return nums[mid];
            }
            else if(mid>0 && nums[mid-1]==nums[mid]){
                if(mid%2==0){
                    end =mid-1;
                }
                else{
                    start = mid+1;
                }
            }
            else if(nums[mid]==nums[mid+1]){
                if(mid%2==0){
                    start = mid+1;
                }
                else{
                    end =mid-1;
                }
            }
        }
        return nums[mid];
    }
};

// class Solution {
// public:
//     int singleNonDuplicate(vector<int>& nums) {
//         int n = nums.size();
//         int ans = 0;

//         for(int i = 0; i < n; i++) {
//             ans = ans ^ nums[i];
//         }
//         return ans;
//     }
    
// };