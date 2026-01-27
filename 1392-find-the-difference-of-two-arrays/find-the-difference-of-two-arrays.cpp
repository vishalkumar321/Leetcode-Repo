// BRUTE FORCE APPROACH
class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<vector<int>> ans(2);

        for (int i = 0; i < n; i++) {
            bool found = false;
            for (int j = 0; j < m; j++) {
                if (nums1[i] == nums2[j]) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                bool already = false;
                for (int x : ans[0]) {
                    if (x == nums1[i]) {
                        already = true;
                        break;
                    }
                }
                if (!already)
                    ans[0].push_back(nums1[i]);
            }
        }

        for (int i = 0; i < m; i++) {
            bool found = false;
            for (int j = 0; j < n; j++) {
                if (nums2[i] == nums1[j]) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                bool already = false;
                for (int x : ans[1]) {
                    if (x == nums2[i]) {
                        already = true;
                        break;
                    }
                }
                if (!already)
                    ans[1].push_back(nums2[i]);
            }
        }
        return ans;
    }
};