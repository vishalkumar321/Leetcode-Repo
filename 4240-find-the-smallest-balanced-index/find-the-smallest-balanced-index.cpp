class Solution {
public:
    int smallestBalancedIndex(vector<int>& nums) {
        int n = nums.size();

        if (n == 1)
            return -1;
        vector<long long> prefixSum(n);
        vector<long long> suffixProduct(n);

        prefixSum[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefixSum[i] = prefixSum[i - 1] + nums[i];
        }

        suffixProduct[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            if (suffixProduct[i + 1] > (long long)1e18 / nums[i])
                suffixProduct[i] = 1e18;
            else
                suffixProduct[i] = suffixProduct[i + 1] * nums[i];
        }

        for (int i = 0; i < n; i++) {
            if (i == 0 && suffixProduct[i + 1] == 0) {
                return i;
            } else if (i == n - 1 && prefixSum[i - 1] == 1) {
                return i;
            } else if (i > 0 && i < n - 1 &&
                       prefixSum[i - 1] == suffixProduct[i + 1]) {
                return i;
            }
        }
        return -1;
    }
};