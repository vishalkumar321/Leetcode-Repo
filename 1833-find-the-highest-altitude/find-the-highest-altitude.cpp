// OPTIMAL SOLUTION
class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        int prefix = 0;
        int highAlti = 0;

        for (int i = 0; i < n; i++) {
            prefix += gain[i];
            highAlti = max(highAlti, prefix);
        }
        return highAlti;
    }
};