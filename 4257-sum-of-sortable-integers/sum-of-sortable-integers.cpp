
class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int k = 1; k <= n; k++) {
            if (n % k != 0)
                continue;

            bool valid = true;
            int prevLast = -1;

            for (int start = 0; start < n && valid; start += k) {
                int descents = 0;
                int rotationStart = 0;

                for (int j = 0; j < k; j++) {
                    int next = (j + 1) % k;

                    if (nums[start + j] > nums[start + next]) {
                        descents++;
                        rotationStart = next;
                    }
                }

                if (descents > 1) {
                    valid = false;
                    break;
                }

                int first = nums[start + rotationStart];
                int last = nums[start + (rotationStart + k - 1) % k];

                if (start > 0 && prevLast > first) {
                    valid = false;
                    break;
                }

                prevLast = last;
            }

            if (valid)
                ans += k;
        }

        return ans;
    }
};
