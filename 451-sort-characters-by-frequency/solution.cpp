class Solution {
public:
    string frequencySort(string s) {
        int characterCount[62]={0};
        string result ="";

        for(int i=0; i<s.size(); i++){
            if(s[i]>='a' && s[i]<='z'){
                characterCount[s[i] -'a']++ ;
            }
            else if(s[i]>='A' && s[i]<='Z'){
                characterCount[(s[i] -'A') +26]++ ;
            }
            else if(s[i]>='0' && s[i]<='9'){
                characterCount[(s[i] - '0') +52]++ ;
            }
        }

        string sortedCharacter[62];
        for(int i=0; i<26; i++){
            sortedCharacter[i]= string(characterCount[i], 'a'+i);
        }
        for(int i=26; i<52; i++){
            sortedCharacter[i]= string(characterCount[i], 'A'+(i-26));
        }
        for(int i=52; i<62; i++){
            sortedCharacter[i]= string(characterCount[i], '0' +(i-52));
        }

        for(int i=0; i<61; i++){
            for(int j=i+1; j<62; j++){
                if(sortedCharacter[j].size()>sortedCharacter[i].size()){
                    swap(sortedCharacter[i],sortedCharacter[j]);
                }
            }
        }

        for(int i=0; i<62; i++){
            result += sortedCharacter[i];
        }
        return result;
    }
};