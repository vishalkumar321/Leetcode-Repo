class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        long long sum = 0;
        int maxFreq = 1;
        int i = 0;

        for (int j = 0; j < nums.size(); j++) {
            sum += nums[j];

            while ((long long)nums[j] * (j - i + 1) - sum > k) {
                sum -= nums[i];
                i++;
            }
            maxFreq = max(maxFreq, j - i + 1);
        }
        return maxFreq;
    }
};