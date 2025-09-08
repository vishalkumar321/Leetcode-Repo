class Solution {
public:
    int possible(vector<int>& bloomDay, int m, int k, int day) {
        int bouquet = 0;
        int length = 0;

        for (int b : bloomDay) {
            if (b <= day) {
                length++;
                if (length == k) {
                    bouquet++;
                    length = 0;
                }
            } else {
                length = 0;
            }
        }
        return bouquet >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long required = 1LL * m * k;
        if (required > bloomDay.size())
            return -1;
        int ans = -1;

        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (possible(bloomDay, m, k, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};