class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {

        unordered_map<string, string> mp;

        for (auto& it : knowledge) {
            mp[it[0]] = it[1];
        }

        bool flag = false;
        string key = "";
        string res = "";

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                flag = true;
                key = "";
            } 
            else if (s[i] == ')') {
                if (mp.find(key) != mp.end()) {
                    res += mp[key];
                } else {
                    res += "?";
                }
                flag = false;
            }
            else if (flag) {
                key.push_back(s[i]);
            } 
            else {
                res.push_back(s[i]);
            }
        }
        return res;
    }
};