class Solution {
public:
    bool isPalindrome(int x) {
        
         if(x<0){
            return false;
        }
        int rem,i;
        long long int sum=0;
        int n=x;
        for(i=0;x!=0;i++){

            rem =x%10;
            sum =10*sum+rem;
            x=x/10;
        }
        
        
        if(sum==n){
            return true;
        }
        
        else{
           return false;
        }


    
    }
};