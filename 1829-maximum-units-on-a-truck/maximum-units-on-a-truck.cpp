class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {

        sort(boxTypes.begin(), boxTypes.end(),
             [](vector<int>& a, vector<int>& b) { return a[1] > b[1]; });

        int TotalUnits = 0;
        for (auto& box : boxTypes) {
            int boxesToTake = min(box[0], truckSize);
            TotalUnits += boxesToTake * box[1];
            truckSize -= boxesToTake;
            if (truckSize == 0)
                break;
        }
        return TotalUnits;
    }
};