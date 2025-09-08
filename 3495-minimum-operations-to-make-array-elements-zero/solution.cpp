class Solution {
public:
    long long prefix(long long n) {
        if (n <= 0)
            return 0;
        long long sum = 0, start = 1;
        int step = 1;
        while (start <= n) {
            long long end = min(n, (1LL << (2 * step)) - 1);
            long long count = end - start + 1;
            sum += count * step;
            start <<= 2;
            step++;
        }
        return sum;
    }

    long long minOperations(vector<vector<int>>& queries) {
        long long ans = 0;
        for (auto& qr : queries) {
            long long l = qr[0], r = qr[1];
            long long total = prefix(r) - prefix(l - 1);
            ans += (total + 1) / 2;
        }
        return ans;
    }
};
