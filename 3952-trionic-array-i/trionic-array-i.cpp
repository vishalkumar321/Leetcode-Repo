class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int i = 1;
        int n = nums.size();
        if (nums.size() == 3)
            return false;

        while (i < n && nums[i] > nums[i - 1]) {
            i++;
        }
        if (i == 1 || i == n)
            return false;

        while (i < n && nums[i] < nums[i - 1]) {
            i++;
        }
        if (i == n)
            return false;

        while (i < n && nums[i] > nums[i - 1]) {
            i++;
        }

        return i == n;
    }
};