class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n = fruits.size();
        int maxfruits = 0, total = 0;
        int i = 0;

        for (int j = 0; j < n; j++) {
            total += fruits[j][1];

            while (i <= j) {
                int left = fruits[i][0];
                int right = fruits[j][0];

                int dist1 = abs(startPos - left) + (right - left);
                int dist2 = abs(startPos - right) + (right - left);

                if (min(dist1, dist2) > k) {
                    total -= fruits[i][1];
                    i++;
                } else {
                    break;
                }
            }
            maxfruits = max(maxfruits, total);
        }
        return maxfruits;
    }
};