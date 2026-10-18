class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int l = 0;
        int len = 1;

        for (int j = 0; j < n; ++j) {
            for (int i = 0; i < n; ++i) {
                if (s[i] == s[j] and (j - i < 2 or dp[i + 1][j - 1])) {
                    dp[i][j] = true;

                    if (len < j - i + 1) {
                        l = i;
                        len = j - i + 1;
                    }
                }
            }            
        }

        return s.substr(l, len);
    }
};
