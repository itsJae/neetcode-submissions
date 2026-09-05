class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) 
            return nums[n - 1];
        else if (n <= 2) 
            return max(nums[n - 1], nums[n - 2]);

        vector<int> dp1(n);
        dp1[0] = nums[0];
        dp1[1] = max(nums[0], nums[1]);

        // Exclude the last index.
        for (int i = 2; i < n - 1; ++i) {
            int first = dp1[i - 2] + nums[i];
            int second = dp1[i - 1];

            if (first > second) {
                dp1[i] = first;
            } else {
                dp1[i] = second;
            }
        }

        vector<int> dp2(n);
        dp2[1] = nums[1];
        dp2[2] = max(nums[1], nums[2]);

        // Exclude the first index.
        for (int i = 3; i < n; ++i) {
            int first = dp2[i - 2] + nums[i];
            int second = dp2[i - 1];

            if (first > second) {
                dp2[i] = first;
            } else {
                dp2[i] = second;
            }
        }

        int max1 = dp1[n - 2];
        int max2 = dp2[n - 1];
    
        return max(max1, max2);
    }
};
