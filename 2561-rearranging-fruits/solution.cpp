class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        map<int, int> freq;

        for (int i = 0; i < basket1.size(); i++) {
            freq[basket1[i]]++;
        }
        for (int i = 0; i < basket2.size(); i++) {
            freq[basket2[i]]--;
        }

        vector<int> fruitsToSwap;
        int mini = INT_MAX;

        for (auto& [fruit, count] : freq) {
            mini = min(mini, fruit);

            if (count % 2 != 0)
                return -1;

            for (int i = 0; i < abs(count) / 2; i++) {
                fruitsToSwap.push_back(fruit);
            }
        }
        sort(fruitsToSwap.begin(), fruitsToSwap.end());

        long long ans = 0;
        for (int i = 0; i < fruitsToSwap.size() / 2; i++) {
            ans += min(fruitsToSwap[i], 2 * mini);
        }
        return ans;
    }
};