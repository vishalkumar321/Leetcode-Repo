class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> flip(n, 0);

        int active = 0;
        int ans = 0;

        for (int i = 0; i < n; i++) {

            if (i >= k) {
                active -= flip[i - k];
            }

            if (nums[i] ^ (active % 2) == 0) {
                if (i + k > n) {
                    return -1;
                }
                flip[i] = 1;
                active++;
                ans++;
            }
        }
        return ans;
    }
};