class SegmentTree {
private:
    vector<int> lazyCoverCount;
    vector<int> coveredLength;
    vector<int> xCoords;
    int segments;

    void updateRange(int updateLeft, int updateRight, int delta, int nodeLeft,
                     int nodeRight, int nodeIndex) {
        int segLeftX = xCoords[nodeLeft];
        int segRightX = xCoords[nodeRight + 1];

        if (segRightX <= updateLeft || segLeftX >= updateRight)
            return;

        if (updateLeft <= segLeftX && segRightX <= updateRight) {
            lazyCoverCount[nodeIndex] += delta;
        } else {
            int mid = (nodeLeft + nodeRight) / 2;
            updateRange(updateLeft, updateRight, delta, nodeLeft, mid,
                        nodeIndex * 2 + 1);
            updateRange(updateLeft, updateRight, delta, mid + 1, nodeRight,
                        nodeIndex * 2 + 2);
        }

        if (lazyCoverCount[nodeIndex] > 0) {
            coveredLength[nodeIndex] = segRightX - segLeftX;
        } else {
            if (nodeLeft == nodeRight) {
                coveredLength[nodeIndex] = 0;
            } else {
                coveredLength[nodeIndex] = coveredLength[nodeIndex * 2 + 1] +
                                           coveredLength[nodeIndex * 2 + 2];
            }
        }
    }

public:
    SegmentTree(vector<int>& compressedX) : xCoords(compressedX) {
        segments = xCoords.size() - 1;
        lazyCoverCount.assign(4 * segments, 0);
        coveredLength.assign(4 * segments, 0);
    }

    void addInterval(int x1, int x2, int delta) {
        updateRange(x1, x2, delta, 0, segments - 1, 0);
    }

    int getCoveredXLength() { return coveredLength[0]; }
};

class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        vector<tuple<int, int, int, int>> events;
        set<int> uniqueX;

        for (auto& sq : squares) {
            int x = sq[0], y = sq[1], side = sq[2];
            int xLeft = x, xRight = x + side;
            events.push_back({y, +1, xLeft, xRight});
            events.push_back({y + side, -1, xLeft, xRight});
            uniqueX.insert(xLeft);
            uniqueX.insert(xRight);
        }

        sort(events.begin(), events.end());
        vector<int> compressedX(uniqueX.begin(), uniqueX.end());
        SegmentTree segTree(compressedX);

        vector<double> prefixAreaAfterEvent;
        vector<int> coveredWidthAfterEvent;

        double totalArea = 0.0;
        int prevY = get<0>(events[0]);

        for (auto& [currY, delta, xLeft, xRight] : events) {
            int coveredWidth = segTree.getCoveredXLength();
            totalArea += 1LL * coveredWidth * (currY - prevY);

            segTree.addInterval(xLeft, xRight, delta);

            prefixAreaAfterEvent.push_back(totalArea);
            coveredWidthAfterEvent.push_back(segTree.getCoveredXLength());

            prevY = currY;
        }

        double halfArea = totalArea / 2.0;

        int idx = lower_bound(prefixAreaAfterEvent.begin(),
                              prefixAreaAfterEvent.end(), halfArea) -
                  prefixAreaAfterEvent.begin();

        if (idx == 0)
            return get<0>(events[0]);

        double areaBeforeStrip = prefixAreaAfterEvent[idx - 1];
        int yStart = get<0>(events[idx - 1]);
        int stripWidth = coveredWidthAfterEvent[idx - 1];

        double remaining = halfArea - areaBeforeStrip;
        return yStart + remaining / stripWidth;
    }
};
