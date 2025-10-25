class Solution {
public:
    int totalMoney(int n) {

        int week = 0;
        int sum = 0;

        for (int i = 1; i <= n; i++) {
            sum += (i % 7 == 0 ? 7 + week : (i % 7) + week);
            if (i % 7 == 0)
                week++;
        }
        return sum;
    }
};