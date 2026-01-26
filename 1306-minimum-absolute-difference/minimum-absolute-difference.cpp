class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        vector<vector<int>> ans;
        int minAbsDiff = INT_MAX;

        for (int i = 1; i < n; i++) {
            minAbsDiff = min(minAbsDiff, abs(arr[i] - arr[i - 1]));
        }

        for (int i = 1; i < n; i++) {
            if (abs(arr[i] - arr[i - 1]) == minAbsDiff) {
                ans.push_back({arr[i - 1], arr[i]});
            }
        }
        return ans;
    }
};