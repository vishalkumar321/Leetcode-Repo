// BRUTE FORCE APPROACH
class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        int highAlti = INT_MIN;

        for (int i = 0; i < n; i++) {
            int current = 0;
            for (int j = 0; j <= i; j++) {
                current += gain[j];
            }
            highAlti = max(highAlti, current);
        }
        if (highAlti < 0) {
            return 0;
        }
        return highAlti;
    }
};