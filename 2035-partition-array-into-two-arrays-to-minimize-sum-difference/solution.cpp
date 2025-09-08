// Meet-in-the-Middle Approach
class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size(), sum = accumulate(nums.begin(), nums.end(), 0);
        int N = n / 2;
        vector<vector<int>> left(N + 1), right(N + 1);

        for (int mask = 0; mask < (1 << N); ++mask) {
            int idx = 0, l_sum = 0, r_sum = 0;
            for (int i = 0; i < N; ++i) {
                if (mask & (1 << i)) {
                    idx++;
                    l_sum += nums[i];
                    r_sum += nums[i + N];
                }
            }
            left[idx].push_back(l_sum);
            right[idx].push_back(r_sum);
        }

        for (int idx = 0; idx <= N; ++idx) {
            sort(right[idx].begin(), right[idx].end());
        }

        int res = min(abs(sum - 2 * left[N][0]), abs(sum - 2 * right[N][0]));

        for (int idx = 1; idx < N; ++idx) {
            for (auto& a : left[idx]) {
                int b = (sum - 2 * a) / 2;
                int rightidx = N - idx;
                auto& v = right[rightidx];
                auto itr = lower_bound(v.begin(), v.end(), b);
                if (itr != v.end())
                    res = min(res, abs(sum - 2 * (a + (*itr))));
                if (itr != v.begin()) {
                    --itr;
                    res = min(res, abs(sum - 2 * (a + (*itr))));
                }
            }
        }

        return res;
    }
};



// TABULATION FAILED DUE TO NEGATIVE VALUES
// class Solution {
// public:
//     int minimumDifference(vector<int>& nums) {
//         int n = nums.size();
//         int sum = accumulate(nums.begin(), nums.end(), 0);
//         int target = sum / 2;
//         vector<vector<bool>> dp(n, vector<bool>(target + 1, 0));

//         for (int i = 0; i < n; i++) {
//             dp[i][0] = true;
//         }
//         if (nums[0] <= target)
//             dp[0][nums[0]] = true;

//         for (int index = 1; index < n; index++) {
//             for (int t = 1; t <= target; t++) {
//                 bool notTake = dp[index - 1][t];
//                 bool take = false;
//                 if (nums[index] <= t) {
//                     take = dp[index - 1][t - nums[index]];
//                 }
//                 dp[index][t] = take || notTake;
//             }
//         }

//         int mini = 1e9;
//         for (int s1 = 0; s1 <= target; s1++) {
//             if (dp[n - 1][s1]) {
//                 mini = min(mini, abs((sum - s1) - s1));
//             }
//         }
//         return mini;
//     }
// };