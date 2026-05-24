class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int i = 0;
        int j = nums.size() - 1;
        int swap = 0;

        while (i < j) {
            if (nums[i] == 0 && nums[j] != 0) {
                swap++;
                i++;
                j--;
            } else if (nums[i] != 0) {
                i++;
            } else {
                j--;
            }
        }
        return swap;
    }
};