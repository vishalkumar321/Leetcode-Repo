class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {

        sort(nums.begin(), nums.end());
        long long nextAvailable = LLONG_MIN;
        int count = 0;

        for (int num : nums) {

            long long assigned = max((long long)num - k, nextAvailable);

            if (assigned <= (long long)num + k) {
                nextAvailable = assigned + 1;
                count++;
            }
        }
        return count;
    }
};