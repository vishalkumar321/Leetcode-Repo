class Solution {
public:
    int sumOfTheDigitsOfHarshadNumber(int x) {
        

        int sum=0,n=x;
       //for(int i=0;x!=0;i++){
        while(x!=0){
        int rem = x % 10;
            sum = sum+rem;
            x = x/10;
       }
       if(n % sum == 0){
        return sum;
       }
       else{
        return -1;
       }
    }
};