// BIT MANIPULATION APPROACH
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n>0 && ((n&n-1)==0);
    }
};

// BUILT-IN FUNCTION APPROACH
// class Solution {
// public:
//     bool isPowerOfTwo(int n) {
//         return n>0 && __builtin_popcount(n)==1;
//     }
// };

// ITERATIVE APPROACH
// class Solution {
// public:
//     bool isPowerOfTwo(int n) {
//         if(n<=0) return false;
//         while(n%2==0){
//             n/=2;
//         }
//         return n==1;
//     }
// };