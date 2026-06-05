class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;
        for (int i = 0; i < n; i++) {
            long long curr = 1;
            for (int j = i; j < n; j++) {
                curr *= nums[j];
                if (curr < k) {
                    count++;
                }
                else{
                    break;
                }
            }
        }
        return count;
    }
};