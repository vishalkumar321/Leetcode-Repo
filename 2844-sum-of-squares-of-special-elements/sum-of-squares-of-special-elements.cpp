class Solution {
public:
    int square(int n) { return n * n; }

    int sumOfSquares(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int i = 1; i <= n; i++) {
            if (n % i == 0) {
                ans += square(nums[i - 1]);
            }
        }
        return ans;
    }
};