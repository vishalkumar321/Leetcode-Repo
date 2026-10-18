class Solution {
public:
    int minDeletions(vector<int>& nums) {

        int n = nums.size();
        int count = 0;
        int op = 0;

        for (int i = 1; i < n; i++) {
            op = nums[i] ^ nums[i - 1];
            if (op== 0) {
                count++;
            }
        }
        return count;
    }
};