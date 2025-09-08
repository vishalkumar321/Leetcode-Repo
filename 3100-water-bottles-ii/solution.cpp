class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        
        int bottleDrunk = 0;
        int emptyBottles = 0;

        emptyBottles = numBottles;
        bottleDrunk = numBottles;
        numBottles =0;

        while(emptyBottles>=numExchange ){
            numBottles++;
            emptyBottles = emptyBottles - numExchange;
            numExchange++;
        }
       emptyBottles = emptyBottles + numBottles;
       

       if(emptyBottles>=numExchange ){
         bottleDrunk = bottleDrunk+numBottles;
         numBottles = 0;
            numBottles++;
            emptyBottles = emptyBottles - numExchange;
            numExchange++;
        }
        if(emptyBottles <numExchange){
          
            bottleDrunk = bottleDrunk+ numBottles;
        }
        return bottleDrunk;
    }
};