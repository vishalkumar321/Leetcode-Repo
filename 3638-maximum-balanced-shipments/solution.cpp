class Solution {
public:
    int maxBalancedShipments(vector<int>& weight) {
        int shipment = 0;
        int n = weight.size();
        int maxweight = weight[0];
        int j = 0;

        for (int i = 1; i < n; i++) {
            maxweight = max(weight[i], maxweight);

            if (maxweight > weight[i]) {
                shipment++;

                j = i + 1;
                if (j < n) {
                    maxweight = weight[j];
                }
                i = j;
            }
        }
        return shipment;
    }
};