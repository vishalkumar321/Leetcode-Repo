class Solution {
public:
    int possible(vector<int>& nums, int threshold, int mid) {
        int sum = 0;
        for (int num : nums) {
            sum += (num + mid - 1) / mid;
        }
        return sum <= threshold;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (possible(nums, threshold, mid)) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};