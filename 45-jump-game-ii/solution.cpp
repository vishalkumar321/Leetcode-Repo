class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int reach = 0;
        int count = 0;
        int currentEnd = 0;

        for (int i = 0; i < n - 1; i++) {
            reach = max(reach, i + nums[i]);

            if (i == currentEnd) {
                count++;
                currentEnd = reach;
            }
            if (currentEnd >= n - 1)
                break;
        }
        return count;
    }
};