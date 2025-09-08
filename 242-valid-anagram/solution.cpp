// class Solution {
// public:
//     bool isAnagram(string s, string t) {
//         if(s.length()!=t.length()){
//             return false;
//         }
        
//         int charCount[26] = {0};

//         for(int i=0; i<s.size(); i++){
//             charCount[s[i] - 'a']++;
//         }
//         for(int i=0; i<t.size(); i++){
//             charCount[t[i] - 'a']--;
//             if(charCount[t[i] - 'a']<0){
//                 return false;
//             }
//         }
//         return true;
//     }
// };


// BRUTE FORCE APPROACH
class Solution {
public:
    bool isAnagram(string s, string t) {
        
        if(s.length()!=t.length()){
            return false;
        }
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());

        if(s==t){
            return true;
        }
        return false;
    }
};