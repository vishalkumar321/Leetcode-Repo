class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> maxReach(n + 1, 0);

        for (int i = 0; i <= n; i++) {
            int L = max(0, i - ranges[i]);
            int R = min(n, i + ranges[i]);
            maxReach[L] = max(maxReach[L], R);
        }

        int taps = 0;
        int currEnd = 0;
        int farthest = 0;

        for (int i = 0; i <= n; i++) {
            if (i > farthest)
                return -1;

            farthest = max(farthest, maxReach[i]);

            if (i == currEnd) {
                if (currEnd == n)
                    break;
                taps++;
                currEnd = farthest;
            }
        }

        return taps;
    }
};