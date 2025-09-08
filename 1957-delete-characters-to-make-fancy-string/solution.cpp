class Solution {
public:
    string makeFancyString(string s) {
        string ans = "";

        for (auto i = 0; i < s.size(); i++) {
            if (ans.size() >= 2 && ans[ans.size() - 1] == s[i] &&
                ans[ans.size() - 2] == s[i]) {
                continue;
            }
            ans += s[i];
        }
        return ans;
    }
};