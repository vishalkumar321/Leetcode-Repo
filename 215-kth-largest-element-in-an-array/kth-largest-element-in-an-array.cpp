class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        int n = nums.size();
        priority_queue<int> p;

        for (int i = 0; i < n; i++) {
            p.push(nums[i]);
        }

        int kLargest = 0;
        while (k--) {
            kLargest = p.top();
            p.pop();
        }
        return kLargest;
    }
};