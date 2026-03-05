class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        int count0 = 0;
        int count1 = 0;

        for(int i=0; i<n; i++){
            if(i%2==0){
                if(s[i]=='0'){
                    count1++;
                }
                else{
                    count0++;
                }
            }
            else{
                if(s[i]=='1'){
                    count1++;
                }
                else{
                    count0++;
                }
            }
        }

        return min(count0, count1);
    }
};