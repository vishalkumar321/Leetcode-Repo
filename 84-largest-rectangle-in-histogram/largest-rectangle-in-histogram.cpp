class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        heights.push_back(0);
        stack<int> st;
        int result = 0;

        for (int i = 0; i <= n; i++) {
            while (!st.empty() && heights[st.top()] > heights[i]) {
                int h = heights[st.top()];
                st.pop();
                int left = st.empty() ? -1 : st.top();
                int width = i - left - 1;

                result = max(result, h * width);
            }
            st.push(i);
        }
        return result;
    }
};