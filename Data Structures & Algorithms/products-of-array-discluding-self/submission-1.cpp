class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans;
        int total = 1;

        for (int num : nums)
            total *= num;


        for (int i {0}; i < nums.size(); ++i)
        {
            if (nums[i] == 0)
            {
                total = 1;

                for (int j {0}; j < nums.size(); ++j)
                {
                    if (i != j)
                        total *=  nums[j];
                }
                
                ans.push_back(total);
                total = 0;
            }
            else
                ans.push_back(total / nums[i]);
        }

        return ans;
    }
};
