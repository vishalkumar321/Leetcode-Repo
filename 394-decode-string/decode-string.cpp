class Solution {
public:
    string decodeString(string s) {
        stack<string> st;

        for (auto& it : s) {
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
                while (k--) {
                    decoded += curr;
                }
                st.push(decoded);
            } else {
                st.push(string(1, it));
            }
        }

        string result = "";
        while (!st.empty()) {
            result = st.top() + result;
            st.pop();
        }
        return result;
    }
};