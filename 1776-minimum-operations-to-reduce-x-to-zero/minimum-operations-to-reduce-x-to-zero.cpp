class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);

        int target = sum - x;

        int left = 0;
        int maxLen = -1;

        int currSum = 0;
        for (int right = 0; right < n; right++) {
            currSum += nums[right];

            while (left<n && currSum > target) {
                currSum -= nums[left];
                left++;
            }
            if (currSum == target) {
                maxLen = max(maxLen, right - left + 1);
            }
        }
        return (maxLen == -1) ? -1 : n - maxLen;
    }
};