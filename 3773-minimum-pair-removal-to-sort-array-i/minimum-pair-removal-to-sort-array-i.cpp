class Solution {
public:
    bool sorted(vector<int>& nums) {
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] > nums[i + 1])
                return false;
        }
        return true;
    }

    int minimumPairRemoval(vector<int>& nums) {
        int ops = 0;

        while (!sorted(nums)) {
            int n = nums.size();
            int minSum = nums[0] + nums[1];
            int idx = 0;

            for (int i = 1; i < n - 1; i++) {
                int sum = nums[i] + nums[i + 1];
                if (sum < minSum) {
                    minSum = sum;
                    idx = i;
                }
            }

            nums[idx] = nums[idx] + nums[idx + 1];
            nums.erase(nums.begin() + idx + 1);
            ops++;
        }

        return ops;
    }
};
