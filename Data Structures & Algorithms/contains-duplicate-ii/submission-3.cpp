class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> m;
        
        // setup window
        for (int i = 0; i < n && i <= k; ++i) {
            ++m[nums[i]];
        }

        // for (auto& [k, v] : m) cout << k << ": " << v << endl;

        int i = 0;
        while (i < n) {
            int curr = nums[i];

            if (m[curr] >= 2) 
                return true;  

            if (k + 1 < n) {
                ++k;
                ++m[nums[k]];
            }

            ++i;
            --m[curr];
        }

        return false;
    }
};