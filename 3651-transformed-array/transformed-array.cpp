class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);

        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                int right = nums[i] % n;
                result[i] = nums[(i + right) % n];
            } 
            else if (nums[i] < 0) {
                int left = (n - (abs(nums[i]) % n)) % n;
                result[i] = nums[(i + left) % n];
            } 
            else {
                result[i] = nums[i];
            }
        }
        return result;
    }
};
