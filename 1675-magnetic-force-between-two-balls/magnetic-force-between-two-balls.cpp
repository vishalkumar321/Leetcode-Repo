class Solution {
public:
    bool canPlace(vector<int>& position, int mid, int n, int m) {
        int lastPos = position[0];
        int cnt = 1;

        for (int i = 1; i < n; i++) {
            if (lastPos + mid <= position[i]) {
                lastPos = position[i];
                cnt++;
            }
        }
        return cnt >= m;
    }

    int maxDistance(vector<int>& position, int m) {
        int n = position.size();

        sort(position.begin(), position.end());

        int low = 1;
        int high = position[n - 1] - position[0];

        while (low < high) {
            int mid = low + (high - low + 1) / 2;

            if (canPlace(position, mid, n, m)) {
                low = mid;
            } else {
                high = mid - 1;
            }
        }
        return low;
    }
};