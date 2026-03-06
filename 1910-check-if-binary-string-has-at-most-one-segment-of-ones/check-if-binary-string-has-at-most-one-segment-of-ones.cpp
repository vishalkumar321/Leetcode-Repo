class Solution {
public:
    bool checkOnesSegment(string s) {
        int segment = 0;

        for(int i=1; i<s.size(); i++){
            if(s[i]==s[i-1])continue;
            else segment++;
        }
        return segment<=1;
    }
};