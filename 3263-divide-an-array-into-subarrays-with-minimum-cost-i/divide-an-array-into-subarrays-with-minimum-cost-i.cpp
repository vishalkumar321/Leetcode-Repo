class Solution {
public:
    int minimumCost(vector<int>& nums) {

        int first = INT_MAX;
        int second = INT_MAX;
        int n = nums.size();

        for (int i = 1; i < n; i++) {
            if (nums[i] < first) {
                second = first;
                first = nums[i];
            } else if (nums[i] < second) {
                second = nums[i];
            }
        }
        return (nums[0] + first + second);
    }
};