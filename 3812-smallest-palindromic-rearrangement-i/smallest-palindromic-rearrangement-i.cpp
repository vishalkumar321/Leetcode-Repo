class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();
        int len = s.size() / 2;

        sort(s.begin(), s.begin() + len);
        sort(s.rbegin(), s.rbegin() + len);
        
        // for (int i = 0; i < len; i++) {
        //     s[n - 1 - i] = s[i];
        // }
        return s;
    }
};