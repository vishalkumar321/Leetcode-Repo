class Solution {
public:
    double getAreaBelowLine(vector<vector<int>>& squares, double cutY) {
        double areaBelow = 0;

        for (auto& square : squares) {
            int bottomY = square[1];
            int side = square[2];

            if (bottomY < cutY) {
                double heightCovered = min(cutY - bottomY, (double)side);
                areaBelow += side * heightCovered;
            }
        }

        return areaBelow;
    }

    bool isHalfOrMore(vector<vector<int>>& squares, double cutY,
                      double halfArea) {
        return getAreaBelowLine(squares, cutY) >= halfArea;
    }

    double separateSquares(vector<vector<int>>& squares) {
        double totalArea = 0;
        double maxTopY = 0;

        for (auto& square : squares) {
            int bottomY = square[1];
            int side = square[2];

            totalArea += (double)side * side;
            maxTopY = max(maxTopY, (double)(bottomY + side));
        }

        double halfArea = totalArea / 2.0;

        double low = 0;
        double high = maxTopY;
        double eps = 1e-5;

        while (high - low > eps) {
            double mid = (low + high) / 2.0;

            if (isHalfOrMore(squares, mid, halfArea)) {
                high = mid;
            } else {
                low = mid;
            }
        }

        return high;
    }
};
