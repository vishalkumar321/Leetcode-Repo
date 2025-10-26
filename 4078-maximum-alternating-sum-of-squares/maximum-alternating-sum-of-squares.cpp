class Solution {
public:
    vector<int> rearrangement(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end(),
             [](int a, int b) { return abs(a) < abs(b); });

        int i = 0;
        int j = n - 1;
        vector<int> rearg;
        bool alternate = true;

        while (i <= j) {
            if (alternate) {
                rearg.push_back(nums[j--]);
            } else if (!alternate) {
                rearg.push_back(nums[i++]);
            }
            alternate = !alternate;
        }
        return rearg;
    }

    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        long long sum = 0;
        vector<int> res = rearrangement(nums);

        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                sum += 1LL * res[i] * res[i];
            } else {
                sum -= 1LL * res[i] * res[i];
            }
        }
        return sum;
    }
};