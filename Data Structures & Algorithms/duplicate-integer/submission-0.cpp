class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_map<int, int> hash_map;

        for (int num: nums)
        {
            if (hash_map.find(num) != hash_map.end())
            {
                return true;
            }

            hash_map[num]++;
        }
        return false;
    }
};