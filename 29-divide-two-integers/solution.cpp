// class Solution {
// public:
//     int divide(int dividend, int divisor) {
//         return dividend/divisor;
//     }
// };

// SIMPLE SUBSTRACTION METHOD
// class Solution {
// public:
//     int divide(int dividend, int divisor) {

//         if (dividend == INT_MIN && divisor == -1) {
//             return INT_MAX;
//         }

//         int negative = (dividend < 0) ^ (divisor < 0);
//         long a = abs((long)dividend);
//         long b = abs((long)divisor);
//         int count = 0;

//         while (a >= b) {
//             a -= b;
//             count++;
//         }
//         return negative ? -count : count;
//     }
// };

// BIT MANIPULATION APPROACH
class Solution {
public:
    int divide(int dividend, int divisor) {

        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }

        int negative = (dividend < 0) ^ (divisor < 0);
        long a = abs((long)dividend);
        long b = abs((long)divisor);
        long result = 0;

        for (int i = 31; i >= 0; i--) {
            if ((a >> i) >= b) {
                result += 1L << i;
                a -= b << i;
            }
        }
        return negative ? -result : result;
    }
};