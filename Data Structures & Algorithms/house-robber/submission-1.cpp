class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) {
            return nums[n - 1];
        }

        vector<int> dp(n);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for (int i = 2; i < n; ++i) {
            int first = dp[i - 2] + nums[i];
            int second = dp[i - 1];

            if (first > second) {
                dp[i] = first;
            } else {
                dp[i] = second;
            }
        }

        return dp[n - 1];
    }
};
