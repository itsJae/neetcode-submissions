class Solution {
public:
    int jump(vector<int>& nums) {
        int l = 0;
        int r = 0;
        int n = nums.size();
        int ans = 0;

        while (l < n - 1 && r < n - 1) {
            int maxReachable = 0;

            for (int i = l; r < n && i <= r; ++i) {
                if (i + nums[i] > maxReachable) {
                    maxReachable = i + nums[i];
                }
            }

            ++ans;
            l = r + 1; 
            r = maxReachable;
        }    

        return ans;
    }
};
