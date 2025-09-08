// class Solution {
// public:
//     vector<int> singleNumber(vector<int>& nums) {
//         vector<int>ans;
//         map<int, int> mpp;

//         for(int i=0; i<nums.size(); i++){
//             mpp[nums[i]]++;
//         }

//         for(auto it : mpp){
//             if(it.second == 1){
//                 ans.push_back(it.first);
//             }
//         }
//         return ans;
//     }
// };

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long num = 0;

        for (int i : nums) {
            num = num ^ i;
        }

        long long rightMost = num & -num;
        int nums1 = 0, nums2 = 0;

        for (int i : nums) {
            if (rightMost & i) {
                nums1 = nums1 ^ i;
            } else {
                nums2 = nums2 ^ i;
            }
        }
        return {max(nums1, nums2), min(nums1, nums2)};
    }
};