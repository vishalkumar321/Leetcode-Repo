class Solution {
public:
    int reverseDegree(string s) {

        int idx = 1;
        int ans = 0;

        for (auto& it : s) {
            ans += (('z' - it) + 1) * idx;
            idx++;
        }
        return ans;
    }
};