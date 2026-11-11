class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        
        long long ans = LLONG_MAX;

        long long requiredBoth = min(need1, need2);
        long long costUsingOnlyBoth = 1LL*max(need1,need2)*costBoth;
        long long costWithBoth = requiredBoth* costBoth
                                + (need1-requiredBoth)* cost1
                                + (need2-requiredBoth)* cost2;

        long long costWithoutBoth = 1LL*need1*cost1 + 1LL*need2*cost2; 

        ans = min({costWithBoth, costWithoutBoth,costUsingOnlyBoth});
        return ans;
    }
};