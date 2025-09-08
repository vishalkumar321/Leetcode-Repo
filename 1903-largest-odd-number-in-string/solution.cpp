class Solution {
public:
    string largestOddNumber(string num) {
        int start = 0;
        int end = num.size()-1;

        for(int i=0; i<num.size(); i++){
            if(num[end]%2!=0){
                return num.substr(0,end+1);
            }
            else{
                end--;
            }
        }
        return "";
    }
};