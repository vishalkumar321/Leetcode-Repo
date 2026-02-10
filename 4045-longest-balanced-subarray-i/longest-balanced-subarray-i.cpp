class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        int longest = 0;

        for (int i = 0; i < n; i++) {
            unordered_set<int> seen;
            int oddCnt = 0;
            int evenCnt = 0;
            for (int j = i; j < n; j++) {
                if (!seen.count(nums[j])) {
                    seen.insert(nums[j]);
                    if (nums[j] % 2 == 0) {
                        evenCnt++;
                    } else {
                        oddCnt++;
                    }
                }

                if (evenCnt == oddCnt) {
                    longest = max(longest, j - i + 1);
                }
                // cout << "odd: " << j << " : " << oddCnt << endl;
                // cout << "even: " << j << " : " << evenCnt << endl;
            }
        }
        return longest;
    }
};