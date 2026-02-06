class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int ans = n;
        int j = 0;
        for (int i = 0; i < n; i++) {
            while (j < n && nums[j] <= static_cast<long long>(nums[i]) * k) {
                j++;
            }
            ans = min(ans, n - (j - i));
        }
        return ans;
    }
};