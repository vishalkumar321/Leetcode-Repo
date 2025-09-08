class Solution {
public:

    void backTrack(string num,int index, int target,long eval, long lastoperand, string  expr,vector<string>& result){

        if(index==num.size()){
            if(eval==target){
                result.push_back(expr);
            }
            return;
        }

        for(int i = index; i<num.size(); i++){

            if(i!=index && num[index]=='0') break;

            string currStr = num.substr(index, i-index+1);
            long currNum = stol(currStr);

            if(index==0){
                backTrack(num, i+1, target,currNum, currNum, currStr, result);
            }
            else{
                 backTrack(num, i+1, target, eval+currNum, currNum, expr + "+" + currStr, result);
                 backTrack(num, i+1, target, eval-currNum, -currNum, expr + "-" + currStr, result);
                 backTrack(num, i+1, target, eval-lastoperand+lastoperand*currNum, lastoperand*currNum, expr + "*" + currStr, result);
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        vector<string> result;
        backTrack(num, 0, target, 0, 0, "", result);
        return result;
    }
};