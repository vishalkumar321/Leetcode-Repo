class Solution {
public:
    string longestWord(vector<string>& words) {
        sort(words.begin(), words.end());

        string ans = "";
        unordered_set<string> st;

        for (auto& it : words) {
            if (it.size() == 1 || st.count(it.substr(0, it.length() - 1))) {
                st.insert(it);

                if (ans.length() < it.length()) {
                    ans = it;
                }
            }
        }
        return ans;
    }
};