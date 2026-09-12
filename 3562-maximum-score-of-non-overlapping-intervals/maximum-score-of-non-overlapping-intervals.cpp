class Solution {
public:

    long long solve(int i, int count,
                    vector<vector<int>>& arr,
                    vector<int>& next,
                    vector<vector<long long>>& dp,
                    vector<vector<vector<int>>>& ans) {

        int n = arr.size();

        if (i == n || count == 4)
            return 0;

        if (dp[i][count] != -1)
            return dp[i][count];

        long long skip = solve(i + 1, count, arr, next, dp, ans);

        long long take = arr[i][2] +
                         solve(next[i], count + 1, arr, next, dp, ans);

        if (take > skip) {
            ans[i][count] = ans[next[i]][count + 1];
            ans[i][count].push_back(arr[i][3]);

            sort(ans[i][count].begin(), ans[i][count].end());
        }
        else if (skip > take) {
            ans[i][count] = ans[i + 1][count];
        }
        else {
            vector<int> takeAns = ans[next[i]][count + 1];
            takeAns.push_back(arr[i][3]);

            sort(takeAns.begin(), takeAns.end());

            vector<int> skipAns = ans[i + 1][count];

            if (takeAns < skipAns)
                ans[i][count] = takeAns;
            else
                ans[i][count] = skipAns;
        }

        return dp[i][count] = max(take, skip);
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {

        int n = intervals.size();

        vector<vector<int>> arr;

        for (int i = 0; i < n; i++) {
            arr.push_back({
                intervals[i][0],
                intervals[i][1],
                intervals[i][2],
                i
            });
        }

        sort(arr.begin(), arr.end());

        vector<int> next(n);

        for (int i = 0; i < n; i++) {

            int low = i + 1;
            int high = n;

            while (low < high) {

                int mid = low + (high - low) / 2;

                if (arr[mid][0] > arr[i][1])
                    high = mid;
                else
                    low = mid + 1;
            }

            next[i] = low;
        }

        vector<vector<long long>> dp(
            n + 1,
            vector<long long>(5, -1)
        );

        vector<vector<vector<int>>> ans(
            n + 1,
            vector<vector<int>>(5)
        );

        solve(0, 0, arr, next, dp, ans);

        return ans[0][0];
    }
};