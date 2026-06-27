class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        vector<vector<string>> ans;
        unordered_map<string, vector<string>> mp;

        for (auto it : strs) {

            vector<int> freq(26, 0);
            for (auto i : it) {
                freq[i - 'a']++;
            }

            string key = "";
            for (auto i : freq) {
                key += to_string(i) + '#';
            }
            mp[key].push_back(it);
        }

        for (auto it : mp) {
            ans.push_back(it.second);
        }
        return ans;
    }
};
