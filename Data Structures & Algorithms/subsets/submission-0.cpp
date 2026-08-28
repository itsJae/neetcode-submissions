class Solution {
public:
    vector<int> subset;
    
    void search(int k, int n, vector<int>& nums, vector<vector<int>>& ans) {
        if (n == k) {
            ans.push_back(subset);            
            return;
        }

        search(k + 1, n, nums, ans);

        subset.push_back(nums[k]);   
        search(k + 1, n, nums, ans);
        subset.pop_back();
    } 

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();

        search(0, n, nums, ans);

        return ans;
    }
};
