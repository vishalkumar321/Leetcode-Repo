class Solution {
public:
    int minimumDistance(vector<int>& nums) {

        unordered_map<int, vector<int>> freq;
        int ans = INT_MAX;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            freq[nums[i]].push_back(i);
        }

        for (auto& it : freq) {
            auto& v = it.second;

            if (v.size() < 3)
                continue;

            for (int i = 0; i < v.size() - 2; i++) {
                int a = v[i];
                int b = v[i + 1];
                int c = v[i + 2];

                int dist = abs(a - b) + abs(b - c) + abs(c - a);
                ans = min(ans, dist);
            }
        }
        if (ans == INT_MAX)
            return -1;
        return ans;
    }
};