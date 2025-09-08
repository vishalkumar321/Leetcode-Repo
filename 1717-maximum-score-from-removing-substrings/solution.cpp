class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int res = 0;
        stack<char> st;

        int firstchar, secondchar;
        int high, low;

        if (x > y) {
            firstchar = 'a';
            secondchar = 'b';
            high = x;
            low = y;
        } else {
            firstchar = 'b';
            secondchar = 'a';
            high = y;
            low = x;
        }

        string temp = "";
        for (char c : s) {
            if (!st.empty() && st.top() == firstchar && c == secondchar) {
                st.pop();
                res += high;
            } else {
                st.push(c);
            }
        }

        while (!st.empty()) {
            temp += st.top();
            st.pop();
        }
        reverse(temp.begin(), temp.end());

        for (char c : temp) {
            if (!st.empty() && st.top() == secondchar && c == firstchar) {
                st.pop();
                res += low;
            } else {
                st.push(c);
            }
        }
        return res;
    }
};