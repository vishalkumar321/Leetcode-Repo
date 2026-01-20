class Solution {
public:
    int calculate(string s) {

        stack<int> st;
        int ans = 0;
        long long number = 0;
        int sign = 1;

        for (int i = 0; i < s.size(); i++) {

            if (s[i] >= '0' && s[i] <= '9') {
                number = number * 10 + (s[i] - '0');
            }
             else if (s[i] == '+') {
                ans += sign * number;
                number = 0;
                sign = 1;
            }
             else if (s[i] == '-') {
                ans += sign * number;
                number = 0;
                sign = -1;
            }
             else if (s[i] == '(') {
                st.push(ans);
                st.push(sign);
                ans = 0;
                number = 0;
                sign = 1;
            }
             else if (s[i] == ')') {
                ans += sign * number;
                number = 0;

                int prevSign = st.top();
                st.pop();
                int prevAns = st.top();
                st.pop();

                ans = prevAns + prevSign * ans;
            }
        }
        ans += sign * number;
        return ans;
    }
};