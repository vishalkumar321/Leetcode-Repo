class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ans = 0;
        while (a || b || c) {
            int currA = a & 1;
            int currB = b & 1;
            int currC = c & 1;

            if ((currA | currB) != currC) {
                if ((currA | currB) == 0) {
                    ans++;
                } else {
                    ans += currA + currB;
                }
            }

            a = a >> 1;
            b = b >> 1;
            c = c >> 1;
        }
        return ans;
    }
};