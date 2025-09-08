class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans ="";

        for(int i=0; i<strs[0].size(); i++){
            char currentChar = strs[0][i];
            for(int j=1; j<strs.size(); j++){
                if(currentChar!=strs[j][i]){
                    return ans;
                }
            }
            ans += currentChar;
        }
        return ans;
    }
};