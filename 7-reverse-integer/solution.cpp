class Solution {
public:
    int reverse(long long int x){

        long long int i,rem,sum=0;
         int a= -2147483648 ;
         int b=  2147483647;
       
        for(i=0;x!=0;i++){
            rem =x%10;
            sum=sum*10+rem;
            x=x/10;
        }
        if(sum<= a || sum>b){
            sum=0;
        }
         return sum;
    }
};