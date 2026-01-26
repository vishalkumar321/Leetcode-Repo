class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int l = 0, r = 0, zeros = 0, maxLen = 0;

        while (r < nums.size()) {
            if (nums[r] == 0)
                zeros++;

            if (zeros > 1) {
                if (nums[l] == 0)
                    zeros--;
                l++;
            }

            int len = r - l + 1;
            maxLen = max(maxLen, len);
            r++;
        }
        return maxLen - 1;
    }
};