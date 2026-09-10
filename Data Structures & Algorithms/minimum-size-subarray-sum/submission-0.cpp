class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0;
        int r = 0;
        int sum = 0;
        int ans = INT_MAX;

        while (r < nums.size()) {
            sum += nums[r];
            // cout << "sum: " << sum << ", L: " << l << ", R: " << r << endl;

            if (sum >= target) {
                while (sum >= target) {
                    ans = min(ans, r - l + 1);
                    sum -= nums[l];
                    ++l;
                }
            }

            ++r;
        }

        while (sum >= target) {
            ans = min(ans, r - l + 1);
            sum -= nums[l];
            ++l;
        }
        
        if (ans == INT_MAX) return 0;
        return ans;
    }
};