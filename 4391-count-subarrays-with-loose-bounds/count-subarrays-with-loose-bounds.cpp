class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {

        int n = nums.size();
        int left = 0;
        int right = 0;
        long long ans = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] >= minK && nums[i] <= maxK) {
                right++;
            } else {
                long long l = right - left;
                ans += l * (l + 1) / 2;
                left = right;
            }
        }

        long long l = right - left;
        ans += l * (l + 1) / 2;
        return ans;
    }
};