class Solution {
public:
    string getMinString(vector<int>& cnt) {
        string str = "";

        for (int i = 0; i < 26; i++) {
            if (cnt[i] > 0) {
                str += string(cnt[i], 'a' + i);
            }
        }
        return str;
    }

    string lexGreaterPermutation(string s, string target) {
        int n = s.size();
        vector<int> cnt(26);

        for (int i = 0; i < s.size(); i++) {
            cnt[s[i] - 'a']++;
            cnt[target[i] - 'a']--;
        }

        for (int i = n - 1; i >= 0; i--) {
            int ch = target[i] - 'a';
            cnt[ch]++;

            if (*min_element(cnt.begin(), cnt.end()) < 0) {
                continue;
            }

            for (int j = ch + 1; j < 26; j++) {
                if (cnt[j]) {
                    cnt[j]--;
                    target[i] = 'a' + j;
                    target.resize(i + 1);
                    return target + getMinString(cnt);
                }
            }
        }
        return "";
    }
};