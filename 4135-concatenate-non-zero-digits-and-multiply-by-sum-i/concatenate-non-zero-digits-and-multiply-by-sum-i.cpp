class Solution {
public:
    long long sumAndMultiply(int n) {

        int x = 0;
        int sum = 0;
        while (n > 0) {
            if (n % 10 == 0) {
                n /= 10;
                continue;
            }
            sum += n % 10;
            x = x * 10 + n % 10;
            n /= 10;
        }

        int y = 0;
        while (x > 0) {
            y = y * 10 + x % 10;
            x /= 10;
        }

        return (long long)y * sum;
    }
};