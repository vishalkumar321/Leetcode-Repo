class Solution {
public:
    int compress(vector<char>& chars) {
        int i = 0;
        int res = 0;
        int n = chars.size();

        while (i < n) {
            int length = 1;
            while (i + length < n && chars[i + length] == chars[i]) {
                length++;
            }
            chars[res] = chars[i];
            res++;
            if (length > 1) {
                for (auto c : to_string(length)) {
                    chars[res] = c;
                    res++;
                }
            }
            i += length;
        }
        return res;
    }
};