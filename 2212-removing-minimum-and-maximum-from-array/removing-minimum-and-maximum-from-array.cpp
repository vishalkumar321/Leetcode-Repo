class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;

        int mini = INT_MAX;
        int maxi = INT_MIN;

        for (int i = 0; i < n; i++) {
            mp[nums[i]] = i;
            mini = min(mini, nums[i]);
            maxi = max(maxi, nums[i]);
        }

        int minDelFromBothEnd =
            min(mp[mini] + 1, n - mp[mini]) + min(mp[maxi] + 1, n - mp[maxi]);
        int minDelFromRight = n - min(mp[mini], mp[maxi]);
        int minDelFromLeft = max(mp[mini], mp[maxi]) + 1;

        return min({minDelFromBothEnd, minDelFromRight, minDelFromLeft});
    }
};