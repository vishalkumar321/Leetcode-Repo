class Solution {
public:
    void backTrack(vector<string>& ans, string current, int index,
                   string mapping[], string digit) {
        if (digit.empty())
            return;
        if (index >= digit.length()) {
            ans.push_back(current);
            return;
        }

        int number = digit[index] - '0';
        string value = mapping[number];

        for (int i = 0; i < value.length(); i++) {
            current.push_back(value[i]);
            backTrack(ans, current, index + 1, mapping, digit);
            current.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string current = "";

        string mapping[10] = {"",    "",    "abc",  "def", "ghi",
                              "jkl", "mno", "pqrs", "tuv", "wxyz"};

        backTrack(ans, current, 0, mapping, digits);
        return ans;
    }
};