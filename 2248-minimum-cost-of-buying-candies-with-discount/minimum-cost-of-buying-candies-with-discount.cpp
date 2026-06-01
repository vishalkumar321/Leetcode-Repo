class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n = cost.size();
        sort(cost.begin(), cost.end());
        int minCost = 0;
        int j = 0;

        for (int i = n - 1; i >= 0; i--) {
            if (j != 2) {
                minCost += cost[i];
                j++;
            } else {
                j = 0;
            }
        }
        return minCost;
    }
};