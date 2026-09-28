class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st;

        string curr = "";
        for (int i = 0; i < s.size(); i++) {
            curr = "";

            if (s[i] == ')') {
                while (!st.empty() && st.top() != '(') {
                    curr += st.top();
                    // cout<<curr<<endl;
                    st.pop();
                }
                st.pop();
                for (auto& ch : curr) {
                    st.push(ch);
                }
            } else {
                st.push(s[i]);
            }
        }

        string ans = "";

        while (!st.empty()) {
            ans = st.top() + ans;
            st.pop();
        }

        return ans;
    }
};