class Solution {
public:

    const int MOD = 1e9 +7;

    long long modExp(long long base, long long exp){
        if(exp==0) return 1;
        long long half = modExp(base, exp/2);
        half = (half* half)% MOD;

        if(exp%2==0){
            return half;
        }
        else{
            return (half*base)%MOD;
        }
    }

    int countGoodNumbers(long long n) {

        long long evenCount = (n+1)/2;
        long long oddCount = n/2;

        return (modExp(5,evenCount)*modExp(4,oddCount))%MOD;
    }
};