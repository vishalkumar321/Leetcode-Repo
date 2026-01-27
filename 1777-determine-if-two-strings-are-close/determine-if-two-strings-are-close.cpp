class Solution {
public:
    bool closeStrings(string word1, string word2) {

        unordered_map<char, int> freq1;
        unordered_map<char, int> freq2;

        for (int i = 0; i < word1.size(); i++) {
            freq1[word1[i]]++;
        }

        for (int i = 0; i < word2.size(); i++) {
            freq2[word2[i]]++;
        }

        vector<int> v1, v2;
        for (auto it : freq1) {
            char ch = it.first;
            v1.push_back(it.second);

            if (freq2.find(ch) == freq2.end()) {
                return false;
            }
        }

        for (auto it : freq2) {
            char ch = it.first;
            v2.push_back(it.second);

            if (freq1.find(ch) == freq1.end()) {
                return false;
            }
        }

        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());

        for (int i = 0; i < v1.size(); i++) {
            if (v1[i] != v2[i]) {
                return false;
            }
        }
        return true;
    }
};