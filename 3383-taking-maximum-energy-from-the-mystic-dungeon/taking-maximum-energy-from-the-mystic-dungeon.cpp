class Solution {
public:
    long long maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
        long long ans = LLONG_MIN;
        
        for (int start = n - k; start < n; start++) {
            long long s = 0;
           
            for (int i = start; i >= 0; i -= k) {
                s += energy[i];
                ans = max(ans, s);
            }
        }
        return ans;
    }
};
