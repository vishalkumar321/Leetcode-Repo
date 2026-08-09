class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {

        vector<vector<int>> ans;

        // {height, right}
        priority_queue<pair<int, int>> pq;

        int i = 0;
        int n = buildings.size();

        while (i < n || !pq.empty()) {

            int x;

            // Next building starts before the current tallest building ends
            if (pq.empty() || 
                (i < n && buildings[i][0] <= pq.top().second)) {

                x = buildings[i][0];

                // Add all buildings starting at x
                while (i < n && buildings[i][0] == x) {
                    int left = buildings[i][0];
                    int right = buildings[i][1];
                    int height = buildings[i][2];

                    pq.push({height, right});
                    i++;
                }

            } else {

                // Current tallest building ends
                x = pq.top().second;

                // Remove all buildings that ended by x
                while (!pq.empty() && pq.top().second <= x) {
                    pq.pop();
                }
            }

            int currHeight = pq.empty() ? 0 : pq.top().first;

            if (ans.empty() || ans.back()[1] != currHeight) {
                ans.push_back({x, currHeight});
            }
        }

        return ans;
    }
};