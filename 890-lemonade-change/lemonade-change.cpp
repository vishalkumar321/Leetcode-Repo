class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n = bills.size();
        int cnt5 = 0;
        int cnt10 = 0;

        for (int i = 0; i < n; i++) {
            if (bills[i] == 5) {
                cnt5++;
            } else if (bills[i] == 10) {
                cnt5--;
                cnt10++;
            } else {
                if (cnt10 && cnt5) {
                    cnt10--;
                    cnt5--;
                } else {
                    cnt5 = cnt5 - 3;
                }
            }
            if (cnt5 < 0) {
                return false;
            }
        }
        return true;
    }
};