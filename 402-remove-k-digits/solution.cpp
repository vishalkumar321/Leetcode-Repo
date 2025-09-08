class Solution {
public:
    string removeKdigits(string num, int k) {
        vector<char> stack;

        for(char digit : num){
            while(!stack.empty() && k>0 && stack.back()>digit){
                stack.pop_back();
                k--;
            }
            stack.push_back(digit);
        }

        while(k>0 && !stack.empty()){
            stack.pop_back();
            k--;
        }

        bool leadingZeros = true;
        string res;
        for(char digit : stack){
            if(leadingZeros && digit=='0'){
                continue;
            }
            leadingZeros = false;
            res += digit;
        }
        return res.empty() ? "0": res;
    }
};