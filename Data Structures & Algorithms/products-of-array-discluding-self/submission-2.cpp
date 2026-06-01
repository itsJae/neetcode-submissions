class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans;
        int total = 1;
        int zero_cnt = 0;

        for (int num : nums)
        {
            if (num == 0) zero_cnt++;            
            else total *= num;
        }

        for (int i {0}; i < nums.size(); ++i)
        {
            if (zero_cnt > 1) ans.push_back(0);
            else if (zero_cnt == 1)
                ans.push_back(nums[i] == 0 ? total : 0);
            else
                ans.push_back(total / nums[i]);
        }

        return ans;
    }
};
