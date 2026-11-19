class Solution {
public:
    int minimizeSum(vector<int>& nums) {

        int n = nums.size();
        sort(nums.begin(), nums.end());

        if (n == 3)
            return 0;

        int bothEnd = nums[n - 3] - nums[0];
        int oneStOneEnd = nums[n - 2] - nums[1];
        int bothStart = nums[n - 1] - nums[2];

        return min({bothEnd, oneStOneEnd, bothStart});
    }
};