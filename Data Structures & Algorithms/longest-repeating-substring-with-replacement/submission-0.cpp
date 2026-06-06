class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0;
        int max_len = 0;
        int max_cnt = 0;
        vector<int> counts(26);

        for (int right = 0; right < s.length(); ++right) {
            counts[s[right] - 'A']++;
            max_cnt = max(max_cnt, counts[s[right] - 'A']);

            if ((right - left + 1) - max_cnt > k) {

                // shrink window
                counts[s[left] - 'A']--;
                left++;
            }

            max_len = max(max_len, right - left + 1);
        }

        return max_len;
    }
};
