class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {

        set<int> xSet;

        for (auto& b : buildings) {
            xSet.insert(b[0]);
            xSet.insert(b[1]);
        }

        vector<int> xs(xSet.begin(), xSet.end());

        vector<vector<int>> ans;
        int prevHeight = 0;

        for (int x : xs) {

            int currHeight = 0;

            for (auto& b : buildings) {
                int left = b[0];
                int right = b[1];
                int height = b[2];

                if (left <= x && x < right) {
                    currHeight = max(currHeight, height);
                }
            }

            if (currHeight != prevHeight) {
                ans.push_back({x, currHeight});
                prevHeight = currHeight;
            }
        }

        return ans;
    }
};