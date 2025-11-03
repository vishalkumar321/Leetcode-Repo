class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size();
        int mini = 0;
        int prev = 0;

        for (int i = 1; i < n; i++) {
            if (colors[i] == colors[prev]) {
                mini += min(neededTime[i], neededTime[prev]);
                if (neededTime[i] > neededTime[prev]) {
                    prev = i;
                }
            } else {
                prev = i;
            }
        }
        return mini;
    }
};