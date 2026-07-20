class Solution {
public:
    int unequalTriplets(vector<int>& nums) {

        unordered_map<int, int> countMap;

        for (int it : nums) {
            countMap[it]++;
        }

        int left = 0;
        int triplets = 0;
        int right = nums.size();

        for (auto& [num, count] : countMap) {
            right -= count;
            triplets += left * count * right;
            left += count;
        }
        return triplets;
    }
};