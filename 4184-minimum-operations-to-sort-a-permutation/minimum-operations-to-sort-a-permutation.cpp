class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) {
            return 0;
        }

        int start = find(nums.begin(), nums.end(), 0) - nums.begin();

        bool asc = true;
        bool desc = true;

        for (int i = 1; i < n; i++) {
            int val = nums[(start + i) % n];

            if (val != i) {
                asc = false;
            }
            if (val != n - i) {
                desc = false;
            }

            if (!asc && !desc) {
                return -1;
            }
        }

        if (asc) {
            return min(start, n - start + 2);
        }
        return min(start + 2, n - start);
    }
};