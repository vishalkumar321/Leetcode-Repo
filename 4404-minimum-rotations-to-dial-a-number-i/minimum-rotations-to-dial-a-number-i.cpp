class Solution {
public:
    int minRotations(string s) {
        int start = 0;
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            int diff = abs(start - (s[i]-'0'));

            ans += (diff > 5) ? 10 - diff : diff;
            start = s[i]-'0';
        }
        return ans;
    }
};