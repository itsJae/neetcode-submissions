class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;

        for (int num : nums)
            s.insert(num);
        
        int max = 0;
        
        for (int i : s) {
            if (s.find(i - 1) == s.end()) {
                int target = i + 1;
                int cnt = 1;

                while (s.find(target) != s.end()) {
                    ++target;
                    ++cnt;
                }

                if (cnt > max) 
                    max = cnt;
            }
        }

        return max;
    }
};
