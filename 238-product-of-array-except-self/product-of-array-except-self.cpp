class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int n = nums.size();
        vector<int> ans(n);

        ans[0] = nums[0];
        for (int i = 1; i < n; i++) {
            ans[i] = nums[i] * ans[i - 1];
        }

        int suffix = 1;
        for (int i = n - 1; i >= 0; i--) {

            if (i == 0) {
                ans[0] = suffix;
            } else {
                ans[i] = ans[i - 1] * suffix;
            }
            suffix = suffix * nums[i];
        }

        return ans;
    }
};