class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int emptyBottles = numBottles;
        
        while (emptyBottles >= numExchange) {
            numBottles += emptyBottles / numExchange;
            emptyBottles =
                emptyBottles / numExchange + emptyBottles % numExchange;
        }
        
        return numBottles;
    }
};