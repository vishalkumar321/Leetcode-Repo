class Solution {
public:
    vector<vector<string>> findMismatchedSegments(string s1, string s2) {

        int n = s1.size();
        vector<vector<string>> ans;

        int last = -1;
        int curr = 0;
        bool flag = true;

        for (int i = 0; i < n; i++) {
            vector<string> curr;
            if (s1[i] != s2[i] && flag) {
                last = i;
                flag = false;
            }
            else if (s1[i] == s2[i]) {
                if (last != -1) {
                    curr.push_back(s1.substr(last, i - last));
                    curr.push_back(s2.substr(last, i - last));
                    ans.push_back(curr);
                    flag = true;
                    last = -1;
                } else {
                    continue;
                }
            }
            if (last != -1 && i == n - 1) {
                curr.push_back(s1.substr(last, n - last));
                curr.push_back(s2.substr(last, n - last));
                ans.push_back(curr);
            }
        }

        return ans;
    }
};