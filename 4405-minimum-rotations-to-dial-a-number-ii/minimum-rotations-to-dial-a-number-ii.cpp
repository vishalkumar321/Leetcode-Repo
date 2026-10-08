class Solution {
public:
    int dist(int a, int b) {
        int d = abs(a - b);
        return min(d, 10 - d);
    }

    int minRotations(int n, string s) {
        // Original cost
        int total = dist(0, s[0] - '0');

        for (int i = 1; i < n; i++) {
            total += dist(s[i - 1] - '0', s[i] - '0');
        }

        int ans = total;

        // Try reversing suffix starting at k
        for (int k = 0; k < n; k++) {
            int newCost = total;

            if (k == 0) {
                // Original:
                // 0 -> s[0]
                // After reversing:
                // 0 -> s[n-1]
                newCost -= dist(0, s[0] - '0');
                newCost += dist(0, s[n - 1] - '0');

                // Last edge changes:
                // s[n-2] -> s[n-1]
                // becomes
                // s[0] -> s[n-2]
                // if (n > 1) {
                //     newCost -= dist(s[n - 2] - '0',
                //                     s[n - 1] - '0');

                //     newCost += dist(s[0] - '0',
                //                     s[n - 2] - '0');
                // }
            } else {
                // Edge entering the suffix:
                // s[k-1] -> s[k]
                // becomes
                // s[k-1] -> s[n-1]
                newCost -= dist(s[k - 1] - '0', s[k] - '0');

                newCost += dist(s[k - 1] - '0', s[n - 1] - '0');

                // Last edge:
                // s[n-2] -> s[n-1]
                // becomes
                // s[k] -> s[n-2]
                // if (k < n - 1) {
                //     newCost -= dist(s[n - 2] - '0',
                //                     s[n - 1] - '0');

                //     newCost += dist(s[k] - '0',
                //                     s[n - 2] - '0');
                // }
            }

            ans = min(ans, newCost);
        }

        return ans;
    }
};