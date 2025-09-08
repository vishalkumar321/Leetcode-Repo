class Solution {
public:
    string processStr(string s) {

        string ans;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= 'a' && s[i] <= 'z') {
                ans += s[i];
            } else if (s[i] == '*') {
                if (!ans.empty())
                    ans.pop_back();
            } else if (s[i] == '#') {
                ans += ans;
            } else if (s[i] == '%') {
                reverse(ans.begin(), ans.end());
            }
        }
        return ans;
    }
};