class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size();

        vector<int> arr1;
        vector<int> arr2;

        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);

        for (int i = 2; i < n; i++) {
            if (arr1.back() > arr2.back()) {
                arr1.push_back(nums[i]);
            } else {
                arr2.push_back(nums[i]);
            }
        }

        int n1 = arr1.size();
        int n2 = arr2.size();

        int idx = 0;
        int it = 0;
        while (n1--) {
            nums[idx++] = arr1[it++];
        }
        it = 0;
        while (n2--) {
            nums[idx++] = arr2[it++];
        }
        return nums;
    }
};