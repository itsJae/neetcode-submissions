class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;

        for (int num : nums)
            s.insert(num);
        
        vector<int> ans{0};

        for (int i : s) {
            if (s.find(i - 1) == s.end()) {
                int target = i + 1;
                int cnt = 1;

                while (s.find(target) != s.end()) {
                    ++target;
                    ++cnt;
                }

                ans.push_back(cnt);
            }
        }

        return *max_element(ans.begin(), ans.end());
    }
};
