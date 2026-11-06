class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs,
                             int x, vector<int>& queries) {

        sort(logs.begin(), logs.end(),
             [](const auto& a, const auto& b) {
                 return a[1] < b[1];
             });

        int q = queries.size();

        vector<pair<int, int>> sortedQueries;

        for (int i = 0; i < q; i++) {
            sortedQueries.push_back({queries[i], i});
        }

        sort(sortedQueries.begin(), sortedQueries.end());

        vector<int> ans(q, 0);
        vector<int> cnt(n + 1, 0);

        int left = 0;
        int right = 0;
        int active = 0;

        for (auto [time, index] : sortedQueries) {

            int start = time - x;

            while (right < logs.size() &&
                   logs[right][1] <= time) {

                int id = logs[right][0];

                if (cnt[id] == 0) {
                    active++;
                }

                cnt[id]++;
                right++;
            }

            while (left < right &&
                   logs[left][1] < start) {

                int id = logs[left][0];

                cnt[id]--;

                if (cnt[id] == 0) {
                    active--;
                }

                left++;
            }

            ans[index] = n - active;
        }

        return ans;
    }
};