class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<int> lastOneIndex(n);

        for (int i = 0; i < n; i++) {
            int index = -1;

            for (int j = n - 1; j >= 0; j--) {
                if (grid[i][j] == 1) {
                    index = j;
                    break;
                }
            }
            lastOneIndex[i] = index;
        }

        int totalSwaps = 0;
        for (int i = 0; i < n; i++) {

            int rowToBring = -1;

            for (int j = i; j < n; j++) {
                if (lastOneIndex[j] <= i) {
                    rowToBring = j;
                    break;
                }
            }

            if (rowToBring == -1) {
                return -1;
            }

            while (rowToBring > i) {
                swap(lastOneIndex[rowToBring], lastOneIndex[rowToBring - 1]);
                rowToBring--;
                totalSwaps++;
            }
        }

        return totalSwaps;
    }
};