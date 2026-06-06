class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> s1_cnt(26);
        vector<int> s2_cnt(26);

        for (char c1 : s1) {
            s1_cnt[c1 - 'a']++;
        }

        if (s1_cnt == s2_cnt) return true;

        for (int right = 0; right < s2.length(); ++right) {
            s2_cnt[s2[right] - 'a']++;
            
            if (right >= s1.length()) {
                int left = right - s1.length();
                s2_cnt[s2[left] - 'a']--;
            }

            if (s1_cnt == s2_cnt) return true;
        }

        return false;
    }
};
