class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> s;

        for (int num : nums) {
            if (s.insert(num).second == false)
                return num;
        }

        return -1;
    }
};
