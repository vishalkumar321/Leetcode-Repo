class Solution {
public:
    string reverseWords(string s) {
        int start =0;
        int end = s.size()-1;
        string temp = "";
        string ans = "";

        while(start<=end){
            if(s[start]!= ' '){
                temp = temp+ s[start];
            }
            else if(s[start] == ' ' && temp!=""){
                if(ans!= ""){
                    ans = temp + " "+ ans;
                }
                else{
                    ans= temp;
                }
                temp = "";
            }
            start++;
        }
        if(temp!= ""){
                if(ans!= ""){
                    ans = temp + " "+ ans;
                }
                else{
                    ans= temp;
                }
            }
        return ans;
    }
};