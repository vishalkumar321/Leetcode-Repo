class Solution {
public:
    unordered_set<int> isTravelNeeded;

    int solve(int currDay, vector<int>& days, vector<int>& costs,
              vector<int>& dp) {
        if (currDay > days[days.size() - 1]) {
            return 0;
        }

        if (isTravelNeeded.find(currDay) == isTravelNeeded.end()) {
            return solve(currDay + 1, days, costs, dp);
        }

        if (dp[currDay] != -1) {
            return dp[currDay];
        }

        int oneDay = costs[0] + solve(currDay + 1, days, costs, dp);
        int sevenDay = costs[1] + solve(currDay + 7, days, costs, dp);
        int thirtyDay = costs[2] + solve(currDay + 30, days, costs, dp);

        dp[currDay] = min({oneDay, sevenDay, thirtyDay});
        return dp[currDay];
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int lastDay = days[days.size() - 1];
        vector<int> dp(lastDay + 1, -1);

        for (int day : days) {
            isTravelNeeded.insert(day);
        }

        return solve(1, days, costs, dp);
    }
};