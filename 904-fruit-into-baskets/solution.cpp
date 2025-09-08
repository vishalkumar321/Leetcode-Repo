class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> basket;
        int n = fruits.size();
        int maxfruit = 0;
        int i = 0;

        for (int j = 0; j < n; j++) {
            basket[fruits[j]]++;

            while (basket.size() > 2) {
                basket[fruits[i]]--;
                if (basket[fruits[i]] == 0) {
                    basket.erase(fruits[i]);
                }
                i++;
            }
            maxfruit = max(maxfruit, j - i + 1);
        }
        return maxfruit;
    }
};