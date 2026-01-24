class Solution {
public:
    bool isVowel(char num) {
        if (num == 'a' || num == 'e' || num == 'i' || num == 'o' ||
            num == 'u' || num == 'A' || num == 'E' || num == 'I' ||
            num == 'O' || num == 'U') {
            return true;
        }
        return false;
    }

    string reverseVowels(string s) {

        int i = 0;
        int j = s.size() - 1;
        while (i <= j) {
            if (isVowel(s[i]) && isVowel(s[j])) {
                swap(s[i], s[j]);
                i++;
                j--;
            } else if (isVowel(s[i]) && !isVowel(s[j])) {
                j--;
            } else {
                i++;
            }
        }
        return s;
    }
};