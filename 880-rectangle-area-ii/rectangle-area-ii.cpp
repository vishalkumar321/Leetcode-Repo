class Solution {
public:
    int rectangleArea(vector<vector<int>>& rectangles) {
        const long long MOD = 1e9 + 7;

        vector<vector<int>> events;

        for (auto& r : rectangles) {
            events.push_back({r[0], r[1], r[3], 1});
            events.push_back({r[2], r[1], r[3], -1});
        }

        sort(events.begin(), events.end());

        vector<pair<int, int>> active;

        long long area = 0;
        int prevX = events[0][0];

        int i = 0;

        while (i < events.size()) {
            int x = events[i][0];

            sort(active.begin(), active.end());

            long long yLength = 0;

            if (!active.empty()) {
                int start = active[0].first;
                int end = active[0].second;

                for (int j = 1; j < active.size(); j++) {
                    if (active[j].first <= end) {
                        end = max(end, active[j].second);
                    } else {
                        yLength += end - start;
                        start = active[j].first;
                        end = active[j].second;
                    }
                }

                yLength += end - start;
            }

            area += (long long)(x - prevX) * yLength;
            area %= MOD;

            while (i < events.size() && events[i][0] == x) {
                int y1 = events[i][1];
                int y2 = events[i][2];
                int type = events[i][3];

                if (type == 1) {
                    active.push_back({y1, y2});
                } else {
                    for (int j = 0; j < active.size(); j++) {
                        if (active[j].first == y1 &&
                            active[j].second == y2) {
                            active.erase(active.begin() + j);
                            break;
                        }
                    }
                }

                i++;
            }

            prevX = x;
        }

        return area;
    }
};