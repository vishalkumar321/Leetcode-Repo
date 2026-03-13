class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long left = 1;
        long long right = 1e18;
        long long ans = 0;

        while (left <= right) {
            long long mid = (left + right) / 2;
            long long total = 0;

            for (int t : workerTimes) {
                long long k = (sqrt(1 + 8.0 * mid / t) - 1) / 2;
                total += k;
            }

            if (total >= mountainHeight) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return ans;
    }
};