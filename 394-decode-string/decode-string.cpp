class Solution {
public:
    string decodeString(string s) {
        stack<string> st;

        for (char it : s) {
            if (it == ']') {
                string curr = "";
                while (st.top() != "[") {
                    curr = st.top() + curr;
                    st.pop();
                }
                st.pop();

                string num = "";
                while (!st.empty() && isdigit(st.top()[0])) {
                    num = st.top() + num;
                    st.pop();
                }

                int k = stoi(num);
                string decoded = "";
                while (k--)
                    decoded += curr;

                st.push(decoded);
            } else {
                st.push(string(1, it));
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