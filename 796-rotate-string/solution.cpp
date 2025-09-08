class Solution {
public:
    bool rotateString(string s, string goal) {
       string ans = s+s;
        if(s.length()==goal.length() && ans.find(goal) != string::npos){
            return true;
        }
        return false;
    }
};