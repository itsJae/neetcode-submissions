class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        double n = nums.size();
        int cap = floor(n / 3);
    
        unordered_map<int, int> m;
        for (auto x : nums)
            ++m[x];

        vector<int> ans;
        for (auto& [k, v] : m) {
            if (v > cap)
                ans.push_back(k);
        }

        return ans;
    }
};