class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {

        priority_queue<int> p;

        for (int i = 0; i < stones.size(); i++) {
            p.push(stones[i]);
        }

        while (p.size() > 1) {
            int stone1 = p.top();
            p.pop();
            int stone2 = p.top();
            p.pop();

            if (stone1 != stone2) {
                p.push(stone1 - stone2);
            }
        }
        return p.empty() ? 0 : p.top();
    }
};