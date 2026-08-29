class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> count(26, 0);
        vector<bool> used(26, false);
        stack<char> st;

        for (char ch : s) {
            count[ch - 'a']++;
        }

        for (char ch : s) {
            count[ch - 'a']--;

            if (used[ch - 'a']) {
                continue;
            }

            while (!st.empty() && st.top() > ch && count[st.top() - 'a'] > 0) {
                used[st.top() - 'a'] = false;
                st.pop();
            }

            st.push(ch);
            used[ch - 'a'] = true;
        }

        string ans = "";

        while (!st.empty()) {
            ans = st.top() + ans;
            st.pop();
        }

        return ans;
    }
};