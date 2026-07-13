class Solution {
public:
    void recurse(string& s, int index, int leftCount, int rightCount,
                 string& expression, int removedCount,
                 unordered_set<string>& validExpressions, int& minimumRemoved) {

        if (index == s.size()) {
            if (leftCount == rightCount) {
                if (removedCount <= minimumRemoved) {
                    if (removedCount < minimumRemoved) {
                        validExpressions.clear();
                        minimumRemoved = removedCount;
                    }
                    validExpressions.insert(expression);
                }
            }
            return;
        }

        char ch = s[index];

        if (ch != '(' && ch != ')') {
            expression.push_back(ch);
            recurse(s, index + 1, leftCount, rightCount, expression,
                    removedCount, validExpressions, minimumRemoved);
            expression.pop_back();
        } else {

            recurse(s, index + 1, leftCount, rightCount, expression,
                    removedCount + 1, validExpressions, minimumRemoved);

            expression.push_back(ch);

            if (ch == '(') {
                recurse(s, index + 1, leftCount + 1, rightCount, expression,
                        removedCount, validExpressions, minimumRemoved);
            } else if (rightCount < leftCount) {
                recurse(s, index + 1, leftCount, rightCount + 1, expression,
                        removedCount, validExpressions, minimumRemoved);
            }
            expression.pop_back();
        }
    }

    vector<string> removeInvalidParentheses(string s) {
        unordered_set<string> validExpressions;
        int minimumRemoved = INT_MAX;
        string expression;

        recurse(s, 0, 0, 0, expression, 0, validExpressions, minimumRemoved);

        return vector<string>(validExpressions.begin(), validExpressions.end());
    }
};