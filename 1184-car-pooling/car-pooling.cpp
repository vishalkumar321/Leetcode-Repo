class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> diff(1002, 0);

        for (auto& it : trips) {
            int num = it[0];
            int from = it[1];
            int to = it[2];

            diff[from] += num;
            diff[to] -= num;
        }

        for (int i = 0; i < 1001; i++) {
            if (i > 0) {
                diff[i] += diff[i - 1];
            }
            if (diff[i] > capacity) {
                return false;
            }
        }
        return true;
    }
};