class Solution {
public:
    string shortestPalindrome(string s) {
        int n = s.size();
        string rev = s;
        reverse(rev.begin(), rev.end());
        string p = s + '#' + rev;
        int m = p.size();

        int lps[m];
        int len = 0;
        int i = 1;

        lps[0] = 0;

        while (i < p.size()) {
            if (p[i] == p[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }

        string needed = rev.substr(0, n - lps[m - 1]);
        return needed + s;
    }
};