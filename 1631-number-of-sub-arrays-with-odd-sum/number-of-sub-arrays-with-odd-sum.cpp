class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {

        int n = arr.size();
        int prefixSum = 0;
        int oddCnt = 0;
        int evenCnt = 1;
        int ans = 0;
        int MOD = 1e9 + 7;

        for (int i = 0; i < n; i++) {
            prefixSum += arr[i];

            if (prefixSum % 2 == 0) {
                ans += oddCnt;
                evenCnt++;
            } else {
                ans += evenCnt;
                oddCnt++;
            }
            ans %= MOD;
        }
        return ans;
    }
};