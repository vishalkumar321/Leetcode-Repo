class Solution {
public:
    int countBinarySubstrings(string s) {
        int zeroes = 0, ones = 0;
        int n = s.size();
        int ans = 0;

        int i =0;
        while( i < n){
            if(s[i] == '0') {
                zeroes = 0;

                while(s[i] == '0'){
                    zeroes++;
                    i++;
                }
                ans+= min(ones,zeroes);
            }

            if(s[i] == '1') {
                ones = 0;

                while(s[i] == '1'){
                    ones++;
                    i++;
                }
                ans+= min(ones,zeroes);
            }
            
        }
        return ans;
    }
};