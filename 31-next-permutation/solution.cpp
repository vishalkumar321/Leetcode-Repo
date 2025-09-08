// // OPTIMAL APPROACH
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n= nums.size();
        int idx=-1;
        for(int i=n-1;i>0; i--){
            if(nums[i]>nums[i-1]){
                idx =i-1;
                break;
            }
        }
            if(idx==-1){
                reverse(nums.begin(),nums.end());
                return;
            }
        for(int i=n-1; i>idx; i--){
            if(nums[i]>nums[idx]){
                swap(nums[i],nums[idx]);
                sort(nums.begin()+idx+1,nums.end());
                break;
            }
        }
    }
};

// BETTER APPROACH
// class Solution {
// public:
//     void nextPermutation(vector<int>& nums) {
//         // In-built STL function
//       next_permutation(nums.begin(),nums.end());
//     }
// };