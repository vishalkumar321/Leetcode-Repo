class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st(nums.begin(), nums.end());

        int prefix = nums[0];
        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1] + 1) {
                prefix += nums[i];
            } else {
                break;
            }
        }

        while (st.count(prefix)) {
            prefix += 1;
        }
        return prefix;
    }
};