class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {

        for (int i = left; i <= right; i++) {
            bool flag = false;
            for (auto& it : ranges) {
                int first = it[0];
                int second = it[1];

                if ((first <= i && i <= second)) {
                    flag = true;
                    break;
                }
            }
            if (!flag) {
                return false;
            }
        }

        return true;
    }
};