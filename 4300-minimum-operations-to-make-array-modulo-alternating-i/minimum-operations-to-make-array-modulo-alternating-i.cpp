class Solution {
public:
    int cost(int r, int t, int k) {
        int inc = (t - r + k) % k;
        int dec = (r - t + k) % k;
        return min(inc, dec);
    }

    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = INT_MAX;

        for (int x = 0; x < k; x++) {
            for (int y = 0; y < k; y++) {
                if (x == y)
                    continue;

                int ops = 0;
                for (int i = 0; i < n; i++) {
                    int rem = nums[i] % k;

                    if (i % 2 == 0) {
                        ops += cost(rem, x, k);
                    } else {
                        ops += cost(rem, y, k);
                    }
                }
                ans = min(ans, ops);
            }
        }
        return ans;
    }
};