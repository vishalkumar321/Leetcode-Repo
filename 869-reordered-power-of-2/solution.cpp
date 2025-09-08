class Solution {
public:
    vector<int> Binary(int num) {
        vector<int> count(10, 0);
        while (num > 0) {
            count[num % 10]++;
            num /= 10;
        }
        return count;
    }

    bool reorderedPowerOf2(int n) {
        vector<int> target = Binary(n);

        for (int i = 0; i < 31; i++) {
            int power = 1 << i;
            if (Binary(power) == target)
                return true;
        }
        return false;
    }
};