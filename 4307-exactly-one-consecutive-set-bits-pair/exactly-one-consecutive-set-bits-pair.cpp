class Solution {
public:
    bool consecutiveSetBits(int n) {
        string binary;

        while (n > 0) {
            binary += char('0' + (n % 2));
            n /= 2;
        }
        cout << binary << endl;
        cout << binary.size() << endl;
        int count = 0;
        for (int i = 1; i < binary.size(); i++) {
            if (binary[i] == '1' && binary[i - 1] == '1') {
                count++;
            }
        }
        return count == 1;
    }
};