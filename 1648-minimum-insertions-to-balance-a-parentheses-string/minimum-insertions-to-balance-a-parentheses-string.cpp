class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        int insertions = 0;
        int idx = 0;
        int leftCnt = 0;

        while (idx < n) {
            if (s[idx] == '(') {
                leftCnt++;
                idx++;
            } else {
                if (leftCnt > 0) {
                    leftCnt--;
                } else {
                    insertions++;
                }
                if (idx < n - 1 && s[idx + 1] == ')') {
                    idx += 2;
                } else {
                    insertions++;
                    idx++;
                }
            }
        }
        insertions += 2 * leftCnt;
        return insertions;
    }
};