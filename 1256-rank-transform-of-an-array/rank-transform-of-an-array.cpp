class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {

        int n = arr.size();
        vector<int> ans(n, 1);

        vector<pair<int, int>> nums;

        for (int i = 0; i < n; i++) {
            nums.push_back({arr[i], i});
        }

        sort(nums.begin(), nums.end());

        int rank = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i].first == nums[i - 1].first) {
                ans[nums[i].second] = rank;
            } else {
                rank++;
                ans[nums[i].second] = rank;
            }
        }
        return ans;
    }
};