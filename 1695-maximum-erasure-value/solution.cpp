class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int> s;
        int i = 0;
        int j = 0;
        int sum = 0;
        int ans = 0;

        while (i < nums.size()) {
            if (s.find(nums[i]) == s.end()) {
                s.insert(nums[i]);
                sum += nums[i];
                ans = max(sum, ans);
                i++;
            } else {
                s.erase(nums[j]);
                sum -= nums[j];
                j++;
            }
        }
        return ans;
    }
};