class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> s(nums.begin(), nums.end());
        
        int n = nums.size();
        int m = s.size();
        vector<int> tmp(s.begin(), s.end()); 

        for (int i = 0; i < m; ++i) 
            nums[i] = tmp[i];

        for (int i = 0; i < n - m; ++i) 
            nums.pop_back();

        return nums.size();
    }
};