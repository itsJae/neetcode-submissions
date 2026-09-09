class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> m;
        
        for (int i = 0; i < nums.size(); ++i) {
            ++m[nums[i]];
        }

        int maxVal = 0;
        int majority = 0;

        for (auto& [k, v] : m) {
            if (v > maxVal) {
                majority = k;
                maxVal = v;
            }
        }

        return majority;
    }
};