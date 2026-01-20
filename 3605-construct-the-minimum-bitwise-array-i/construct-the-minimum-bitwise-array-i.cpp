class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);

        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums[i]; j++) {
                if ((j | (j + 1)) == nums[i]) {
                    ans[i] = j;
                    break;
                }
            }
            if (ans[i] == 0) {
                ans[i] = -1;
            }
        }
        return ans;
    }
};