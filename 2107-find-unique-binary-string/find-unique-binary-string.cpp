class Solution {
public:
    void binary(int n, vector<string>&ans, string s){
        if(s.size()==n){
            ans.push_back(s);
            return;
        }

        binary(n, ans, s+'0');
        binary(n, ans, s+'1');
    }
    
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        vector<string>ans;
        binary(n, ans, "");

        for(auto& it : ans){
            if(find(nums.begin(), nums.end(), it)==nums.end()){
                return it;
            }
        }
        return "";
    }
};