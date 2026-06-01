class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq_map;
        vector<int> ans;

        for (int num : nums)
            freq_map[num]++;

        vector<vector<int>> freq_vec(nums.size() + 1);

        for (const auto& [key, val] : freq_map)
            freq_vec[val].push_back(key);
    
        for (int i = freq_vec.size() - 1; i >= 0; --i)
        {
            for (int num : freq_vec[i])
            {
                if (k == 0) break;
                
                ans.push_back(num);
                --k;
            }
        }

        return ans;
    }
};
