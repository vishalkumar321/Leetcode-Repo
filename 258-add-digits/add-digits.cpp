class Solution {
public:

    vector<int> getDigits(int num) {
        vector<int> d;
        while(num > 0) {
            d.push_back(num % 10);
            num /= 10;
        }
        return d;
    }

    void backtrack(vector<int>& digits, int index, int currSum, int &finalSum) {

        if(index == digits.size()) {
            finalSum = max(finalSum, currSum);
            return;
        }

        backtrack(digits, index + 1, currSum + digits[index], finalSum);
        backtrack(digits, index + 1, currSum, finalSum);
    }

    int addDigits(int num) {

        if(num < 10) return num;
        vector<int> digits = getDigits(num);

        int sum = 0;
        backtrack(digits, 0, 0, sum);

        return addDigits(sum);
    }
};
