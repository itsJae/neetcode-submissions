class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        if (nums.size() <= 2) 
            return {0, 1};

        std::unordered_map<int, int> hash_map;

        for (int i {0}; i < nums.size(); ++i)
        {
            int diff = target - nums[i];

            if (hash_map.find(diff) == hash_map.end())
                hash_map[nums[i]] = i;
            else
                return {hash_map[diff], i};
        }

        return {};
    }
};
