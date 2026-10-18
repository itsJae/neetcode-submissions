class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, -1);
        dp[0] = 0;

        for (int i = 1; i <= amount; ++i) {
            int min = INT_MAX;

            for (auto coin : coins) {
                if (i - coin < 0 || dp[i - coin] == -1) continue;
                if (min > dp[i - coin]) 
                    min = dp[i - coin];
            }

            if (min != INT_MAX)
                dp[i] = min + 1;
        }

        return dp[amount];
    }
};
