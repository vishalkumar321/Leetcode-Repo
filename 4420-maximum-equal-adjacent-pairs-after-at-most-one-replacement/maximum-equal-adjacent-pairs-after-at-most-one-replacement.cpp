class Solution {
public:
    int maxEqualAdjacentPairs(vector<int>& nums) {
        int n = nums.size();
        int base = 0;
        int maxFreq = 0;

        map<pair<int, int>, int> freq;

        for (int i = 1; i < n; i++) {
            int a = nums[i - 1];
            int b = nums[i];

            if (a == b) {
                base++;
            } else {
                int first = min(a, b);
                int second = max(a, b);

                freq[{first, second}]++;
                maxFreq = max(maxFreq, freq[{first, second}]);
            }
        }

        return base + maxFreq;
    }
};