class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);
        if (n == 3) return max(nums[0], max(nums[1], nums[2]));

        vector<int> dp1(n - 1);
        vector<int> dp2(n - 1);

        // dp1 (0 to n - 2)
        dp1[0] = nums[0];
        dp1[1] = max(nums[0], nums[1]);

        for (int i = 2; i < n - 1; ++i) {
            dp1[i] = max(dp1[i - 1], nums[i] + dp1[i - 2]);
        }

        // for (auto x : dp1) {
        //     cout << "dp1: " << x << endl;
        // }

        // dp2 (1 to n - 1)
        dp2[0] = nums[1];
        dp2[1] = max(nums[1], nums[2]);

        for (int i = 2; i < n - 1; ++i) {
            dp2[i] = max(dp2[i - 1], nums[i + 1] + dp2[i - 2]);
        }

        // for (auto x : dp2) {
        //     cout << "dp2: " << x << endl;
        // }

        return max(dp1[n - 2], dp2[n - 2]);
    }
};
