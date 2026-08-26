class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {

        vector<pair<int, long long>> events;

        for (auto& it : segments) {
            int start = it[0];
            int end = it[1];
            int color = it[2];

            events.push_back({start, color});
            events.push_back({end, -color});
        }

        sort(events.begin(), events.end());

        vector<vector<long long>> ans;

        int i = 0;
        long long currSum = 0;
        int prev = events[0].first;

        while (i < events.size()) {

            int pos = events[i].first;

            if (prev < pos && currSum > 0) {
                ans.push_back({prev, pos, currSum});
            }

            while (i < events.size() && events[i].first == pos) {
                currSum += events[i].second;
                i++;
            }
            prev = pos;
        }
        return ans;
    }
};