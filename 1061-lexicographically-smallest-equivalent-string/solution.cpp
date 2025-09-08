class Solution {
public:
        int parent[26];

        int find(int x){
            if(parent[x]!= x){
                parent[x] = find(parent[x]);
            }
            return parent[x];
        }

        void unionSet(int x, int y){
            int px = find(x);
            int py = find(y);

            if(px==py)return;

            if(px < py){
                parent[py] = px;
            }
            else{
                parent[px] = py;
            }
        }
        
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        
        for(int i=0; i<26; i++){
            parent[i] = i;
        }

        for(int i=0; i<s1.length(); i++){
            unionSet(s1[i] - 'a', s2[i] - 'a');
        }
        
        string result = "";
        for(char ch : baseStr){
            int smallest = find(ch - 'a');
            result += char(smallest + 'a');
        }
        return result;
    }
};