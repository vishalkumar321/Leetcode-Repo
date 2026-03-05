class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int n = heights.size();
        int ans = 0;

        for (int i = 0; i <= n; i++) {
            int curr = (i == n ? 0 : heights[i]);

            while (!st.empty() && heights[st.top()] >= curr) {
                int h = heights[st.top()];
                st.pop();

                int right = i;
                int left = st.empty() ? -1 : st.top();

                ans = max(ans, h * (right - left - 1));
            }

            st.push(i);
        }

        return ans;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> height(m, 0);
        int ans = 0;

        for (int i = 0; i < n; i++) {

            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == '1')
                    height[j]++;
                else
                    height[j] = 0;
            }

            ans = max(ans, largestRectangleArea(height));
        }

        return ans;
    }
};