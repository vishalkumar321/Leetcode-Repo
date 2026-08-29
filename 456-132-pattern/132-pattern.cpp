class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) {
            return false;
        }

        stack<int> st;
        vector<int> arr(nums.size());
        arr[0] = nums[0];

        for (int i = 1; i < n; i++) {
            arr[i] = min(nums[i], arr[i - 1]);
        }

        for (int i = n - 1; i > 0; i--) {
            if (nums[i] <= arr[i]) {
                continue;
            }

            while (!st.empty() && st.top() <= arr[i]) {
                st.pop();
            }

            if (!st.empty() && st.top() < nums[i]) {
                return true;
            }
            st.push(nums[i]);
        }
        return false;
    }
};