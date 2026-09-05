class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n);

        dp[n - 1] = cost[n - 1];
        dp[n - 2] = cost[n - 2];

        // cout << dp[2] << ", " << dp[1] << endl;

        for (int i = n - 3; i >= 0; --i) {
            int first = dp[i + 1];
            int second = dp[i + 2];
            
            if (first > second) {
                dp[i] = cost[i] + second;    
            } else {
                dp[i] = cost[i] + first;    
            }
        }

        return min(dp[0], dp[1]);
    }
};
