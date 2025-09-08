class Solution {
public:
    bool checkValidString(string s) {
        int high = 0;
        int low = 0;

        for (int c : s) {
            if (c == '(') {
                high++;
                low++;
            } else if (c == ')') {
                high--;
                low--;
            } else {
                low--;
                high++;
            }
            if (high < 0)
                return false;
            if (low < 0)
                low = 0;
        }
        return (low == 0);
    }
};