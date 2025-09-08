class Solution {
public:
    int myAtoi(string s) {
        long result = 0;
        int sign = 1;
        bool firstNum = false;
        for(int i = 0; i < s.size(); i++) {
            // if whitespace, skip
            if(s[i] == ' ' && firstNum == false) {
                continue;
            }
            // checking for negative
            else if(s[i] == '-' && firstNum == false) {
                sign = -1;
                firstNum = true;
                // if(result > 0) {
                //     break;
                // }
                continue;
            }
            else if(s[i] == '+' && firstNum == false) {
                firstNum = true;
                continue;
            }
            //  checking for the integer value
            else if(s[i] >= '0' && s[i] <= '9') {
                firstNum = true;
                int digit = s[i] - '0';
                result = (result * 10) + digit;
                if(sign*result <INT_MIN) return INT_MIN;
                if(sign*result >INT_MAX) return INT_MAX;
                
            }
            // checking for the value other than integer
            else {
                break;
            }
        }
        return (result*sign);
    }
};