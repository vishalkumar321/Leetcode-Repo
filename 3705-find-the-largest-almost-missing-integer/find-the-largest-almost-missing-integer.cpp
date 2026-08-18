class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> freq;
        if (n == k) {
            return *max_element(nums.begin(), nums.end());
        }
        
        for (int i = 0; i <= n - k; i++) {
            for (int j = i; j < i + k; j++) {
                freq[nums[j]]++;
            }
        }

        int ans = -1;
        for (auto& it : freq) {
            if (it.second == 1) {
                ans = max(ans, it.first);
            }
        }
        return ans;
    }
};