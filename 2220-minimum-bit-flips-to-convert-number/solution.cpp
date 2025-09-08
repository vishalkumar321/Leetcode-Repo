class Solution {
public:
    int minBitFlips(int start, int goal) {
        int needToFlip = start ^ goal;
        int count = 0;

        while (needToFlip) {
            count += needToFlip & 1;
            needToFlip >>= 1;
        }
        return count;
    }
};