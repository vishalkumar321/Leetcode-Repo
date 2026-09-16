class Solution {
public:
    void solve(int idx, string& digits, string curr, string combination[],
               vector<string>& ans) {

        if (idx == digits.size()) {
            ans.push_back(curr);
            return;
        }

        int num = digits[idx] - '0';
        string dig = combination[num];

        for (int j = 0; j < dig.size(); j++) {
            curr.push_back(dig[j]);
            solve(idx + 1, digits, curr, combination, ans);
            curr.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {

        vector<string> ans;
        string combination[] = {"",    "",    "abc",  "def", "ghi",
                                "jkl", "mno", "pqrs", "tuv", "wxyz"};

        solve(0, digits, "", combination, ans);
        return ans;
    }
};