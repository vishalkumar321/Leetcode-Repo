class Solution {
public:
    int vowelConsonantScore(string s) {

        int v = 0;
        int c = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' ||
                s[i] == 'u') {
                v++;
            } else if((s[i]>='0' && s[i]<='9') || s[i]==' '){
                continue;
            }
            else{
                c++;
            }
        }
        
        if (c > 0)
            return (v / c);
        return 0;
    }
};