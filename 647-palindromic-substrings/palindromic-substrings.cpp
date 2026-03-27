class Solution {
public:
    int countPalindrome(string& s, int low, int high) {
        int ans = 0;
        int n = s.size();

        while (low >= 0 && high < n) {
            if (s[low] != s[high]) {
                break;
            }
            low--;
            high++;
            ans++;
        }
        return ans;
    }

    int countSubstrings(string s) {
        int ans = 0;

        for (int i = 0; i < s.size(); i++) {
            ans += countPalindrome(s, i, i);
            ans += countPalindrome(s, i, i + 1);
        }
        return ans;
    }
};