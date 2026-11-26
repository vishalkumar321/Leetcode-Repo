class Solution {
public:
    bool canAliceWin(int n) {

        int stone = 10;
        bool flag = false;
        
        while (n >= stone) {
            n -= stone;
            stone--;
            flag = !flag;
        }
        return flag;
    }
};