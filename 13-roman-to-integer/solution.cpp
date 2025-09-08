class Solution {
public:
    int getValue(char c){
        if(c=='I') return 1;
        if(c=='V') return 5;
        if(c=='X') return 10;
        if(c=='L') return 50;
        if(c=='C') return 100;
        if(c=='D') return 500;
        if(c=='M') return 1000;
            return 0;
        }
public:
    int romanToInt(string s) {
        int ans = 0;

       for(int i=0; i<s.size(); i++){
            if(getValue(s[i])<getValue(s[i+1])){
                ans = ans - getValue(s[i]);
            }
            else{
                ans = ans + getValue(s[i]);
            }
       } 
       return ans;
    }
};