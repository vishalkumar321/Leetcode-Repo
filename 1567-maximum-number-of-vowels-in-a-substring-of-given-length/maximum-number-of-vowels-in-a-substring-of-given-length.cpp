class Solution {
public:
    bool isVowel(char c) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            return true;
        }
        return false;
    }

    int maxVowels(string s, int k) {
        int n = s.size();
        int vowelCnt = 0;

        for (int i = 0; i < k; i++) {
            if (isVowel(s[i])) {
                vowelCnt++;
            }
        }
        int maxVowel = vowelCnt;

        for (int i = k; i < n; i++) {
            if (isVowel(s[i])) {
                vowelCnt++;
            }
            if (isVowel(s[i - k])) {
                vowelCnt--;
            }
            maxVowel = max(maxVowel, vowelCnt);
        }
        return maxVowel;
    }
};