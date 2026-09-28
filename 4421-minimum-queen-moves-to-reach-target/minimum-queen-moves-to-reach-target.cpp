class Solution {
public:
    int minQueenMoves(vector<int>& source, vector<int>& target) {
        int diff1 = abs(source[0] - target[0]);
        int diff2 = abs(source[1] - target[1]);

        if (diff1 == diff2 && diff1 == 0) {
            return 0;
        } else if (diff1 == diff2 || diff1 == 0 || diff2 == 0) {
            return 1;
        }
        return 2;
    }
};