class Solution {
public:
    bool judgePoint24(vector<int>& cards) {
        vector<double> nums(cards.begin(), cards.end());
        return solve(nums);
    }

private:
    const double EPS = 1e-6;

    bool solve(vector<double> nums) {
        int n = nums.size();
        if (n == 1)
            return fabs(nums[0] - 24) < EPS;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j)
                    continue;
                vector<double> next;
                for (int k = 0; k < n; k++) {
                    if (k != i && k != j)
                        next.push_back(nums[k]);
                }
                for (double res : compute(nums[i], nums[j])) {
                    next.push_back(res);
                    if (solve(next))
                        return true;
                    next.pop_back();
                }
            }
        }
        return false;
    }

    vector<double> compute(double a, double b) {
        vector<double> results;
        results.push_back(a + b);
        results.push_back(a - b);
        results.push_back(b - a);
        results.push_back(a * b);
        if (fabs(b) > EPS)
            results.push_back(a / b);
        if (fabs(a) > EPS)
            results.push_back(b / a);
        return results;
    }
};
