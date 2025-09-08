class Solution {
public:
    string removeOuterParentheses(string s) {
        string res = "";
        int j = 0;

        for(int i=0; i<s.size(); i++){
            
            if(s[i]==')'){
                j--;
            }
            if(j!=0){
                res = res+ s[i];
            }
            if(s[i]== '('){
                j++;
            }
        }
        return res;
    }
};