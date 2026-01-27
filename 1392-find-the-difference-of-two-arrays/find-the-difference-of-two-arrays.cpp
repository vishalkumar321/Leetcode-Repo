class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> ele1;
        unordered_set<int> ele2;
        vector<vector<int>> ans;
        vector<int> first, second;

        for (int x : nums1) {
            ele1.insert(x);
        }
        for (int x : nums2) {
            ele2.insert(x);
        }

        for (int x : ele1) {
            if (ele2.find(x) == ele2.end()) {
                first.push_back(x);
            }
        }

        for (int x : ele2) {
            if (ele1.find(x) == ele1.end()) {
                second.push_back(x);
            }
        }

        ans.push_back(first);
        ans.push_back(second);
        return ans;
    }
};