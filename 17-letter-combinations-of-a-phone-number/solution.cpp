class Solution {
public:

    void letterComb(vector<string>&ans,string output,int index,string mapping[],string digit){

        if(digit.empty()) return;

        if(index>=digit.length()){
            ans.push_back(output);
            return;
        }

        int number = digit[index] - '0';
        string value = mapping[number];

        for(int i=0; i<value.length(); i++){
            output.push_back(value[i]);
            letterComb(ans,output,index+1,mapping,digit);
            output.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        string output;
        
        string mapping[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

        letterComb(ans,output,0,mapping,digits);
        return ans;
    }
};