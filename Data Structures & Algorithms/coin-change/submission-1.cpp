class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;

        for (int i = 1; i <= amount; ++i) {
            int minCnt = INT_MAX;

            for (int j = 0; j < coins.size(); ++j) {
                int target = i - coins[j];
                
                if (target < 0) continue;
                else if (dp[target] == INT_MAX) continue;

                int cnt = 1 + dp[target];

                if (cnt < minCnt) {
                    minCnt = cnt;
                    dp[i] = cnt;
                }
            }

            cout << "dp[" << i << "] = " << minCnt << endl;
        }        

        if (dp[amount] == INT_MAX) return -1;
        return dp[amount];
    }
};
