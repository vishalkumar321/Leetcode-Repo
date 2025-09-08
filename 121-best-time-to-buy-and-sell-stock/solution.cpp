// OPTIMAL APPROACH
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int maxProfit=0;
        int minPrice = INT_MAX;
        int n = prices.size();
        for(int i=0; i<n; i++){
           minPrice = min(minPrice, prices[i]);
           int profit = prices[i]-minPrice;
           maxProfit = max(maxProfit,profit);
        }
        return maxProfit;
    }
};



// BRUTE FORCE APPROACH
// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int profit =0;
//         int maxProfit=0;
//         int n = prices.size();
//         for(int i=0; i<n-1; i++){
//             for(int j=i+1; j<n; j++){
//                 if(prices[i]<prices[j]){
//                     profit = prices[j]-prices[i];
//                     maxProfit = max(maxProfit, profit);
//                 }
//             }
//         }
//         return maxProfit;
//     }
// };