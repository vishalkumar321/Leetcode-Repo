class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> d;
        queue<int> r;
        int n = senate.size();

        for (int i = 0; i < n; i++) {
            if (senate[i] == 'D') {
                d.push(i);
            } else {
                r.push(i);
            }
        }

        while (!r.empty() && !d.empty()) {
            int rIdx = r.front();
            r.pop();
            int dIdx = d.front();
            d.pop();

            if (rIdx < dIdx) {
                r.push(rIdx + n);
            } 
            else {
                d.push(dIdx + n);
            }
        }

        return r.empty() ? "Dire" : "Radiant";
    }
};