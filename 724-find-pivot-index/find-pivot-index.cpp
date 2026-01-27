// OPTIMAL SOLUTION
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;

        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }

        int prefix = 0;
        for (int i = 0; i < n; i++) {

            if (prefix == sum - prefix - nums[i]) {
                return i;
            }
            prefix += nums[i];
        }
        return -1;
    }
};