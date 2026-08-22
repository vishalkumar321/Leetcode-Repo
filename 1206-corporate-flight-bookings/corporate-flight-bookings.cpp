class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> ans(n + 2, 0);

        for (auto& it : bookings) {
            int start = it[0];
            int end = it[1];
            int seat = it[2];

            ans[start] += seat;
            ans[end + 1] -= seat;
        }

        for (int i = 1; i <= n; i++) {
            ans[i] += ans[i - 1];
        }
        ans.pop_back();
        ans.erase(ans.begin());
        return ans;
    }
};