class Solution {
    const int mod = 12345;

public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {

        vector<int> a;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                a.push_back(grid[i][j]);
            }
        }
        vector<int> pp(a.size(), 1);
        for (int i = 1; i < a.size(); i++)
            pp[i] = (1LL * pp[i - 1] * a[i - 1]) % mod;

        vector<int> sp(a.size(), 1);
        for (int i = a.size() - 2; i >= 0; i--)
            sp[i] = (1LL * sp[i + 1] * a[i + 1]) % mod;
        int idx = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                grid[i][j] = (1LL * pp[idx] * sp[idx]) % mod;
                idx++;
            }
        }
        return grid;
    }
};