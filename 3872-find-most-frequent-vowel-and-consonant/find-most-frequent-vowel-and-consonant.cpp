class Solution {
public:
    int maxFreqSum(string s) {

        int vowelCnt = 0;
        int consCnt = 0;
        unordered_map<int, int> freq;

        for (int i = 0; i < s.size(); i++) {
            freq[s[i]]++;
        }

        for (auto [ele, count] : freq) {
            if (ele == 'a' || ele == 'e' || ele == 'i' || ele == 'o' ||
                ele == 'u') {
                vowelCnt = max(vowelCnt, count);
            } else {
                consCnt = max(consCnt, count);
            }
        }
        return vowelCnt + consCnt;
    }
};