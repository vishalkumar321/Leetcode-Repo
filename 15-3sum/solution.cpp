class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;

    // Step 1: Sort the array
    sort(nums.begin(), nums.end());
    int n = nums.size();

    // Step 2: Iterate through the array
    for (int i = 0; i < n; i++) {
        // Skip duplicate elements for the fixed element
        if (i > 0 && nums[i] == nums[i - 1]) continue;

        // Use two pointers to find the remaining two numbers
        int target = -nums[i];
        int left = i + 1, right = n - 1;

        while (left < right) {
            int currentSum = nums[left] + nums[right];
            if (currentSum == target) {
                result.push_back({nums[i], nums[left], nums[right]});

                // Skip duplicates for left and right pointers
                while (left < right && nums[left] == nums[left + 1]) left++;
                while (left < right && nums[right] == nums[right - 1]) right--;

                // Move pointers inward
                left++;
                right--;
            } else if (currentSum < target) {
                left++;  // Increase the sum
            } else {
                right--; // Decrease the sum
            }
        }
    }

    return result;
    }
};