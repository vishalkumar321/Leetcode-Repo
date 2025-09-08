class Solution {
public:
    int atMost(vector<int>& nums, int k) {
        int total = 0;

        unordered_map<int, int> freq;
        int start = 0, end = 0, n = nums.size();

        for (int end = 0; end < n; end++) {
            if (freq[nums[end]] == 0) {
                k--;
            }
            freq[nums[end]]++;

            while (k < 0) {
                freq[nums[start]]--;
                if (freq[nums[start]] == 0) {
                    k++;
                }
                start++;
            }
            total += end - start + 1;
        }
        return total;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }
};