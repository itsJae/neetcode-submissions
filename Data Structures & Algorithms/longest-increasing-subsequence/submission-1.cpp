class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n);
        dp[0] = 1;

        for (int i = 1; i < n; ++i) {
            int maxLen = 0;

            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    maxLen = max(maxLen, dp[j]);
                }
            }

            // cout << "i: " << i << ", maxLen: " << maxLen << endl;
            dp[i] = maxLen + 1;
        }

        // for (auto x : dp)
        //     cout << x << endl;
    
        return *max_element(dp.begin(), dp.end());
    }
};
