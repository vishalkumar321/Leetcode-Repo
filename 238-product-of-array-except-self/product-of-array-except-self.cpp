class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int n = nums.size();
        vector<int> prefixSum(n);
        vector<int> suffixSum(n);
        prefixSum[0] = nums[0];
        suffixSum[n - 1] = nums[n - 1];

        for (int i = 1; i < n; i++) {
            prefixSum[i] = prefixSum[i - 1] * nums[i];
        }

        for (int i = n - 2; i >= 0; i--) {
            suffixSum[i] = suffixSum[i + 1] * nums[i];
        }

        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                ans[i] = 1 * suffixSum[i + 1];
            } else if (i == n - 1) {
                ans[i] = 1 * prefixSum[i - 1];
            } else {
                ans[i] = prefixSum[i - 1] * suffixSum[i + 1];
            }
        }
        return ans;
    }
};