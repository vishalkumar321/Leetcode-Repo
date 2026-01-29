class Solution {
public:
    vector<long long> dijkstra(
        int startChar,
        const vector<vector<pair<int, int>>>& adjacencyList) {

        priority_queue<pair<long long, int>,
                       vector<pair<long long, int>>,
                       greater<pair<long long, int>>> pq;

        vector<long long> minCosts(26, -1);

        pq.push({0, startChar});
        minCosts[startChar] = 0;

        while (!pq.empty()) {
            auto [currentCost, currentChar] = pq.top();
            pq.pop();

            if (currentCost > minCosts[currentChar])
                continue;

            for (auto& edge : adjacencyList[currentChar]) {
                int nextChar = edge.first;
                int edgeCost = edge.second;

                long long newCost = currentCost + edgeCost;

                if (minCosts[nextChar] == -1 || newCost < minCosts[nextChar]) {
                    minCosts[nextChar] = newCost;
                    pq.push({newCost, nextChar});
                }
            }
        }

        return minCosts;
    }

    long long minimumCost(string source, string target,
                          vector<char>& original,
                          vector<char>& changed,
                          vector<int>& cost) {

        vector<vector<pair<int, int>>> adjacencyList(26);

        for (int i = 0; i < original.size(); i++) {
            adjacencyList[original[i] - 'a'].push_back(
                {changed[i] - 'a', cost[i]}
            );
        }

        vector<vector<long long>> minConversionCosts(26, vector<long long>(26));

        for (int i = 0; i < 26; i++) {
            minConversionCosts[i] = dijkstra(i, adjacencyList);
        }

        long long totalCost = 0;

        for (int i = 0; i < source.length(); i++) {
            if (source[i] != target[i]) {
                long long charCost =
                    minConversionCosts[source[i] - 'a'][target[i] - 'a'];

                if (charCost == -1)
                    return -1;

                totalCost += charCost;
            }
        }

        return totalCost;
    }
};
