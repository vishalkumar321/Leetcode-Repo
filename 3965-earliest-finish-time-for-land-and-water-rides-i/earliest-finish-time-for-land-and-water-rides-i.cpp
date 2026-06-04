class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {
        int n = landStartTime.size();
        int m = waterStartTime.size();

        // sort(landStartTime.begin(), landStartTime.end());
        // sort(waterStartTime.begin(), waterStartTime.end());

        int result = INT_MAX;
        for (int i = 0; i < n; i++) {
            int current = INT_MAX;
            for (int j = 0; j < m; j++) {
                current = landStartTime[i] + landDuration[i];
                if (waterStartTime[j] <= current) {
                    current += waterDuration[j];
                } else {
                    current = waterStartTime[j] + waterDuration[j];
                }
                result = min(result, current);
            }
        }

        for (int i = 0; i < m; i++) {
            int current = INT_MAX;
            for (int j = 0; j < n; j++) {
                current = waterStartTime[i] + waterDuration[i];
                if (landStartTime[j] <= current) {
                    current += landDuration[j];
                } else {
                    current = landStartTime[j] + landDuration[j];
                }
                result = min(result, current);
            }
        }
        return result;
    }
};