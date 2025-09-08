class Solution {
public:
    int mySqrt(int x) {
        
        int ans;
        int start=0;
        int end= x;
        long long int mid=(start+end)/2;

       while(start<=end){
           long long int square= mid*mid;
           if(square==x){
               return mid;
           }
           else if(square<x){
            ans=mid;
            start=mid+1;
           }
           else {
               end =mid-1;
           }
           mid=(start+end)/2;
       }
       return mid;
    }
};