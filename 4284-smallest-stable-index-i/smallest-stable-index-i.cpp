class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();

        int maxi = INT_MIN;

        for (int i = 0; i < n; i++) {
            int mini = INT_MAX;
            maxi = max(maxi, nums[i]);
            for (int j = i; j < n; j++) {
                mini = min(mini, nums[j]);
            }
            if (maxi - mini <= k) {
                return i;
            }
        }
        return -1;
    }
};