class Solution {
public:
    int centeredSubarrays(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int sum = 0;
                for (int k = i; k <= j; k++) {
                    sum += nums[k];
                }
                for (int k = i; k <= j; k++) {
                    if (nums[k] == sum) {
                        count++;
                        break;
                    }
                }
            }
        }
        return count;
    }
};