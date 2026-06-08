class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int> left;
        vector<int> right;
        vector<int> result(n, pivot);

        for (int i = 0; i < n; i++) {
            if (nums[i] < pivot) {
                left.push_back(nums[i]);
            } else if (nums[i] > pivot) {
                right.push_back(nums[i]);
            }
        }

        for (int i = 0; i < left.size(); i++) {
            result[i] = left[i];
        }

        int start = n - right.size();

        for (int i = 0; i < right.size(); i++) {
            result[start + i] = right[i];
        }
        return result;
    }
};