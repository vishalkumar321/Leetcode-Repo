class Solution {
public:
    int beautySum(string s) {
        int n = s.size();
        int sum = 0;
        
        for(int i=0; i<n; i++){
            int charCount[26] = {0};
            for(int j=i; j<n; j++){
                charCount[s[j]-'a']++;

                int maxFreq = INT_MIN;
                int minFreq = INT_MAX;
                for(int k=0; k<26; k++){
                    if(charCount[k]>0){
                        maxFreq = max(charCount[k],maxFreq);
                        minFreq = min(charCount[k],minFreq);
                    }
                }
                sum+=maxFreq- minFreq;
            }
        }
        return sum;
    }
};