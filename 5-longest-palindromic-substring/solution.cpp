class Solution {
public:
    string longestPalindrome(string s) {
        int maxlength =0;
        int start =0;

        if(s.length()==0) return "";
        
        auto expandFromCenter = [&](int left, int right){
            while(left>=0 && right<s.size() && s[left]==s[right]){
                left--;
                right++;
            }
            return right-left-1;
        };

        for(int i=0; i<s.size(); i++){

            int len1 = expandFromCenter(i,i);
            int len2 = expandFromCenter(i,i+1);

            int len = max(len1 , len2);

            if(len>maxlength){
                maxlength = len;
                start = i -(len-1)/2;
            }
        }
        return s.substr(start,maxlength);
    }
};


// BRUTE FORCE APPROACH
// class Solution {
// public:
//     string longestPalindrome(string s) {
//         string rev = "";
//         string palindrome = "";
//         int maxi=0;

//         for(int i=0; i<s.size(); i++){
//             string subst = "";
//             for(int j=i; j<s.size(); j++){
//                 subst += s[j];
//                 // string subst = s.substr(i,j-i+1);
//                 rev = subst;
//                 reverse(rev.begin(),rev.end());
//                 if(subst == rev){
//                    if(subst.size()>maxi){
//                         maxi = subst.size();
//                         palindrome = subst;
//                    } 
//                 }
//             }
//         }
//         return palindrome;
//     }
// };