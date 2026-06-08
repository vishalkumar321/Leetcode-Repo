class Solution {
public:
    void helper(int i, string digit, string curr, string combination[],
                vector<string>& ans) {

        if (i == digit.size()) {
            ans.push_back(curr);
            return;
        }

        int number = digit[i] - '0';
        string value = combination[number];

        for (int j = 0; j < value.size(); j++) {
            curr.push_back(value[j]);
            helper(i + 1, digit, curr, combination, ans);
            curr.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {

        string combination[10] = {"",    "",    "abc",  "def", "ghi",
                                  "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> ans;
        helper(0, digits, "", combination, ans);
        return ans;
    }
};