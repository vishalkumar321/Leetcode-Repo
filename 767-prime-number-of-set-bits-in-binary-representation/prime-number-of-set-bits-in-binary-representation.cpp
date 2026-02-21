class Solution {
public:
    bool isPrime(int n) {
        if (n == 1)
            return false;

        for (int i = 2; i*i <= n; i++) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }

    int countBits(int n){
        int cnt = 0;

        while(n){
            n = n & (n-1);
            cnt++;
        }
        return cnt;
    }

    int countPrimeSetBits(int left, int right) {

        int cnt = 0;

        for (int i = left; i <= right; i++) {
            int bits = countBits(i);
            if (isPrime(bits)) {
                cnt++;
            }
        }
        return cnt;
    }
};