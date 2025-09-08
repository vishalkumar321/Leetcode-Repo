class Solution {
public:

    bool ispalin(string s){
        string s2 = s;
        reverse(s2.begin(),s2.end());
        return s == s2;
    }

    void getAllPart(string input, vector<string>& partitions,vector<vector<string>>& ans){

        if(input.size()==0){
            ans.push_back(partitions);
            return;
        }

        for(int i = 0; i<input.size(); i++){

            string part = input.substr(0,i+1);
            if(ispalin(part)){
                partitions.push_back(part);
                getAllPart(input.substr(i+1), partitions, ans);
                partitions.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<string>partitions;
        vector<vector<string>>ans;

        getAllPart(s, partitions, ans);
        return ans;
    }
};