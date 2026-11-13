class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        long long ans = 0;
        long long operations = 0;

        priority_queue<pair<int, int>> pq;

        vector<vector<int>> nextGreater(n);
        vector<int> next(n, n);

        stack<int> st;

        int left = 0;

        for (int right = 0; right < n; right++) {

            while (!st.empty() && nums[right] >= nums[st.top()]) {
                next[st.top()] = right;
                st.pop();
            }

            if (!st.empty()) {
                nextGreater[st.top()].push_back(right);
            }

            st.push(right);

            pq.push({nums[right], right});

            operations += max(0, pq.top().first - nums[right]);

            while (operations > k) {

                for (int idx : nextGreater[left]) {
                    operations -= 1LL * (nums[left] - nums[idx]) *
                                  (min(next[idx], right + 1) - idx);
                }

                left++;
            }

            while (!pq.empty() && pq.top().second < left) {
                pq.pop();
            }

            ans += right - left + 1;
        }

        return ans;
    }
};