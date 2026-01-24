class Solution {
public:
    string reverseWords(string s) {

        int i = 0;
        int j = 0;
        int n = s.size();

        while (i < n) {
            while (i < n && s[i] == ' ')
                i++;

            while (i < n && s[i] != ' ') {
                s[j] = s[i];
                j++;
                i++;
            }

            while (i < n && s[i] == ' ')
                i++;

            if (i < n) {
                s[j] = ' ';
                j++;
            }
        }

        s.resize(j);
        int size = s.size();
        reverse(s.begin(), s.end());

        int start = 0;
        for (int j = 0; j <= size; j++) {
            if (j == size || s[j] == ' ') {
                reverse(s.begin() + start, s.begin() + j);
                start = j + 1;
            }
        }
        return s;
    }
};