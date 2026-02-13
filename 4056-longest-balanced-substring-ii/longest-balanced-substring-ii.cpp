class Solution {
public:

    // case 1: only one character (aaaa / bbb / ccc)
    int longestSingleChar(string s){
        int best = 1;
        int current = 1;

        for(int i=1;i<s.size();i++){
            if(s[i]==s[i-1]) current++;
            else current = 1;

            best = max(best,current);
        }
        return best;
    }

    // case 2: exactly two characters with equal frequency
    int longestTwoChars(string s, char a, char b){

        map<int,int> firstIndex;  // delta -> first position
        firstIndex[0] = -1;

        int delta = 0;
        int best = 0;

        for(int i=0;i<s.size();i++){

            // if third character appears → restart segment
            if(s[i]!=a && s[i]!=b){
                firstIndex.clear();
                firstIndex[0]=i;
                delta=0;
                continue;
            }

            if(s[i]==a) delta++;
            else delta--;

            if(firstIndex.count(delta))
                best = max(best, i - firstIndex[delta]);
            else
                firstIndex[delta]=i;
        }

        return best;
    }

    // case 3: all three characters equal
    int longestThreeChars(string s){

        vector<int> count(3,0);
        map<pair<int,int>,int> firstIndex;

        firstIndex[{0,0}] = -1;

        int best = 0;

        for(int i=0;i<s.size();i++){

            count[s[i]-'a']++;

            int d1 = count[1]-count[0]; // b-a
            int d2 = count[2]-count[0]; // c-a

            pair<int,int> state = {d1,d2};

            if(firstIndex.count(state))
                best = max(best, i - firstIndex[state]);
            else
                firstIndex[state]=i;
        }

        return best;
    }

    int longestBalanced(string s) {

        return max({
            longestSingleChar(s),
            longestTwoChars(s,'a','b'),
            longestTwoChars(s,'a','c'),
            longestTwoChars(s,'b','c'),
            longestThreeChars(s)
        });
    }
};
