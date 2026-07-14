class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {

        int left = 0;
        int right = 0;
        int zeroCnt = 0;
        int maxLen = INT_MIN;

        while (right < nums.size()) {
            if (nums[right] == 0) {
                zeroCnt++;
            }

            while (zeroCnt > k) {
                if (nums[left] == 0)
                    zeroCnt--;
                left++;
            }

            maxLen = max(maxLen, right - left + 1);
            right++;
        }
        return maxLen;
    }
};