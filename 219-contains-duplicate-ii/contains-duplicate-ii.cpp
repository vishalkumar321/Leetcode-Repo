class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> Idx;

        for (int i = 0; i < nums.size(); i++) {

            if (Idx.count(nums[i]) && i - Idx[nums[i]] <= k)
                return true;
            Idx[nums[i]] = i;
        }
        return false;
    }
};
